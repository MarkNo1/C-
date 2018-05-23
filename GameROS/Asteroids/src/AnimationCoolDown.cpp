//
// Created by mark on 16/05/18.
//

#include "../lib/AnimationCoolDown.h"
#include "../lib/Player.h"
#include "../lib/Game.h"
#include "../lib/global.h"

AnimationCoolDown::AnimationCoolDown(float x, float y)
{
  this->x = x;
  this->y = y;
}



void AnimationCoolDown::update()
{
  animation.sprite.setPosition(x, y);

  int coolDown = static_cast<Player *>(Game::getInstance()->getEntities()->front())->bombCoolDown;
  int backwardsIndex = coolDown * (float)NR_OF_CD_FRAMES / (float)FULL_COOLDOWN;
  int spriteNr = std::max(0, NR_OF_CD_FRAMES - 1 - backwardsIndex);
  animation.sprite.setTextureRect(animation.frames[spriteNr]);
}

void AnimationCoolDown::set_animation(Animation &a)
{
  animation = a;
}

void AnimationCoolDown::draw(sf::RenderWindow &app)
{
  animation.sprite.setPosition(this->x, this->y);
  app.draw(animation.sprite);
}

