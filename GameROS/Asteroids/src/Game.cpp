//
// Created by mark on 16/05/18.
//
#include "../lib/Game.h"


Game *Game::getInstance()
{
  if (!instance_)
  {
    instance_ = (Game *)new Game();
  }
  return instance_;
}

Game::Game() : W(1200), H(800)
{
  app = new sf::RenderWindow(sf::VideoMode(W, H), "Asteroids!");
  entities = new std::list<class Entity *>;
}
