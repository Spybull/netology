#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

std::vector<std::string> parseByDelim(std::string, char);
bool isFileEmpty(const std::string& filename);