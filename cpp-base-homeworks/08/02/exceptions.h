#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <exception>

class FigureException : public std::exception {
    private:
        std::string err;
    public:
        FigureException(std::string error);
        virtual const char *what() const noexcept override;
};
#endif