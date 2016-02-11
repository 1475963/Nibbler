//
// Food.cpp for Food in /home/benzah_m/rendu/cpp_nibbler/trash
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Tue Mar 18 02:47:32 2014 benzah_m
// Last update Sun Apr  6 21:57:20 2014 benzah_m
//

#include "Food.hpp"

Food::Food(const Snake &snake, bool state) 
{
  std::list<Maillon *>			*snakeList = snake.getSnake();
  std::list<Maillon *>::iterator	itSnake = snakeList->begin();
  std::list<Food *>			*foodList = snake.getFood();
  std::list<Food *>::iterator		itFood = foodList->begin();
  std::list<Walls *>			*wallList = snake.getWalls();
  std::list<Walls *>::iterator		itWalls = wallList->begin();

  std::srand(std::time(NULL));
  this->setX((std::rand() % (snake.getX() - 2)) + 1);
  this->setY((std::rand() % (snake.getY() - 2)) + 1);

  /*** check if the food spawned on the snake ***/
  while (itSnake != snakeList->end())
    {
      if (this->getX() == (*itSnake)->getX() && this->getY() == (*itSnake)->getY())
	{
	  while (this->getX() == (*itSnake)->getX())
	    this->setX((std::rand() % (snake.getX() - 2)) + 1);
	  while (this->getY() == (*itSnake)->getY())
	    this->setY((std::rand() % (snake.getY() - 2)) + 1);
	  itSnake = snakeList->begin();
	}
      ++itSnake;
    }

  /*** check if the food spawned on another food ***/
  while (itFood != foodList->end())
    {
      while (itWalls != wallList->end())
	{
	  if ((*itWalls)->check_pos(this->getX(), this->getY(), (*itWalls)) == true)
	    {
	      this->setX((std::rand() % (snake.getX() - 2)) + 1);
	      this->setY((std::rand() % (snake.getY() - 2)) + 1);
	      itFood = foodList->begin();
	    }
	  itWalls++;
	}
      if (this->getX() == (*itFood)->getX() && this->getY() == (*itFood)->getY())
	{
	  while (this->getX() == (*itFood)->getX())
	    this->setX((std::rand() % (snake.getX() - 2)) + 1);
	  while (this->getY() == (*itFood)->getY())
	    this->setY((std::rand() % (snake.getY() - 2)) + 1);
	  itWalls = wallList->begin();
	}
      ++itFood;
    }

  if (state)
    this->_delay = clock();
  this->setSpecial(state);

  if (state)
    this->setScore(SPECIAL_SCORE);
  else
    this->setScore(DEFAULT_SCORE);
}

Food::Food(const Food &food) 
{
  if (this != &food)
    {
      this->setX(food.getX());
      this->setY(food.getY());
      this->setScore(food.getScore());
      this->setSpecial(food.getSpecial());
    }
}

Food::~Food(void) {
}

Food	&Food::operator=(const Food &food) {
  if (this != &food)
    {
      this->setX(food.getX());
      this->setY(food.getY());
      this->setScore(food.getScore());
      this->setSpecial(food.getSpecial());
    }
  return (*this);
}

void	Food::setX(int x) {
  this->_x = x;
}

int	Food::getX(void) const {
  return (this->_x);
}

void	Food::setY(int y) {
  this->_y = y;
}

int	Food::getY(void) const {
  return (this->_y);
}

void	Food::setScore(int score) {
  this->_score = score;
}

int	Food::getScore(void) const {
  return (this->_score);
}

void	Food::setSpecial(bool state) {
  this->_special = state;
}

bool	Food::getSpecial(void) const {
  return (this->_special);
}

int	Food::getDelay() const
{
  return (this->_delay);
}

/* Set the timer on the special food so it diseapear after a short time */

int	Food::check_ftimer()
{
  int	ntime;

  ntime = clock();
  if (ntime - this->getDelay() >= 200000)
    return (-1);
  return (0);
}
