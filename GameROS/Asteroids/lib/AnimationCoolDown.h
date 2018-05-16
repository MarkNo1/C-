//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_ANIMATIONCOOLDOWN_H
#define ASTEROIDS_ANIMATIONCOOLDOWN_H

#include "Animation.h"
#include <SFML/Graphics.hpp>

class AnimationCoolDown
{
public:
    float x, y;
    Animation animation;

    AnimationCoolDown(float x, float y);
    void set_animation(Animation &a);
    void update();
    void draw(sf::RenderWindow &app);
};


#endif //ASTEROIDS_ANIMATIONCOOLDOWN_H
