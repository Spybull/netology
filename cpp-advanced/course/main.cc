#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <algorithm>

typedef std::map<std::string, std::string> map_ss;

class ini_exceptions : public std::exception {
    private:
        int posInLine;
        std::string message;

    public:
        ini_exceptions(int lPos, std::string msg) : posInLine(lPos) {
            message = "Err:" + std::to_string(posInLine) + ": " + msg;
        }

        ini_exceptions(std::string keyVal, map_ss kv) {
            std::cout << "Key " << keyVal << " not found. Available keys: " << std::endl;
            message = "";
            for (const auto &i : kv)
                std::cout  << i.first << std::endl;
        }

        virtual const char *what() const noexcept override {
            return message.c_str();
        }
};

class ini_parser {

    private:
        std::string filePath;
        size_t line_count;
        size_t section_count;
        size_t kv_count;
        std::map< std::string, map_ss > section;

        inline bool is_number(const std::string& s) {

            std::string::const_iterator it = s.cbegin();
            int point = 0;
            while ( (it != s.end() && std::isdigit(*it)) || *it == '.') {
                if (*it == '.') ++point;
                 ++it;
            }

            if ( point > 1 )
                return false;

            return !s.empty() && it == s.end();
        }
        inline bool isKv(const std::string &kv) const {
            return kv.find_first_of('=') != std::string::npos ?
                   true : false;
        }
        inline std::string trim(const std::string &str) {

            if (!str.length())
                return {};

            const char wp[] = {" \t\n"};

            const size_t lspaced(str.find_first_not_of(wp));
            if (std::string::npos == lspaced)
                return {};

            const size_t rspaced(str.find_last_not_of(wp));
            return str.substr(lspaced, (rspaced - lspaced + 1));
        }

        // Send only formatted strings [Section functions]
        bool isSection(std::string &section) {
            return section[0] == '[' || 
                   section[section.length() - 1] == ']' ? 
                   true : false;
        }
        bool isValidSection(const std::string &section) const{

             std::size_t len = section.length();

            // Section must starts with '['
            if ( section[0] != '[' )
                throw ini_exceptions(line_count, "Section must starts with '['");

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
        std::string getSectionName(const std::string &section) {
            return section.substr(1, section.length() - 2);
        }

    public:
        ini_parser() = default;
        ini_parser(std::string filePath)
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
                    line = line.erase(pp);

                line = trim(line);
                ++line_count;

                // Skip blank lines
                if ( ! line.length() )
                    continue;

                /* search sections first */
                if ( isSection(line) && isValidSection(line) ) {

                    ++section_count;
                    current_section = trim(getSectionName(line));

                    std::transform(current_section.begin(),
                                   current_section.end(),
                                   current_section.begin(),
                                   ::tolower);

                    if (section.find(current_section) == section.end()) {
                        section[current_section] = {};
                    }

                } else if ( isKv(line) ) {

                    ++kv_count;
                    if ( !section_count )
                        throw ini_exceptions(line_count, "Key-value must be in section");

                    size_t eqPos = line.find_first_of('=');
                    std::string key = trim(line.substr(0, eqPos));

                    if ( key.empty() )
                        throw ini_exceptions(line_count, "Key can't be empty!");

                    std::string value = trim(line.substr(eqPos + 1));
                    section[current_section].insert_or_assign(key, value);
                }
                else
                    throw ini_exceptions(line_count, "It's not a key, just string");
 
            } // end of main loop
        }

        template<typename T>
        T get_value(std::string str_val) {

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

        ini_parser(const ini_parser &) = delete;
        ini_parser(ini_parser &&) = delete;
        ini_parser &operator=(const ini_parser &) = delete;
        ini_parser &operator=(ini_parser &&) = delete;
        ~ini_parser() = default;
};


int main()
{
    try
    {
        ini_parser parser("test.ini");
        std::cout << parser.get_value<std::string>("section2.var4") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}