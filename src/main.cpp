#include "binding.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
using namespace sf;

int N = 30, M = 20;
int size = 32;
int w = size * N;
int h = size * M;

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

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }

            ////// draw  ///////

            window.clear();

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    sprite1.setPosition(i * size, j * size);
                    window.draw(sprite1);
                }
            }
            window.display();
        }
    }

    return 0;
}