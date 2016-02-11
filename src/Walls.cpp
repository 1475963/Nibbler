//
// Walls.cpp for snake in /home/dequid_v/rendu/snake/cpp_nibbler
// 
// Made by dequid_v
// Login   <dequid_v@epitech.net>
// 
// Started on  Fri Apr  4 17:06:52 2014 dequid_v
// Last update Sun Apr  6 17:26:55 2014 dequid_v
//

#include "Walls.hpp"
#include "Key.hpp"
#include <stdio.h>

Walls::Walls(const Snake &snake, eDirection dir, int len)
{
  std::list<Maillon *>			*snakeList = snake.getSnake();
  std::list<Maillon *>::iterator	itSnake = snakeList->begin();
  std::list<Food *>			*FoodList = snake.getFood();
  std::list<Food *>::iterator		itFood = FoodList->begin();
  int	k = 0;
  bool good = true;
  int x = (std::rand() % (snake.getX() - 2)) + 1;
  int y = (std::rand() % (snake.getY() - 2)) + 1;

  while (k != len || good != true)
    {
      if (x > snake.getX() || y > snake.getY())
	good = false;
      if (k == len || good == false)
	{
	  x = (std::rand() % (snake.getX() - 2)) + 1;
	  y = (std::rand() % (snake.getY() - 2)) + 1;
	  good = true;
	}
      /*** check if the wall spawned on the snake ***/
      while (itSnake != snakeList->end())
	{
	  if (x == (*itSnake)->getX() && y == (*itSnake)->getY())
	    {
	      good = false;
	      break ;
	    }
	  ++itSnake;
	}
      /*** check if the wall spawned on another Food ***/
      while (itFood != FoodList->end())
	{
	  if (x == (*itFood)->getX() && y == (*itFood)->getY())
	    {
	      good = false;
	      break ;
	    }
	  ++itFood;
	}
      if (dir == SOUTH)
	y++;
      else if (dir == NORTH)
	y--;
      else if (dir == WEST)
	x--;
      else if (dir == EAST)
	x++;
      k++;
    }
  this->setDir(dir);
  this->setX(x);
  this->setY(y);
  this->setLength(len);
}

Walls::Walls(const Walls &w) 
{
  if (this != &w)
    {
      this->setDir(w.getDir());
      this->setX(w.getX());
      this->setY(w.getY());
      this->setLength(w.getLength());
    }
}

Walls::~Walls(void) 
{
}

Walls	&Walls::operator=(const Walls &w) 
{
  if (this != &w)
    {
      this->setDir(w.getDir());
      this->setX(w.getX());
      this->setY(w.getY());
      this->setLength(w.getLength());
    }
  return (*this);
}

int	 Walls::getY(void) const
{
  return (this->y);
}

void	Walls::setY(int _y)
{
  this->y = _y;
}

int	 Walls::getX(void) const
{
  return (this->x);
}

void	Walls::setX(int _x)
{
  this->x = _x;
}

eDirection Walls::getDir(void) const
{
  return (this->dir);
}

void	Walls::setDir(eDirection d)
{
  this->dir = d;
}

int	Walls::getLength(void) const
{
  return (this->length);
}

void	Walls::setLength(int l)
{
  this->length = l;
}

/* check if something was meant to spawn on a random wall */

bool	Walls::check_pos(int x, int y, const Walls *w)
{
  int	k = 0;
  int	_x = w->getX();
  int	_y = w->getY();

  while (k != w->getLength())
    {
      if (_x == x || _y == y)
	return (true);
      if (dir == SOUTH)
	_y++;
      else if (dir == NORTH)
	_y--;
      else if (dir == WEST)
	_x--;
      else if (dir == EAST)
	x++;
      k++;
    }
  return (false);
}
