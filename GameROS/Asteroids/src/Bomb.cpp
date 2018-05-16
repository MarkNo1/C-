//
// Created by mark on 16/05/18.
//

#include "../lib/Bomb.h"


Bomb::Bomb()
{
  name = "Bomb";
}

void Bomb::update()
{
  R += 10;
}