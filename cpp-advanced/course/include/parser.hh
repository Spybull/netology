#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <exception>
#include <map>

typedef std::map<std::string, std::string> map_ss;

namespace ini_parser {

    class ini_exceptions : public std::exception
    {
        private:
            int posInLine;
            std::string message;

        public:
            ini_exceptions(int lPos, std::string msg);
            ini_exceptions(std::string keyVal, map_ss kv);
            virtual const char *what() const noexcept override;
    };

    class Parser {
        private:
            std::string filePath;
            size_t line_count;
            size_t section_count;
            size_t kv_count;
            std::map< std::string, map_ss > section;

            bool is_number(const std::string& s);
            bool isKv(const std::string &kv) const;
            std::string trim(const std::string &str);
            bool isSection(std::string &section);
            bool isValidSection(const std::string &section) const;
            std::string getSectionName(const std::string &section);

        public:
            Parser() = default;
            explicit Parser(const std::string &filePath);

            /* Метод принимающий в качестве аргумента строку,
            которая является ключом key в файле *.ini
            key=val и возвращает T в зависимости от запрошенного типа */
            template<typename T> T get_value(std::string str_val)
            {
                size_t pp = str_val.find_first_of('.');
                if ( pp == std::string::npos )
                    throw std::runtime_error("Unknown section name");

                std::string current_section = str_val.substr(0, pp);
                std::transform(current_section.begin(),
                    current_section.end(),
                    current_section.begin(),
                    ::tolower);

                auto it = section.find(current_section);
                if ( it == section.end() )
                    throw std::runtime_error("Section not found");

                std::string finding_key = str_val.substr(pp + 1);
                auto it_kv = it->second.find(finding_key);

                if ( it_kv == it->second.end() )
                    throw ini_exceptions(finding_key, it->second);

                bool n = is_number(it_kv->second);
                if (n && typeid(std::string) == typeid(T) )
                    throw std::runtime_error("Wrong requested type of string!");
                
                if ( !n && typeid(std::string) != typeid(T) )
                    throw std::runtime_error("Wrong types!");

                if constexpr(std::is_integral<T>::value)
                    return std::atoi(it_kv->second.c_str());
                else if constexpr(std::is_floating_point<T>::value)
                    return std::atof(it_kv->second.c_str());
                else if constexpr(std::is_base_of<char, T>::value)
                    return it_kv->second;
                else
                    return it_kv->second;
            }

            Parser &operator=(const Parser &) = delete;
            Parser &operator=(Parser &&) = delete;
            
            Parser(const Parser &) = delete;
            Parser(Parser &&) = delete;
            ~Parser() = default;
    };
} // ini_parser namespace