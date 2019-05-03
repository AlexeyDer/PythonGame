#include "binding.h"
#include "fruct.h"
#include "snake.h"

using namespace std;

double Tick(int& num, int& max1, int& max2, int& spe, int& dir, float& delay)
{
    int N = 30, M = 20;

    for (int i = num; i > 0; --i) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0)
        s[0].y += 1;
    if (dir == 1)
        s[0].x -= 1;
    if (dir == 2)
        s[0].x += 1;
    if (dir == 3)
        s[0].y -= 1;

    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        num++;
        if (num >= max1)
            max1 = num;
        if (num >= max2)
            max2 = num;

        if (num > 5) {
            delay = 0.09;
            spe = 2;
        }
        if (num > 10) {
            delay = 0.06;
            spe = 3;
        }
        if (num > 15) {
            delay = 0.04;
            spe = 4;
        }

        f.x = rand() % N;
        f.y = rand() % M;
    }

    if (s[0].x > N - 1)
        s[0].x = 0;
    if (s[0].x < 0)
        s[0].x = N - 1;
    if (s[0].y > M - 1)
        s[0].y = 0;
    if (s[0].y < 0)
        s[0].y = M - 1;

    for (int i = 1; i < num; i++) {
        if (s[0].x == s[i].x && s[0].y == s[i].y) {
            num = i;
        }
    }
    return max1;
}