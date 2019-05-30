#include "binding.h"
struct Snake s[100];
struct Fruct f;
struct Level1 p;
struct Level1 p1;
struct Level1 p2;
struct Level1 p3;
struct Level1 p4;
struct Level2 t;
struct Level2 t1;
struct Level2 t2;
struct Level2 t3;
struct Level2 t4;
struct Level2 t5;
struct Level2 t6;
struct Level2 t7;
struct Level2 t8;
struct Level2 t9;
struct Sfruct suf;

int KeyBoardPressLeft(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if ((button == Keyboard::Left) && (R == 1)) {
        if (Keyboard::isKeyPressed(button)) {
            dir = 1;
            L = 0;
            U = 1;
            D = 1;
        }
        return 0;
    }
    return 1;
}

int KeyBoardPressUp(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if ((button == Keyboard::Up) && D == 1) {
        if (Keyboard::isKeyPressed(button)) {
            dir = 3;
            U = 0;
            L = 1;
            R = 1;
        }
        return 0;
    }
    return 1;
}

int KeyBoardPressRight(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if ((button == Keyboard::Right) && (L == 1)) {
        if (Keyboard::isKeyPressed(button)) {
            dir = 2;
            R = 0;
            U = 1;
            D = 1;
        }
        return 0;
    }
    return 1;
}

int KeyBoardPressDown(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D)
{
    if ((button == Keyboard::Down) && U == 1) {
        if (Keyboard::isKeyPressed(button)) {
            dir = 0;
            D = 0;
            L = 1;
            R = 1;
        }
        return 0;
    }
    return 1;
}

int TurnSnake(int dir)
{
    if (dir == 0) {
        s[0].y += 1;
        return 0;
    }
    if (dir == 1) {
        s[0].x -= 1;
        return 1;
    }
    if (dir == 2) {
        s[0].x += 1;
        return 2;
    }
    if (dir == 3) {
        s[0].y -= 1;
        return 3;
    }
    return -1;
}

int TeleportationSnake(int& count, int N)
{
    if (count > N - 1) {
        count = 0;
        return 0;
    }
    if (count < 0) {
        count = N - 1;
        return 0;
    }
    return 1;
}

int SuperFructSpawn(int iter, int& x, int& y, int N, int M, int& timer)
{
    if (iter != 1 && (iter % 5 == 0)) {
        timer++;
        x = rand() % N;
        y = rand() % M;
        return 0;
    }
    return 1;
}

int UpSpeed(int num, float& delay, int& spe)
{
    if (num > 15) {
        delay = 0.04;
        spe = 4;
        return 3;
    }
    if (num > 10) {
        delay = 0.06;
        spe = 3;
        return 2;
    }
    if (num > 5) {
        delay = 0.09;
        spe = 2;
        return 1;
    }

    return 0;
}
