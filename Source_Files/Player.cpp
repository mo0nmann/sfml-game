// #include <Header_Files/Player.h>
#include "../Header_Files/Player.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

// Default Constructor
Player::Player() {}

// Constructor via image
Player::Player(std::string image_directory) {

    // Load Texture
    if (!player_texture.loadFromFile(image_directory)) {
        std::cerr << "Error Loading Player Sprite" << std::endl;
    }

    // Set Texture
    player_sprite.setTexture(player_texture);

    // Scale down. (Probably should use a smaller texture image later)
    player_sprite.scale(0.15, 0.15);
}

// Draw Player
void Player::drawPlayer(sf::RenderWindow &window) {
    window.draw(player_sprite);
}

// Move Player
void Player::movePlayer(char direction, float move_speed) {
    // Move Up
    if (direction == 'u') {
        player_sprite.move(0, -move_speed);

    // Move Left
    } else if (direction == 'l') {
        player_sprite.move(-move_speed, 0);
    
    // Move Right
    } if (direction == 'r') {
        player_sprite.move(move_speed, 0);
    }
}

// Set Player Position
void Player::setPlayerPosition(float x, float y) {
    player_sprite.setPosition(x, y);
}

