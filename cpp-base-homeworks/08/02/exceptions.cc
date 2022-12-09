#include "exceptions.h"

FigureException::FigureException(std::string error) : err(error) {}
        
const char *FigureException::what() const noexcept {
    return err.c_str();
}