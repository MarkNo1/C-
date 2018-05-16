//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_ENTITY_H
#define ASTEROIDS_ENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Entity
{
public:
    float x, y, dx, dy, R, angle;
    bool life;
    std::string name;
    Animation animation;

    Entity();
    void set_state(int X, int Y, float Angle = 0, int radius = 1);
    void set_animation(Animation &a);
    virtual void update();
    void draw(sf::RenderWindow &app);
    virtual ~Entity();
};


#endif //ASTEROIDS_ENTITY_H
