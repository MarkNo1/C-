#ifndef _CLASSES_H
#define _CLASSES_H

#include <memory>
#include "global.h"
#include <list>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Entity.h"
#include "Player.h"


class coolDownAnimation
{
public:
  float x, y;
  Animation anim;

  coolDownAnimation(float, float);
  void set_animation(Animation &a);
  void update();
  void draw(sf::RenderWindow &app);
};

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

#endif
