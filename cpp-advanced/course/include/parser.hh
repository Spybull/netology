#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <exception>
#include <map>
#include <string_view>

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
            std::uintmax_t file_size;
            std::map< std::string, map_ss > section;

            bool is_number(const std::string_view& s);
            bool is_boolean(const std::string_view &s) const;
            bool isKv(const std::string_view &kv) const;
            std::string_view trim(const std::string_view &str);
            bool isSection(const std::string_view &section) const;
            bool isValidSection(const std::string_view &section) const;
            std::string_view getSectionName(const std::string_view &section);

        public:
            Parser() = default;
            explicit Parser(const std::string &filePath);

            /* Метод принимающий в качестве аргумента строку,
            которая является ключом key в файле *.ini
            key=val и возвращает T в зависимости от запрошенного типа */
            template<typename T> T get_value(const std::string_view &str_val)
            {
                size_t pp = str_val.find_first_of('.');
                if ( pp == std::string::npos )
                    throw std::runtime_error("Unknown section name");

                std::string_view section_view = str_val.substr(0, pp);
                std::string current_section(section_view);
                
                std::transform(current_section.begin(),
                    current_section.end(),
                    current_section.begin(),
                    ::tolower);

                auto it = section.find(current_section);
                if ( it == section.end() )
                    throw std::runtime_error("Section not found");

                std::string_view key_view = str_val.substr(pp + 1);
                std::string finding_key(key_view);
                auto it_kv = it->second.find(finding_key);

                if ( it_kv == it->second.end() )
                    throw ini_exceptions(finding_key, it->second);

                if (is_number(it_kv->second))
                {
                    if constexpr(std::is_integral<T>::value)
                        return std::stoi(it_kv->second);
                    if constexpr(std::is_floating_point<T>::value)
                        return std::stod(it_kv->second);
                    
                    throw std::runtime_error("Wrong types!"); 
                }

                if (is_boolean(it_kv->second))
                {
                    if constexpr(std::is_integral<T>::value &&
                                 std::is_same<T, bool>::value) {
                        if (it_kv->second == "true")
                            return true;
                        else
                            return false;
                    }
                    throw std::runtime_error("Wrong types!"); 
                }

                if constexpr(std::is_same<T, std::string>::value)
                    return it_kv->second;
                else
                    throw std::runtime_error("Wrong types!");    
            }

            Parser &operator=(const Parser &) = delete;
            Parser &operator=(Parser &&) = delete;
            
            Parser(const Parser &) = delete;
            Parser(Parser &&) = delete;
            ~Parser() = default;
    };
} // ini_parser namespace