//
// Created by jrebocho on 23/05/18.
//

#include "../lib/Bomb.h"

bomb::bomb()
{
  name = "bomb";
}

void bomb::update()
{
  R += 10;
}