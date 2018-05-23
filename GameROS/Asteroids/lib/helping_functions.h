#ifndef HELPING_FUNCTIONS_H
#define HELPING_FUNCTIONS_H

//#include "classes.h"
#include "Animation.h"
#include "AnimationCoolDown.h"
#include "Asteroid.h"
#include "Bomb.h"
#include "Bullet.h"
#include "Player.h"
#include "Entity.h"


void randomlySpawnAsteroid(Animation, Animation);
void removeFinishedExplosions();
void updateEntitiesAndDeleteTheDead();

void drawEverythingOn(sf::Sprite background, AnimationCoolDown *c);
bool isCollide(Entity *a, Entity *b);
void spawnAsteroids(int number, Animation sRock);

#endif
