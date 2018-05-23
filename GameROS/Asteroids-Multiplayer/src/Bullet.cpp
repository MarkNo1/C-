//
// Created by jrebocho on 23/05/18.
//

#include <tgmath.h>
#include "../lib/Bullet.h"

Bullet::Bullet()
{
  Entity::name = "bullet";
}

void Bullet::update()
{
  Entity::dx = cos(Entity::angle * DEGTORAD) * 6;
  Entity::dy = sin(Entity::angle * DEGTORAD) * 6;
  Entity::x += Entity::dx;
  Entity::y += Entity::dy;

  if (Entity::x > Game::getInstance()->getWidth() || Entity::x < 0 ||
      Entity::y > Game::getInstance()->getHeight() || Entity::y < 0)
    Entity::life = 0;
}