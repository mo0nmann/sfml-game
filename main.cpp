#include <SFML/Graphics.hpp>
#include <iostream>
#include "Header_Files/Player.h"

// Function to maintain Aspect Ration upon Window Resize
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}


int main()
{
    // Render Window to full Size of Desktop
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");

    int window_width = window.getSize().x;
    int window_height = window.getSize().y;

    // Creating a view for resize handling
    sf::View view;
    view.setSize(window_width, window_height);
    view.setCenter(window_width / 2, window_height / 2);
    view = getLetterboxView( view, window_width, window_height );
    
    // Create and Set Background Texture Image
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("images/BG.png")) {
        std::cerr << "Load Failed" << std::endl;

        system("pause");
    }

    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);

    // Create and Set Ground Texture Image
    sf::Texture ground_texture;
    if (!ground_texture.loadFromFile("images/Tiles/Tile_2.png")) {
        std::cerr << "Load Failed" << std::endl;

        system("pause");
    }

    // Repeat Ground Texture
    ground_texture.setRepeated(true);   

    // Create & initialise sprite with ground texture
    sf::Sprite ground_sprite;
    ground_sprite.setTexture(ground_texture);

    // Set Texture Rect to be height of ground sprite and width of screen
    ground_sprite.setTextureRect(sf::IntRect(0, 0, window_width, ground_sprite.getGlobalBounds().height));

    // Put sprite at bottom of screen
    ground_sprite.setPosition(0, window_height - ground_sprite.getGlobalBounds().height);

    // ALlows for holding down of keys
    window.setKeyRepeatEnabled(true);

    // Create Player
    Player player("images/Player/Idle_1.png");

    // Set Player Position to be just above ground sprite
    player.setPlayerPosition(0, window_height - ground_sprite.getGlobalBounds().height * 1.85);


    // While Window is open
    while (window.isOpen())
    {
        // Create Event
        sf::Event event;

        // Polling for Event
        while (window.pollEvent(event))
        {   
            // If user closes window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // If user resizes window
            if (event.type == sf::Event::Resized) {
                view = getLetterboxView( view, event.size.width, event.size.height);
            }

            // If user moves player

            // Move up
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.movePlayer('u', 6.0);

            // Move left
            } if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.movePlayer('l', 6.0);

            // Move right
            } if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.movePlayer('r', 6.0);
            }
        }

        window.clear();

        window.setView(view);

        // Draw
        window.draw(background_sprite);
        window.draw(ground_sprite);
        
        player.drawPlayer(window);

        window.display();
    }

    return 0;
}