//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include "Entity.h"
#include "Game.h"

class Player : public Entity
{
public:
    bool thrust;
    bool brake;
    std::string tilting;
    int bombCoolDown;
    int bulletCoolDown;

    Player();
    void update();

private:
    int width;
    int height;
};

#endif //ASTEROIDS_PLAYER_H
