//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
public:
    Asteroid(int W, int H);
    void update();
private:
    int width;
    int height;
};




#endif //ASTEROIDS_ASTEROID_H
