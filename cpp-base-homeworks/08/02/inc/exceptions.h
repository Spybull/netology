#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <exception>

enum FigureExitCodes {
    SIDES_COUNT_NOT_ZERO,
    SIDES_COUNT_ERR,
    SIDES_B_D_NOT_EQUAL,
    SIDES_A_C_NOT_EQUAL,
    ALL_SIDES_NOT_EQ,
    ANGLE_C_NOT_90,
    ANGLES_A_C_NOT_EQUAL,
    ANGLES_B_D_NOT_EQUAL,
    ANGLES_SUM_NOT_EQ_360,
    ANGLES_SUM_NOT_EQ_180,
    ALL_ANGLES_NOT_EQ_90,
    ALL_ANGLES_NOT_EQ_60,
};

class FigureException : public std::exception {
    private:
        int exCode;
    public:
        FigureException(int err_code);
        virtual const char *what() const noexcept override;
};
#endif