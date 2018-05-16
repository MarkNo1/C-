//
// Created by mark on 16/05/18.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include <list>
#include "Entity.h"
#include <SFML/Graphics.hpp>


class Game
{
public:
    static Game *getInstance();
    int getWidth();
    int getHeight();
    sf::RenderWindow *getApp();
    std::list<class Entity *> *getEntities();

private:
    //static std::unique_ptr<Game> instance_;
    static Game *instance_;
    Game();
    const int W;
    const int H;
    sf::RenderWindow *app;
    std::list<class Entity *> *entities;
};

#endif //ASTEROIDS_GAME_H
