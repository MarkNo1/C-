//
// Created by jrebocho on 28/05/18.
//

#include "../lib/classes.h"
#include "../lib/Entity.h"

Entity::Entity()
{
  life = 1;
}

void Entity::set_state(int X, int Y, float Angle, int radius)
{
  x = X;
  y = Y;
  angle = Angle;
  R = radius;
}

void Entity::set_animation(Animation &a)
{
  anim = a;
}

void Entity::update(){}

void Entity::draw(sf::RenderWindow &app)
{
  anim.sprite.setPosition(x, y);
  anim.sprite.setRotation(angle + 90);
  app.draw(anim.sprite);

  sf::CircleShape circle(R);
  circle.setFillColor(sf::Color(255, 0, 0, 170));
  circle.setPosition(x, y);
  circle.setOrigin(R, R);
  //app.draw(circle);
}

Entity::~Entity(){}