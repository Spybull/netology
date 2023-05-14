#include <iostream>
#include <fstream>
#include "parser.h"
#include "ClientManager.h"


#define HOMEWORK_DATABASE "homework05"
#define USER_CSV_FILE "users.csv"

int main()
{
    if (isFileEmpty(USER_CSV_FILE)) {
        std::cerr << "File " << USER_CSV_FILE << " empty or can't open\n";
        return -1;
    }

    std::ifstream in(USER_CSV_FILE);
    std::string lines;
    std::vector<Client> clients;
    std::vector<std::string> phone_numbers;
    
    while (std::getline(in, lines))
    {
        std::string sv_lines(lines);
        std::vector<std::string> fields = parseByDelim(sv_lines, ';');

        if (fields.size() < 3) {
            std::cout << "Warning for client creation need minimum 3 fields!\n";
            continue;
        }

        if (fields.size() >= 4)
            phone_numbers = parseByDelim(fields[3], ',');

        clients.emplace_back(fields[0], fields[1], fields[2], std::move(phone_numbers));
    }

    try
    {
        ClientManager clientManager("localhost", "5432", HOMEWORK_DATABASE, "postgres", "postgres");

        if (! clientManager.is_connected())
            std::cerr << "Ошибка подключения: "
                    << clientManager.get_connection_error()
                    << std::endl;

        if (! clientManager.init() ) 
            std::cerr << "Ошибка инициализации: "
                    << clientManager.get_connection_error()
                    << std::endl;

        // Добавляем клиентов в БД
        for (const auto &client : clients) {
            if ( clientManager.addNewClient(client) <= 0 )
                std::cerr << "Error insertion"<< std::endl;
        }

        // Метод, позволяющий добавить телефон для существующего клиента
        std::string phoneNumber = "45-78-44";
        if ( !clientManager.addPhoneNumber(clients[0].email, phoneNumber) )
            std::cerr << "Phone number "
                      << phoneNumber
                      << " for client "
                      << clients[0].email
                      << std::endl;


        // Метод, позволяющий изменить данные о клиенте
        clients[2].surname = "Иванова";
        if ( !clientManager.updateInfo(clients[2]) )
            std::cerr << "Error in update for "
                      << clients[2].name
                      << " " << clients[2].surname
                      << std::endl;

        // Метод, позволяющий удалить телефон для существующего клиента
        if ( !clientManager.removePhoneNumber("+7-921-382-88-28") )
            std::cerr << "Error in removePhoneNumber for " << std::endl;

        // Метод, позволяющий удалить существующего клиента
        if ( !clientManager.removeUserByEmail("p.petrov@gmail.com") ) {
            std::cerr << "Error in removeUserByEmail for " << std::endl;
        }

        // Метод, позволяющий найти клиента по его данным (имени, фамилии, email-у или телефону)

        if (int id = 0; (id = clientManager.searchUser(clients[2])) > 0)
            std::cout << "Клиент найден, ID: " << id << std::endl;
        else
            std::cerr << "Клиент " << clients[2].email
                      << " не найден!" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}