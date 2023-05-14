#include "ClientManager.h"

Client::Client(const std::string &name,
               const std::string &surname,
               const std::string &email)
: name(name)
, surname(surname)
, email(email)
{}

Client::Client(const std::string &name,
               const std::string &surname,
               const std::string &email,
               std::string phone)
: Client(name, surname, email)
{
    phoneNumbers.push_back(phone);
}

Client::Client(const std::string &name,
               const std::string &surname,
               const std::string &email,
               std::vector<std::string> &&phones)
: Client(name, surname, email)
{
    phoneNumbers = std::move(phones);
}


ClientManager::ClientManager(const std::string &dbHost,
                             const std::string &dbPort,
                             const std::string &dbName,
                             const std::string &dbUser,
                             const std::string &dbPassword)
: db_password(dbPassword)
, connect(nullptr)
, connection_error("")
{
    connect = std::make_unique<pqxx::connection>
    (
        "host="  + dbHost +
        " port=" + dbPort +
        " dbname=" + dbName +
        " user=" + dbUser +
        " password=" + dbPassword
    );
}

int ClientManager::getUserIdByEmail(std::string email) const
{
    uwork w = std::make_unique<pqxx::work>(*connect);

    std::string checkQ = "SELECT u.id from mails m "
                         "left join users u on u.id = m.user_id "
                         "where m.email = " + w->quote(email) + ";";

    pqxx::result checkR = w->exec(checkQ);

    int res = -1;
    if (! checkR.empty() )
        res = checkR[0][0].as<int>();

    return res;
}

int ClientManager::addNewClient(const Client &client) const
{
    int userExists = 0;
    if (client.name.empty())
        throw std::runtime_error("Error: cannot add new user without name");

    if (client.surname.empty())
        throw std::runtime_error("Error: cannot add new user without surname");

    if (client.email.empty())
        throw std::runtime_error("Error: cannot add new user without email");

    userExists = getUserIdByEmail(client.email);
    uwork w = std::make_unique<pqxx::work>(*connect);

    std::string q1 = "INSERT INTO users (name, surname) VALUES ("
                     + w->quote(client.name) + ", "
                     + w->quote(client.surname) + ") RETURNING id;";

    pqxx::result query_result;

    // If user doesn't exists:
    if ( userExists == -1)
    {
        query_result = w->exec(q1);
        if (!query_result.empty())
            userExists = query_result[0][0].as<int>();

        std::string q2 = "INSERT INTO mails (user_id, email) VALUES("
                            + w->quote(userExists) + ", "
                            + w->quote(client.email) + ");";
        w->exec(q2);
    }

    // If user phones in class exists
    if (!client.phoneNumbers.empty())
    {
        std::string insertPhone;
        for (const auto &phone : client.phoneNumbers)
        {
            insertPhone = "INSERT INTO phones (user_id, phone_number) VALUES ("
                            + w->quote(userExists) + ", "
                            + w->quote(phone) + ") "
                            + "ON CONFLICT (phone_number) DO NOTHING;";
            w->exec(insertPhone);
        }
    }

    w->commit();
    return userExists;
}

bool ClientManager::tableExists(const std::string &table) const{
    uwork w = std::make_unique<pqxx::work>(*connect);
    std::string query = "SELECT EXISTS ("
                        "SELECT FROM information_schema.tables "
                        "WHERE table_name = " + w->quote(table) + ");";

    pqxx::result result = w->exec(query);
    w->commit();
    return result[0][0].as<bool>();
}

bool ClientManager::init()
{
    std::vector<std::string> queries;

    if (!tableExists("users"))
        queries.emplace_back("create table if not exists users("
                            "id serial primary key,"
                            "name VARCHAR(255) not null,"
                            "surname VARCHAR(255) not null);");

    if (!tableExists("mails"))
        queries.emplace_back("create table if not exists mails("
                            "id serial primary key,"
                            "user_id integer not null,"
                            "email varchar(255) not null unique,"
                            "foreign key (user_id) references users (id) on delete cascade);");

    if (!tableExists("phones"))
        queries.emplace_back("create table if not exists phones("
                            "id serial primary key,"
                            "user_id integer not null,"
                            "phone_number varchar(20) unique,"
                            "foreign key (user_id) references users (id) on delete cascade);");

    if (queries.empty())
        return true;

    uwork w = std::make_unique<pqxx::work>(*connect);
    for (const auto &i : queries)
        w->exec(i);

    w->commit();
    return true;
}

