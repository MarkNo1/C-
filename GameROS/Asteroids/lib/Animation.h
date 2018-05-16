//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_ANIMATION_H
#define ASTEROIDS_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>



class Animation
{
public:
    float frameNumber, speed;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;

    Animation();
    Animation(sf::Texture &t, int x, int y, int w, int h, int count, float speed);
    virtual void update();
    bool isEnd();
};


#endif //ASTEROIDS_ANIMATION_H
