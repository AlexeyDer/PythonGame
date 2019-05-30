#ifndef BINDING_H
#define BINDING_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

struct Fruct {
    int x;
    int y;
};
extern Fruct f;

struct Level1 {
    int x;
    int y;
};

extern Level1 p;
extern Level1 p1;
extern Level1 p2;
extern Level1 p3;
extern Level1 p4;

struct Level2 {
    int x;
    int y;
};

extern Level2 t;
extern Level2 t1;
extern Level2 t2;
extern Level2 t3;
extern Level2 t4;
extern Level2 t5;
extern Level2 t6;
extern Level2 t7;
extern Level2 t8;
extern Level2 t9;

struct Snake {
    int x;
    int y;
};

extern Snake s[100];

struct Sfruct {
    int x;
    int y;
};

extern Sfruct suf;

double
Tick(int& num,
     int& max1,
     int& max2,
     int& spe,
     int& dir,
     float& delay,
     int& iter);
double
Lev(int& num,
    int& max1,
    int& max2,
    int& spe,
    int& dir,
    float& delay,
    int& iter);

double
Lev2(int& num,
     int& max1,
     int& max2,
     int& spe,
     int& dir,
     float& delay,
     int& iter);

template <typename T>
std::string To_string(T value)
{
    // create an output string stream
    std::ostringstream os;

    // throw the value into the string stream
    os << value;

    // convert the string stream into a string and return
    return os.str();
}
int KeyBoardPressRight(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D);
int KeyBoardPressLeft(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D);
int KeyBoardPressUp(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D);
int KeyBoardPressDown(
        Keyboard::Key button, int& R, int& dir, int& L, int& U, int& D);
int TurnSnake(int dir);
int TeleportationSnake(int& count, int N);
int SuperFructSpawn(int iter, int& x, int& y, int N, int M, int& timer);
int UpSpeed(int num, float& delay, int& spe);

#endif // BINDING_H
