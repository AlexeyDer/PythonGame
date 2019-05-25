#include "binding.h"

int KeyBoardPressLeft(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if (Keyboard::isKeyPressed(button) && R == 1) {
        dir = 1;
        L = 0;
        U = 1;
        D = 1;
        return 0;
    }
    return 1;
}

int KeyBoardPressUp(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if (Keyboard::isKeyPressed(Keyboard::Up) && D == 1) {
        dir = 3;
        U = 0;
        L = 1;
        R = 1;
        return 0;
    }
    return 1;
}

int KeyBoardPressRight(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if (Keyboard::isKeyPressed(Keyboard::Right) && L == 1) {
        dir = 2;
        R = 0;
        U = 1;
        D = 1;
        return 0;
    }
    return 1;
}

int KeyBoardPressDown(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if (Keyboard::isKeyPressed(Keyboard::Down) && U == 1) {
        dir = 0;
        D = 0;
        L = 1;
        R = 1;
        return 0;
    }
    return 1;
}
