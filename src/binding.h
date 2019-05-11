#ifndef BINDING_H
#define BINDING_H

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

double
Tick(int& num,
     int& max1,
     int& max2,
     int& spe,
     int& dir,
     float& delay,
     int& iter);
double Lev(int& num, int& max1, int& max2, int& spe, int& dir, float& delay);
double Lev2(int& num, int& max1, int& max2, int& spe, int& dir, float& delay);

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

#endif // BINDING_H
