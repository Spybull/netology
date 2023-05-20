#include "parser.hh"

namespace ini_parser
{
    ini_exceptions::ini_exceptions(std::string keyVal, map_ss kv)
    {
        message = "Key '" + keyVal + "' not found. Avaliable keys:\n";
        for (const auto &i : kv) message += i.first + "\n";
    }
    const char *ini_exceptions::what() const noexcept { return message.c_str(); }
    ini_exceptions::ini_exceptions(int lPos, std::string msg)
    : posInLine(lPos)
    {
        message = "Syntax error at line №" + std::to_string(posInLine) + ": " + msg;
    }

    /* Метод проверяет является ли строка s числом
    в строковом представлении. Проверяются целые и дробные числа */
    bool Parser::is_number(const std::string_view& s)
    {
        if (s.empty())
            return false;

        unsigned int point = 0;
        for (const auto &ch : s)
        {
            if (point > 1)
                return false;

            if ( ch == '.' || ch == ',' ) {
                ++point;
                continue;
            }

            if ( !std::isdigit(static_cast<unsigned int>(ch)) )
                return false;
        }

        return true;
    }

    /* Метод проверяет является ли строка s булевым типом */
    bool Parser::is_boolean(const std::string_view &s) const {
        return s == "true" || s == "false" ? true : false;
    }

    /* Метод проверяет имеет ли строка kv
    знак равенства "=" */
    bool Parser::isKv(const std::string_view &kv) const
    {
        return kv.find_first_of('=') != std::string::npos ?
            true : false;
    }

    /* Метод удаляет пробелы, символы табуляции и новые строки
    в конце и начале строки str */
    std::string_view Parser::trim(const std::string_view &str)
    {
        if (!str.length())
            return {};

        const char wp[] = {" \t\n"};

        const size_t lspaced(str.find_first_not_of(wp));
        if (std::string::npos == lspaced)
            return {};

        const size_t rspaced(str.find_last_not_of(wp));
        return str.substr(lspaced, (rspaced - lspaced + 1));
    }

    /* Проверка строки section на наличии секционных скобок []*/
    bool Parser::isSection(const std::string_view &section) const {
        return section[0] == '[' || 
                section[section.length() - 1] == ']' ? 
                true : false;
    }

    /* Проверка строки section на валидность*/
    bool Parser::isValidSection(const std::string_view &section) const
    {
        // Section must starts with '['
        if ( section[0] != '[' )
            throw ini_exceptions(line_count, "Section must starts with '['");

        std::size_t len = section.length();
        // Section must ends with '['
        if ( section.find_last_of(']') != len - 1 )
            throw ini_exceptions(line_count, "Not consistent section");

        if (section[len - 1] != ']')
            throw ini_exceptions(line_count, "Section must ends with ']'");

        // Section length must be more than 2 symbols
        if ( len <= 2 )
            throw ini_exceptions(line_count, "Section, could not be empty!");

        return true;
    }

    std::string_view Parser::getSectionName(const std::string_view &section) {
        return section.substr(1, section.length() - 2);
    }

    /* Основной конструктор filePath - путь к *.ini файлу */
    Parser::Parser(const std::string &filePath)
    : line_count(0)
    , section_count(0)
    , kv_count(0)
    {
        std::ifstream In(filePath);
        if ( ! In.is_open() )
            throw std::runtime_error("Could not open file...");

        std::string line, current_section;        
        while (std::getline(In, line))
        {
            size_t pp = line.find_first_of(';');
            if ( pp != std::string::npos )
                line = line.substr(0, pp);

            line = trim(line);
            ++line_count;

            // Skip blank lines
            if ( ! line.length() )
                continue;

            /* search sections first */
            if ( isSection(line) && isValidSection(line) )
            {
                ++section_count;
                current_section = std::string(trim(getSectionName(line)));

                std::transform(current_section.begin(),
                               current_section.end(),
                               current_section.begin(),
                               ::tolower);

                section[current_section] = {};
            }
            else if ( isKv(line) )
            {
                ++kv_count;
                if ( !section_count )
                    throw ini_exceptions(line_count, "Key-value must be in section");

                size_t eqPos = line.find_first_of('=');
                std::string key = std::string(trim(line.substr(0, eqPos)));

                if ( key.empty() )
                    throw ini_exceptions(line_count, "Key can't be empty!");

                std::string value = std::string(trim(line.substr(eqPos + 1)));
                section[current_section].insert_or_assign(key, value);
            }
            else
                throw ini_exceptions(line_count, line);

        } // end of main loop
    }
}