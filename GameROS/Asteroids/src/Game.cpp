//
// Created by mark on 16/05/18.
//
#include "../lib/Game.h"
#include <SFML/Graphics.hpp>


Game *Game::instance_ = NULL;


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

std::list<Entity *> *Game::getEntities()
{
  return entities;
}

sf::RenderWindow *Game::getApp()
{
  return app;
}

int Game::getWidth()
{
  return W;
}

int Game::getHeight()
{
  return H;
}