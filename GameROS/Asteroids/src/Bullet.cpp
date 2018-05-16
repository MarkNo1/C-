//
// Created by mark on 16/05/18.
//

#include "../lib/Bullet.h"
#include "../lib/global.h"

Bullet::Bullet(int W, int H): width(W), height(H)
{
  name = "Bullet";

}

void Bullet::update()
{
  dx = cos(angle * DEGTORAD) * 6;
  dy = sin(angle * DEGTORAD) * 6;
  x += dx;
  y += dy;

  if (x > width || x < 0 ||
      y > height || y < 0)
    life = 0;
}