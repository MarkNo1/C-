//
// Created by mark on 16/05/18.
//

#include "../lib/Asteroid.h"

Asteroid::Asteroid()
{
  //do {
  dx = rand() % 8 - 4;
  dy = rand() % 8 - 4;
  //} while (dx == 0 && dy == 0);

  name = "Asteroid";
}

void Asteroid::update()
{
  x += dx;
  y += dy;

  if (x > width)
    x = 0;
  if (x < 0)
    x = width;
  if (y > height)
    y = 0;
  if (y < 0)
    y = height;
}