#include "./Obstacle.h"

Obstacle::Obstacle()
{
  obstacle_top = false;
  obstacle_bottom = false;
  obstacle_left = false;
  obstacle_right = false;

  exc = NONE;
}

Obstacle::~Obstacle()
{
  obstacle_top = false;
  obstacle_bottom = false;
  obstacle_left = false;
  obstacle_right = false;
  
  exc = NONE;
}

Obstacle* Obstacle::instance = new Obstacle();
Obstacle* Obstacle::getInstance()
{
  return instance;
}
