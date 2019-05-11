#include "SuperFrute.hpp"
#include "binding.h"
#include "fruct.h"
#include "level2.h"
#include "snake.h"

using namespace std;

double
Lev2(int& num,
     int& max1,
     int& max2,
     int& spe,
     int& dir,
     float& delay,
     int& iter)
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

        iter++;
        if (iter != 1 && (iter % 5 == 0)) {
            suf.x = rand() % N;
            suf.y = rand() % M;
        }
    }

    if ((s[0].x == t.x) && (s[0].y == t.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t1.x) && (s[0].y == t1.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t2.x) && (s[0].y == t2.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t3.x) && (s[0].y == t3.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t4.x) && (s[0].y == t4.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t5.x) && (s[0].y == t5.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t6.x) && (s[0].y == t6.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t7.x) && (s[0].y == t7.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t8.x) && (s[0].y == t8.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == t9.x) && (s[0].y == t9.y)) {
        num = 1;
        max2 = 0;
        spe = 1;
        delay = 0.15;
        t.x = rand() % N;
        t.y = rand() % M;

        t1.x = rand() % N;
        t1.y = rand() % M;

        t2.x = rand() % N;
        t2.y = rand() % M;

        t3.x = rand() % N;
        t3.y = rand() % M;

        t4.x = rand() % N;
        t4.y = rand() % M;

        t5.x = rand() % N;
        t5.y = rand() % M;

        t6.x = rand() % N;
        t6.y = rand() % M;

        t7.x = rand() % N;
        t7.y = rand() % M;

        t8.x = rand() % N;
        t8.y = rand() % M;

        t9.x = rand() % N;
        t9.y = rand() % M;
    }

    if ((s[0].x == suf.x) && (s[0].y == suf.y)) {
        num += 4;
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
        suf.x = -1;
        suf.y = -1;
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