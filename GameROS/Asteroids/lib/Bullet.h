//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "Entity.h"
#include "Game.h"

class Bullet : public Entity
{
public:
    Bullet(int W, int H);
    void update();
private:
    int width;
    int height;
};



#endif //ASTEROIDS_BULLET_H
