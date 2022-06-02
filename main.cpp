#include "SFML/Graphics.hpp"

int main() {

    const int width = 400;
    const int height = 400;

    sf::RenderWindow window(sf::VideoMode(width, height), "q-w(lambda) | e-r(amplitude) | t-y(speed) a(reload)", sf::Style::Close);


    sf::Text text;

    sf::Font font;
    font.loadFromFile("./OpenSans-Regular.ttf");

    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 0);
    text.setLetterSpacing(2);

    float angle = 0;
    float radius = 2;

    float lambda = 50;
    float amplitude = 2;
    float speed = 0.01;

    //window.setKeyRepeatEnabled(false);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    lambda = 50;
                    amplitude = 2;
                    speed = 0.01;
                }
                else if (event.key.code == sf::Keyboard::Q) {
                    lambda += 0.2;
                }
                else if (event.key.code == sf::Keyboard::W) {
                    lambda -= 0.2;
                }
                else if (event.key.code == sf::Keyboard::E) {
                    amplitude += 0.01;
                }
                else if (event.key.code == sf::Keyboard::R) {
                    amplitude -= 0.01;
                }
                else if (event.key.code == sf::Keyboard::T) {
                    speed += 0.002;
                }
                else if (event.key.code == sf::Keyboard::Y) {
                    speed -= 0.002;
                }
            }
        }


        window.clear();

        
        for (int i = 0; i < width; i += radius)
        {
            sf::CircleShape circle;

            circle.setRadius(radius/2);
            circle.setPosition(i + radius/2, (sin(angle + i / lambda) * (height / amplitude) + height / 2));
            circle.setOrigin(circle.getRadius(), circle.getRadius());
            circle.setFillColor(sf::Color::White);
            circle.setOutlineThickness(0.0f);

            text.setString("lambda=" + std::to_string(lambda) + "\n-amplitude=" + std::to_string(amplitude) + "\nspeed=" + std::to_string(speed));

            window.draw(text);
            window.draw(circle);
        }

        angle += speed;
        if (angle >= 90)
        {
            angle = 0;
        }

        if (lambda <= 20)
        {
            lambda = 20;
        }
        else if (lambda >= 200) {
            lambda = 200;
        }
        
        if (amplitude >= 10)
        {
            amplitude = 10;
        }
        else if (amplitude <= 2) {
            amplitude = 2;
        }

        if (speed <= 0.005)
        {
            speed = 0.005;
        }
        else if (speed >= 0.3)
        {
            speed = 0.3;
        }

        window.display();
    }

    return 0;
}