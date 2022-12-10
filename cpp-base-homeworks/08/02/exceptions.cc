#include "inc/exceptions.h"

FigureException::FigureException(int err_code)
    : exCode(err_code)
{}

const char *FigureException::what() const noexcept {
    
    switch (exCode)
    {
        case FigureExitCodes::SIDES_COUNT_NOT_ZERO:
            return "Error! Can't create figure with more than zero sides";
        break;
        case FigureExitCodes::ANGLES_SUM_NOT_EQ_360:
            return "Can't create! Because: sum of angles are not equal 360";
        break;
        case FigureExitCodes::ANGLES_SUM_NOT_EQ_180:
            return "Can't create! Because: sum of angles are not equal 180";
        break;
        case FigureExitCodes::ALL_ANGLES_NOT_EQ_90:
            return "Can't create! Because: all angles must be 90";
        break;
        case FigureExitCodes::ALL_SIDES_NOT_EQ:
            return "Can't create! Because: all sides must be equal";
        break;
        case FigureExitCodes::ANGLE_C_NOT_90:
            return "Can't create! Because: 'C'-angle doesn't equal 90";
        break;
        case FigureExitCodes::ANGLES_A_C_NOT_EQUAL:
            return "Can't create! Because: A angle != C angle";
        break;
        case FigureExitCodes::ALL_ANGLES_NOT_EQ_60:
            return "Can't create! Because: all angles must be 60";
        break;
        case FigureExitCodes::SIDES_A_C_NOT_EQUAL:
            return "Can't create! Because: a side != c side";
        break;
        case FigureExitCodes::SIDES_B_D_NOT_EQUAL:
            return "Can't create! Because: b side != d side";
        break;

    default:
        break;
    }

    return "Unknown error";
}