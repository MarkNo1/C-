//
// Created by jrebocho on 28/05/18.
//

#ifndef ASTEROIDS_MULTIPLAYER_ANIMATION_H
#define ASTEROIDS_MULTIPLAYER_ANIMATION_H


#include <memory>
#include <list>
#include <SFML/Graphics.hpp>



class Animation
{
public:
  float frameNumber, speed;
  sf::Sprite sprite;
  std::vector<sf::IntRect> frames;

  Animation();
  Animation(sf::Texture &t, int x, int y, int w, int h, int count, float speed);
  virtual void update();
  bool isEnd();
};


#endif //ASTEROIDS_MULTIPLAYER_ANIMATION_H
