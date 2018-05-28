//
// Created by jrebocho on 28/05/18.
//

#ifndef ASTEROIDS_MULTIPLAYER_ENTITY_H
#define ASTEROIDS_MULTIPLAYER_ENTITY_H


#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include "Animation.h"


class Entity
{
public:
  float x, y, dx, dy, R, angle;
  bool life;
  std::__cxx11::string name;
  Animation anim;

  Entity();
  void set_state(int X, int Y, float Angle = 0, int radius = 1);
  void set_animation(Animation &a);
  virtual void update();
  void draw(sf::RenderWindow &app);
  virtual ~Entity();
};

#endif //ASTEROIDS_MULTIPLAYER_ENTITY_H
