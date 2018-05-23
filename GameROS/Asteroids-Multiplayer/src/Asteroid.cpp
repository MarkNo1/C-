//
// Created by jrebocho on 23/05/18.
//

#include "../lib/classes.h"
#include "../lib/Asteroid.h"

Asteroid::Asteroid()
{
  //do {
  Entity::dx = rand() % 8 - 4;
  Entity::dy = rand() % 8 - 4;
  //} while (dx == 0 && dy == 0);

  Entity::name = "asteroid";
}

void Asteroid::update()
{
  Entity::x += Entity::dx;
  Entity::y += Entity::dy;

  int W = Game::getInstance()->getWidth();
  int H = Game::getInstance()->getHeight();

  if (Entity::x > W)
    Entity::x = 0;
  if (Entity::x < 0)
    Entity::x = W;
  if (Entity::y > H)
    Entity::y = 0;
  if (Entity::y < 0)
    Entity::y = H;
}