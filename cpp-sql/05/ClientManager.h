#pragma once
#include <iostream>
#include <string>
#include <memory>

#include <pqxx/pqxx>

typedef std::unique_ptr<pqxx::work> uwork;

struct Client {
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;
    std::vector<std::string> phoneNumbers;

    Client(const std::string &name,
           const std::string &surname,
           const std::string &email);

    Client(const std::string &name,
           const std::string &surname,
           const std::string &email,
           std::string phone);

    Client(const std::string &name,
           const std::string &surname,
           const std::string &email,
           std::vector<std::string> &&phones);
};

class ClientManager {
    private:
        std::string db_password;
        std::unique_ptr<pqxx::connection> connect;
        std::string connection_error;

        // Метод получения ID пользователя по email
        int getUserIdByEmail(std::string email) const;

        // Метод получения информации о структуре определенной таблицы
        std::map<std::string, std::string> getTableSchema(std::string_view table);

        // Метод получения телефона(ов) пользователя по ID
        std::vector<std::string> getUserPhones(const int uid);

        // Метод проверяющий существование телефона
        bool checkPhoneExists(const std::string &phone);

        bool tableExists(const std::string &table) const;
    public:

        ClientManager() = delete;
        ClientManager(const std::string &dbHost,
                      const std::string &dbPort,
                      const std::string &dbName,
                      const std::string &dbUser,
                      const std::string &dbPassword);
        ~ClientManager() = default;

        // Метод, создающий структуру БД (таблицы)
        bool init();

        // Метод, позволяющий добавить нового клиента
        int addNewClient(const Client &client) const;

        // Метод, позволяющий добавить телефон для существующего клиента
        bool addPhoneNumber(const std::string &email, const std::string &phoneNumber);
        
        // Метод, позволяющий удалить телефон для существующего клиента
        bool removePhoneNumber(const std::string &phoneNumber);

        // Метод, позволяющий удалить существующего клиента
        bool removeUserByEmail(const std::string &email);

        // Метод, позволяющий изменить данные о клиенте
        bool updateInfo(const Client &client) const;

        // Метод, позволяющий найти клиента по его данным (имени, фамилии, email-у или телефону)
        int searchUser(const Client &client) const;

        bool is_connected() const;
};
