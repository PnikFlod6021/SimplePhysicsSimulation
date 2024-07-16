#include <iostream>

#include <SFML/Graphics.hpp>

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(1280, 720),
                                    "Collision Simulation",
                                    sf::Style::Default);
    window.setFramerateLimit(500);

    sf::Time deltaTime;
    float speed = 9.81f;
    sf::Clock clock;


    sf::Time previousTime = clock.getElapsedTime();
    std::vector<sf::CircleShape> circles(5);
    auto circle = sf::CircleShape(35, 15);
    circle.setPosition(100,100);
    circle.setFillColor(sf::Color(255, 0, 0));



    sf::Vector2f velocity(circle.getPosition());


    while (window.isOpen())
    {

        auto temp = circle.getPosition();
        bool hasCollidedX = temp.x <= 0 || temp.x >= window.getSize().x - 2 * circle.getRadius();
        bool hasCollidedY = temp.y <= 0 || temp.y >= window.getSize().y - 2 * circle.getRadius();

        if(hasCollidedY)
        {
            velocity.y = -(velocity.y) + speed*deltaTime.asSeconds();
            velocity.y *= 1.2f;
            std::cout<<velocity.y;

        } else if(hasCollidedX)
        {
            velocity.x = -(velocity.x) + speed*deltaTime.asSeconds();
            velocity.x *= 1.2f;
            std::cout<<velocity.x;
        }


        circle.move(velocity * deltaTime.asSeconds());
        window.clear();

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        window.draw(circle);
        window.display();
        deltaTime = clock.getElapsedTime() - previousTime;
        previousTime = clock.getElapsedTime();
    }
}
