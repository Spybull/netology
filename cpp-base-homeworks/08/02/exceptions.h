#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <exception>

class Exceptions : public std::exception {
    private:
        std::string err;
    public:
        Exceptions(std::string error);
        
        virtual const char *what() const noexcept override;
};
#endif