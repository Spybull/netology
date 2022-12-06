#include "exceptions.h"

Exceptions::Exceptions(std::string error) : err(error) {}
        
const char *Exceptions::what() const noexcept {
    return err.c_str();
}