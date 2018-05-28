//
// Created by jrebocho on 23/05/18.
//

#ifndef ASTEROIDS_MULTIPLAYER_PLAYER_H
#define ASTEROIDS_MULTIPLAYER_PLAYER_H


#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "classes.h"

class Player : public Entity
{
public:
  bool thrust;
  bool brake;
  std::__cxx11::string tilting;
  int bombCoolDown;

  Player();
  void update();
};

#endif //ASTEROIDS_MULTIPLAYER_PLAYER_H