std::vector<std::string> ClientManager::getUserPhones(const int uid)
{
    std::vector<std::string> phones;
    if (uid <= 0)
        return phones;

    uwork w = std::make_unique<pqxx::work>(*connect);
    std::string selectPhones = "SELECT phone_number FROM phones p "
                               "WHERE p.user_id  = " + w->quote(uid) +
                               " AND p.phone_number IS NOT NULL;";

    pqxx::result result = w->exec(selectPhones);
    for (const auto &row : result)
        phones.push_back(row["phone_number"].as<std::string>());

    w->commit();    
    return phones;
}

bool ClientManager::addPhoneNumber(const std::string &email, const std::string &phoneNumber)
{
    int uid = getUserIdByEmail(email);
    if (uid == -1)
        return false;

    uwork w = std::make_unique<pqxx::work>(*connect);
    std::string query = "INSERT INTO phones(user_id, phone_number) VALUES("
                        + w->quote(uid) + ", "
                        + w->quote(phoneNumber) + ")"
                        + "ON CONFLICT (phone_number) DO NOTHING;";

    w->exec(query);
    w->commit();
    return true;
}

bool ClientManager::removePhoneNumber(const std::string &phoneNumber)
{
    if (phoneNumber.empty())
        throw std::runtime_error("Can't delete empty phone");


    uwork w = std::make_unique<pqxx::work>(*connect);
    std::string query = "DELETE FROM phones "
                        " WHERE phone_number = "
                        + w->quote(phoneNumber) + ";";

    w->exec(query);
    w->commit();
    return true;
}

bool ClientManager::removeUserByEmail(const std::string &email)
{
    if (email.empty())
        throw std::runtime_error("Can't delete empty by email");

    int uid = getUserIdByEmail(email);
    if (uid == -1)
        return false;

    uwork w = std::make_unique<pqxx::work>(*connect);
    w->exec("DELETE FROM users WHERE id = " + w->quote(uid) + ";");
    w->exec("DELETE FROM mails WHERE user_id = " + w->quote(uid) + ";");
    w->exec("DELETE FROM phones WHERE user_id = " + w->quote(uid) + ";");

    w->commit();
    return true;
}

bool ClientManager::updateInfo(const Client &client) const
{
    if (client.name.empty() || client.surname.empty() || client.email.empty())
        throw std::runtime_error("Error, not all data filled");

    int uid = getUserIdByEmail(client.email);
    if (uid == -1)
        return false;

    uwork w = std::make_unique<pqxx::work>(*connect);

    std::string update_users = "UPDATE users SET "
                               "name = " + w->quote(client.name) + ", "
                               "surname = " + w->quote(client.surname)
                               + " WHERE id = " + w->quote(uid) + ";";

    std::string update_mails = "UPDATE mails SET "
                               "email = " + w->quote(client.email)
                               + " WHERE user_id = " + w->quote(uid) + ";";


    w->exec(update_users);
    w->exec(update_mails);

    if (!client.phone.empty())
    {
        std::string update_phones = "UPDATE phones SET "
                                    "phone = " + w->quote(client.phone)
                                    + " WHERE user_id = " + w->quote(uid) + ";";
        w->exec(update_phones);
    }

    w->commit();
    return true;
}

int ClientManager::searchUser(const Client &client) const
{
    int res = -1;
    uwork w = std::make_unique<pqxx::work>(*connect);
    std::string query = "SELECT * "
                        "FROM users u "
                        "LEFT JOIN mails m ON m.user_id = u.id "
                        "LEFT JOIN phones p ON p.user_id = u.id "
                        "WHERE u.name = " + w->quote(client.name) +
                        " OR u.surname = " + w->quote(client.surname) +
                        " OR m.email = " + w->quote(client.email) +
                        " OR p.phone_number = " + w->quote(client.phone) + ";";

    pqxx::result result = w->exec(query);
    if (!result.empty())
        res = result[0][0].as<int>();
    
    return res;
}

bool ClientManager::is_connected() const {
    return connection_error.empty();
}
