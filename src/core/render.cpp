#include "render.h"
#include <SFML/Graphics.hpp>

void display_triangle() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Hello World");

    sf::CircleShape shape(100.f,  3);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
}