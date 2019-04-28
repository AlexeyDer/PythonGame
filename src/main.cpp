#include "binding.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
using namespace sf;

int N = 30, M = 20;
int size = 32;
int w = size * N;
int h = size * M;

int dir, num = 2;

struct Snake {
    int x;
    int y;
} s[100];

void Tick()
{
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
}

int main()
{
    RenderWindow window(
            VideoMode(w + 240, h),
            "Snake Game",
            Style::None); // Style::Fullscreen  //Style::None

    Texture t1, t2;
    t1.loadFromFile("/home/ilya/Документы/PythonGame/images/77.png");
    t2.loadFromFile("/home/ilya/Документы/PythonGame/images/23.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);

    Clock clock;
    float timer = 0, delay = 0.1;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))
                dir = 1;
            if (Keyboard::isKeyPressed(Keyboard::Right))
                dir = 2;
            if (Keyboard::isKeyPressed(Keyboard::Up))
                dir = 3;
            if (Keyboard::isKeyPressed(Keyboard::Down))
                dir = 0;

            if (timer > delay) {
                timer = 0;
                Tick();
            }

            ////// draw  ///////

            window.clear();

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    sprite1.setPosition(i * size, j * size);
                    window.draw(sprite1);
                }
            }

            for (int i = 0; i < num; i++) {
                sprite2.setPosition(s[i].x * size, s[i].y * size);
                window.draw(sprite2);
            }

            window.display();
        }
    }

    return 0;
}