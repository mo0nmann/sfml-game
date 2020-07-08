#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>

class Player {
    public:

        Player();

        Player(std::string);

        void drawPlayer(sf::RenderWindow&);

        void movePlayer(char, float);

        void setPlayerPosition(float, float);

    private:
        sf::Texture player_texture;
        sf::Sprite player_sprite;
};

#endif /* _PLAYER_H */