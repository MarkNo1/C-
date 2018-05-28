#ifndef _CLASSES_CPP
#define _CLASSES_CPP

#include "../lib/classes.h"

#include "iostream"

using namespace std;

Game *Game::instance_ = NULL;;;;

coolDownAnimation::coolDownAnimation(float x, float y)
{
  this->x = x;
  this->y = y;
}

void coolDownAnimation::update()
{
  anim.sprite.setPosition(x, y);

  int coolDown = static_cast<Player *>(Game::getInstance()->getEntities()->front())->bombCoolDown;
  int backwardsIndex = coolDown * (float)NR_OF_CD_FRAMES / (float)FULL_COOLDOWN;
  int spriteNr = std::max(0, NR_OF_CD_FRAMES - 1 - backwardsIndex);
  anim.sprite.setTextureRect(anim.frames[spriteNr]);
}

void coolDownAnimation::set_animation(Animation &a)
{
  anim = a;
}

void coolDownAnimation::draw(sf::RenderWindow &app)
{
  anim.sprite.setPosition(this->x, this->y);
  app.draw(anim.sprite);
}

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
  cout << "GAME CONSTRUCTER CALLED!!!!!!!!!!!!!!!" << endl;
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

#endif
