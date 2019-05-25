#include "binding.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

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
    int foo = 0;
    int iter = 0;
    String st = "";

    RenderWindow window(
            VideoMode(w + 240, h),
            "Snake Game",
            Style::None); // Style::Fullscreen  //Style::None

    Texture tex1, tex2, tex3, tex4, tex5;
    tex1.loadFromFile("images/77.png");
    tex2.loadFromFile("images/23.png");
    tex3.loadFromFile("images/666.png");
    tex4.loadFromFile("images/44.png");
    tex5.loadFromFile("images/farm.png");
    if (!tex1.loadFromFile("images/77.png"))
        return 0;
    if (!tex2.loadFromFile("images/23.png"))
        return 0;
    if (!tex3.loadFromFile("images/666.png"))
        return 0;
    if (!tex4.loadFromFile("images/44.png"))
        return 0;
    if (!tex5.loadFromFile("images/farm.png"))
        return 0;

    Sprite sprite1(tex1);
    Sprite sprite2(tex2);
    Sprite sprite3(tex3);
    Sprite sprite4(tex4);
    Sprite sprite5(tex5);

    Clock clock;
    float timer = 0;

    f.x = rand() % N;
    f.y = rand() % M;

    suf.x = -1;
    suf.y = -1;

    p.x = -1;
    p.y = -1;

    p1.x = -1;
    p1.y = -1;

    p2.x = -1;
    p2.y = -1;

    p3.x = -1;
    p3.y = -1;

    p4.x = -1;
    p4.y = -1;

    ///////////////
    t.x = -1;
    t.y = -1;

    t1.x = -1;
    t1.y = -1;

    t2.x = -1;
    t2.y = -1;

    t3.x = -1;
    t3.y = -1;

    t4.x = -1;
    t4.y = -1;

    t5.x = -1;
    t5.y = -1;

    t6.x = -1;
    t6.y = -1;

    t7.x = -1;
    t7.y = -1;

    t8.x = -1;
    t8.y = -1;

    t9.x = -1;
    t9.y = -1;

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

        KeyBoardPressLeft(Keyboard::Left, R, dir, L, U, D);
        KeyBoardPressRight(Keyboard::Right, R, dir, L, U, D);
        KeyBoardPressUp(Keyboard::Up, R, dir, L, U, D);
        KeyBoardPressDown(Keyboard::Down, R, dir, L, U, D);

        if (Keyboard::isKeyPressed(Keyboard::Q))
            return 0;

        if (Keyboard::isKeyPressed(Keyboard::E)) {
            num = 1;
            max2 = 0;
            spe = 1;
            delay = 0.15;
        }

        if (Keyboard::isKeyPressed(Keyboard::X)) {
            foo = 1;
            p.x = rand() % N;
            p.y = rand() % M;

            p1.x = rand() % N;
            p1.y = rand() % M;

            p2.x = rand() % N;
            p2.y = rand() % M;

            p3.x = rand() % N;
            p3.y = rand() % M;

            p4.x = rand() % N;
            p4.y = rand() % M;
        }

        if (Keyboard::isKeyPressed(Keyboard::C)) {
            foo = 2;
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

        if (Keyboard::isKeyPressed(Keyboard::Z)) {
            foo = 0;

            p.x = -1;
            p.y = -1;

            p2.x = -1;
            p2.y = -1;

            p3.x = -1;
            p3.y = -1;

            p4.x = -1;
            p4.y = -1;

            p1.x = -1;
            p1.y = -1;

            t.x = -1;
            t.y = -1;

            t1.x = -1;
            t1.y = -1;

            t2.x = -1;
            t2.y = -1;

            t3.x = -1;
            t3.y = -1;

            t4.x = -1;
            t4.y = -1;

            t5.x = -1;
            t5.y = -1;

            t6.x = -1;
            t6.y = -1;

            t7.x = -1;
            t7.y = -1;

            t8.x = -1;
            t8.y = -1;

            t9.x = -1;
            t9.y = -1;
        }

        if (foo == 0) {
            if (timer > delay) {
                timer = 0;
                Tick(num, max1, max2, spe, dir, delay, iter);
            }
        }
        if (foo == 1) {
            if (timer > delay) {
                timer = 0;
                Lev(num, max1, max2, spe, dir, delay, iter);
            }
        }
        if (foo == 2) {
            if (timer > delay) {
                timer = 0;
                Lev2(num, max1, max2, spe, dir, delay, iter);
            }
        }

        ////// draw  ///////

        window.clear();

        Font font;
        font.loadFromFile("images/5555.ttf");
        if (!font.loadFromFile("images/5555.ttf")) {
            return 0;
        }
        Text text, text0, text2, text3, text4, text5, text6, text7, text8,
                text9, text10, text11, text12, text13;

        if (num < max2) {
            text3.setFont(font);
            text3.setString("Your Result:");
            text3.setCharacterSize(24);
            text3.setPosition(990, 80);
            window.draw(text3);

            text4.setFont(font);
            text4.setPosition(1150, 80);
            text4.setString((To_string(max2)));
            text4.setCharacterSize(24);
            window.draw(text4);

            text8.setFont(font);
            text8.setString("You");
            text8.setCharacterSize(65);
            text8.setPosition(1025, 180);
            window.draw(text8);

            if (foo == 1) {
                text10.setFont(font);
                text10.setString("Level   1");
                text10.setCharacterSize(50);
                text10.setPosition(990, 400);
                window.draw(text10);

                text12.setFont(font);
                text12.setString("Press 'Z' out Level1");
                text12.setCharacterSize(24);
                text12.setPosition(975, 500);
                window.draw(text12);
            }

            if (foo == 2) {
                text10.setFont(font);
                text10.setString("Level   2");
                text10.setCharacterSize(50);
                text10.setPosition(990, 400);
                window.draw(text10);

                text12.setFont(font);
                text12.setString("Press 'Z' out Level2");
                text12.setCharacterSize(24);
                text12.setPosition(975, 500);
                window.draw(text12);
            }

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
        }

        else {
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
            text2.setString(((To_string(num))));
            text2.setCharacterSize(24);
            window.draw(text2);

            text3.setFont(font);
            text3.setString("Your Record:");
            text3.setCharacterSize(24);
            text3.setPosition(990, 170);
            window.draw(text3);

            text4.setFont(font);
            text4.setPosition(1150, 170);
            text4.setString((To_string(max1)));
            text4.setCharacterSize(24);
            window.draw(text4);

            if (foo == 1) {
                text10.setFont(font);
                text10.setString("Level   1");
                text10.setCharacterSize(50);
                text10.setPosition(990, 360);
                window.draw(text10);

                text12.setFont(font);
                text12.setString("Press 'Z' out Level1");
                text12.setCharacterSize(24);
                text12.setPosition(975, 500);
                window.draw(text12);
            }

            if (foo == 2) {
                text10.setFont(font);
                text10.setString("Level   2");
                text10.setCharacterSize(50);
                text10.setPosition(990, 360);
                window.draw(text10);

                text12.setFont(font);
                text12.setString("Press 'Z' out Level2");
                text12.setCharacterSize(24);
                text12.setPosition(975, 500);
                window.draw(text12);
            }
            text6.setFont(font);
            text6.setString("speed:");
            text6.setCharacterSize(24);
            text6.setPosition(1030, 420);
            window.draw(text6);

            text7.setFont(font);
            text7.setPosition(1128, 420);
            text7.setString((st + (To_string(spe))));
            text7.setCharacterSize(24);
            window.draw(text7);

            if (foo == 0) {
                text11.setFont(font);
                text11.setString("Press 'X' exit Level1");
                text11.setCharacterSize(24);
                text11.setPosition(975, 500);
                window.draw(text11);

                text13.setFont(font);
                text13.setString("Press 'C' exit Level2");
                text13.setCharacterSize(24);
                text13.setPosition(975, 460);
                window.draw(text13);
            }

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

        sprite4.setPosition(p.x * size, p.y * size);
        window.draw(sprite4);

        sprite4.setPosition(p1.x * size, p1.y * size);
        window.draw(sprite4);

        sprite4.setPosition(p2.x * size, p2.y * size);
        window.draw(sprite4);

        sprite4.setPosition(p3.x * size, p3.y * size);
        window.draw(sprite4);

        sprite4.setPosition(p4.x * size, p4.y * size);
        window.draw(sprite4);
        //////////////////////////
        sprite4.setPosition(t.x * size, t.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t1.x * size, t1.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t2.x * size, t2.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t3.x * size, t3.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t4.x * size, t4.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t5.x * size, t5.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t6.x * size, t6.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t7.x * size, t7.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t8.x * size, t8.y * size);
        window.draw(sprite4);

        sprite4.setPosition(t9.x * size, t9.y * size);
        window.draw(sprite4);

        sprite5.setPosition(suf.x * size, suf.y * size);
        window.draw(sprite5);

        window.display();
    }
    return 0;
}
