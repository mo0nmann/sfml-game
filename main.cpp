#include <SFML/Graphics.hpp>

int main()
{
    // Render Window to full Size of Desktop
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");

    // Create circle
    sf::CircleShape circle(100.f);

    // Fill Circle (Pink)
    circle.setFillColor(sf::Color(247, 175, 247));

    // Set Origin of Circle to it's centre
    circle.setOrigin(circle.getRadius(), circle.getRadius());

    // Set Position of Circle to centre of Window
    circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // While Window is open
    while (window.isOpen())
    {
        // Create Event
        sf::Event event;

        // Polling for Event
        while (window.pollEvent(event))
        {   
            // If user closes window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}