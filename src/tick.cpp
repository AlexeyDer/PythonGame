#include "binding.h"
#include "ctime"

int timer = 0;

double
Tick(int& num,
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

    TurnSnake(dir);

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
        SuperFructSpawn(iter, suf.x, suf.y, N, M, timer);
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

    TeleportationSnake(s[0].x, N);
    TeleportationSnake(s[0].y, M);

    for (int i = 1; i < num; i++) {
        if (s[0].x == s[i].x && s[0].y == s[i].y) {
            num = i;
        }
    }

    if (timer > 0)
        timer++;

    if (timer == 50) {
        suf.x = -1, suf.y = -1;
        timer = 0;
    }

    return 0;
}
