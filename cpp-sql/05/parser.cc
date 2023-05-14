#include "parser.h"

std::vector<std::string> parseByDelim(std::string line, char delim)
{
    std::vector<std::string> fields;
    size_t start = 0;
    size_t end = line.find(delim);

    while (end != std::string::npos)
    {
        fields.emplace_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find(delim, start);
    }

    fields.emplace_back(line.substr(start));
    return fields;
}

bool isFileEmpty(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && std::all_of(line.begin(), line.end(), ::isspace) == false) {
            return false;
        }
    }

    return true;
}