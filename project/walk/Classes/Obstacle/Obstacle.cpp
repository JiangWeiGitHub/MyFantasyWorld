#include "./Obstacle.h"

Obstacle::Obstacle()
{
  obstacle_top = false;
  obstacle_bottom = false;
  obstacle_left = false;
  obstacle_right = false;
}

Obstacle::~Obstacle()
{
  obstacle_top = false;
  obstacle_bottom = false;
  obstacle_left = false;
  obstacle_right = false;
}

Obstacle* Obstacle::instance = new Obstacle();
Obstacle* Obstacle::getInstance()
{
	return instance;
}