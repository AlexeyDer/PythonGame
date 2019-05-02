#include "binding.h"
#include "fruct.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
using namespace sf;

struct Snake s[100];
struct Fruct f;

int main()
{
    srand(time(NULL));

    float delay = 0.15;
    int dir, num = 1, max1 = 0, spe = 1, max2 = 0;

    int N = 30, M = 20;
    int size = 32;
    int w = size * N;
    int h = size * M;
    int L = 1, R = 1, U = 1, D = 1;

    RenderWindow window(
            VideoMode(w + 240, h),
            "Snake Game",
            Style::None); // Style::Fullscreen  //Style::None

    Texture t1, t2, t3;
    t1.loadFromFile("images/77.png");
    t2.loadFromFile("images/23.png");
    t3.loadFromFile("images/666.png");
    if (!t1.loadFromFile("images/77.png"))
        return 0;
    if (!t2.loadFromFile("images/23.png"))
        return 0;
    if (!t3.loadFromFile("images/666.png"))
        return 0;

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);

    Clock clock;
    float timer = 0;

    f.x = 10;
    f.y = 10;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::A) && R == 1) {
            dir = 1;
            L = 0;
            U = 1;
            D = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && L == 1) {
            dir = 2;
            R = 0;
            U = 1;
            D = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::W) && D == 1) {
            dir = 3;
            U = 0;
            L = 1;
            R = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && U == 1) {
            dir = 0;
            D = 0;
            L = 1;
            R = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Q))
            return 0;
        if (Keyboard::isKeyPressed(Keyboard::E)) {
            num = 2;
            max2 = 0;
            spe = 1;
            delay = 0.15;
        }

        if (timer > delay) {
            timer = 0;
            Tick(num, max1, max2, spe, dir, delay);
        }

        ////// draw  ///////

        window.clear();

        Font font;
        font.loadFromFile("images/5555.ttf");
        if (!font.loadFromFile("images/5555.ttf")) {
            return 0;
        }
        Text text, text0, text2, text3, text4, text5, text6, text7, text8,
                text9;

        if (num < max2) {
            text3.setFont(font);
            text3.setString("Your Result:");
            text3.setCharacterSize(24);
            text3.setPosition(990, 110);
            window.draw(text3);

            text4.setFont(font);
            text4.setPosition(1150, 110);
            text4.setString(std::to_string(max2));
            text4.setCharacterSize(24);
            window.draw(text4);

            text8.setFont(font);
            text8.setString("You");
            text8.setCharacterSize(65);
            text8.setPosition(1025, 180);
            window.draw(text8);

            text9.setFont(font);
            text9.setString("Lose");
            text9.setCharacterSize(65);
            text9.setPosition(1017, 280);
            window.draw(text9);

            text5.setFont(font);
            text5.setString("Press 'E' for restart");
            text5.setCharacterSize(24);
            text5.setPosition(975, 540);
            window.draw(text5);

            text5.setFont(font);
            text5.setString("Press 'Q' for exit");
            text5.setCharacterSize(24);
            text5.setPosition(990, 580);
            window.draw(text5);
        } else {
            text0.setFont(font);
            text0.setString("Python");
            text0.setCharacterSize(65);
            text0.setPosition(980, 10);
            window.draw(text0);

            text.setFont(font);
            text.setString("Your Score:");
            text.setCharacterSize(24);
            text.setPosition(990, 110);
            window.draw(text);

            text2.setFont(font);
            text2.setPosition(1150, 110);
            text2.setString(std::to_string(num));
            text2.setCharacterSize(24);
            window.draw(text2);

            text3.setFont(font);
            text3.setString("Your Record:");
            text3.setCharacterSize(24);
            text3.setPosition(990, 170);
            window.draw(text3);

            text4.setFont(font);
            text4.setPosition(1150, 170);
            text4.setString(std::to_string(max1));
            text4.setCharacterSize(24);
            window.draw(text4);

            text6.setFont(font);
            text6.setString("speed:");
            text6.setCharacterSize(20);
            text6.setPosition(990, 500);
            window.draw(text6);

            text7.setFont(font);
            text7.setPosition(1088, 500);
            text7.setString(std::to_string(spe));
            text7.setCharacterSize(20);
            window.draw(text7);

            text5.setFont(font);
            text5.setString("Press 'E' for restart");
            text5.setCharacterSize(24);
            text5.setPosition(975, 540);
            window.draw(text5);

            text5.setFont(font);
            text5.setString("Press 'Q' for exit");
            text5.setCharacterSize(24);
            text5.setPosition(990, 580);
            window.draw(text5);
        }

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

        sprite3.setPosition(f.x * size, f.y * size);
        window.draw(sprite3);

        window.display();
    }
    return 0;
}
