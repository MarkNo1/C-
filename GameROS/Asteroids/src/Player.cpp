//
// Created by mark on 16/05/18.
//

#include "../lib/Player.h"
#include "../lib/global.h"
#include "../lib/Game.h"

Player::Player()
{
  name = "Player";
  tilting = "nope";
  bombCoolDown = 0;

}

void Player::update()
{
  if (bombCoolDown > 0)
    bombCoolDown -= 1;

  if (bulletCoolDown > 0)                                                 //ADDED
    bulletCoolDown -= 1;                                                  //ADDED


  if (thrust)
  {
    dx += cos(angle * DEGTORAD) * 0.2;
    dy += sin(angle * DEGTORAD) * 0.2;
  }
  else if (brake)
  {
    dx *= 0.95;
    dy *= 0.95;
  }
  else
  {
    dx *= 0.99;
    dy *= 0.99;
  }

  //sprite.setTextureRect(frames[(int)frameNumber]);

  int maxSpeed = 15;
  float speed = sqrt(dx * dx + dy * dy);
  if (speed > maxSpeed)
  {
    dx *= maxSpeed / speed;
    dy *= maxSpeed / speed;
  }

  x += dx;
  y += dy;

  int W = Game::getInstance()->getWidth();
  int H = Game::getInstance()->getHeight();

  if (x > W)
    x = 0;
  if (x < 0)
    x = W;
  if (y > H)
    y = 0;
  if (y < 0)
    y = H;
}