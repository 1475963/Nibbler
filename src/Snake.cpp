//
// Snake.cpp for snake in /home/benzah_m/rendu/cpp_nibbler
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Tue Apr  1 13:51:34 2014 dequid_v
// Last update Sun Apr  6 23:02:56 2014 dequid_v
//

#include <fstream>
#include <time.h>
#include <sstream>
#include "Walls.hpp"
#include "Snake.hpp"

Snake::Snake(int x, int y)
{
  this->setX(x);
  this->setY(y);
  this->setDirection(DEFAULT_DIR);
  this->setScore(START_SCORE);
  this->setSnake(new std::list<Maillon *>());
  this->setFood(new std::list<Food *>());
  this->setWalls(new std::list<Walls *>());
  x /= 2;
  y /= 2;
  for (int i = 0; i < DEFAULT_SNAKE_SIZE; x++, i++)
    this->getSnake()->push_back(new Maillon(x, y));
  this->_delay = clock();
  this->_speed = 120;
  this->setOldSpeed(120);
  this->_energy = 100;
  this->setSpeedUp(false);
  this->getFood()->push_back(new Food(*this, false));
  this->setEnd(false);
  this->lock = 0;
}

Snake::Snake(Snake const &s)
{
  if (this != &s)
    {
      this->setX(s.getX());
      this->setY(s.getY());
      this->setDirection(s.getDirection());
      this->setScore(s.getScore());
      this->setSnake(s.getSnake());
      this->setFood(s.getFood());
      this->setEnd(s.getEnd());
    }
}

Snake::~Snake(void)
{
  this->getSnake()->clear();
}

Snake			&Snake::operator=(Snake const &s)
{
  if (this != &s)
    {
      this->setX(s.getX());
      this->setY(s.getY());
      this->setDirection(s.getDirection());
      this->setScore(s.getScore());
      this->setSnake(s.getSnake());
      this->setFood(s.getFood());
      this->setEnd(s.getEnd());
    }
  return (*this);
}

void			Snake::setX(int x)
{
  this->_x = x;
}

int			Snake::getX(void) const {
  return (this->_x);
}

void			Snake::setY(int y) {
  this->_y = y;
}

int			Snake::getY(void) const {
  return (this->_y);
}

void			Snake::setDirection(eDirection dir)
{
  this->_d = dir;
}

eDirection		Snake::getDirection(void) const {
  return (this->_d);
}

void			Snake::setScore(int score) {
  this->_score = score;
}

int			Snake::getScore(void) const {
  return (this->_score);
}

void			Snake::setSnake(std::list<Maillon *> *snake)
{
  this->_snake = snake;
}

std::list<Maillon *>	*Snake::getSnake(void) const {
  return (this->_snake);
}

void			Snake::setFood(std::list<Food *> *food) {
  this->_food = food;
}

void			Snake::setWalls(std::list<Walls *> *_walls) 
{
  this->walls = _walls;
}

std::list<Walls *>	*Snake::getWalls(void) const 
{
  return (this->walls);
}

std::list<Food *>	*Snake::getFood(void) const {
  return (this->_food);
}

int			Snake::getSpeed() const
{
  return (this->_speed);
}

void			Snake::setSpeed(int speed)
{
  this->_speed = speed;
}

int			Snake::getDelay() const
{
  return (this->_delay);
}

void			Snake::setOldSpeed(int speed)
{
  this->_oldSpeed = speed;
}

int			Snake::getOldSpeed() const
{
  return (this->_oldSpeed);
}

void			Snake::setDelay(int delay)
{
  this->_delay = delay;
}

void			Snake::setEnergy(int energy)
{
  if (energy > 100)
    this->_energy = 100;
  else
    this->_energy = energy;
}

int			Snake::getLock() const
{
  return (this->lock);
}

void			Snake::setLock(int _lock)
{
  this->lock = _lock;
}

int			Snake::getEnergy() const
{
  return (this->_energy);
}

void			Snake::setSpeedUp(bool su) {
  this->_speedup = su;
}

bool			Snake::getSpeedUp(void) const {
  return (this->_speedup);
}

void			Snake::setEnd(bool state) {
  this->_end = state;
}

bool			Snake::getEnd(void) const {
  return (this->_end);
}

/* Temporarly increase snake's speed */

int			Snake::speedBoost(int lock)
{
  static	int k = 0;

  if (lock == -1)
    {
      if (this->getOldSpeed() / 2 >= this->getSpeed())
	this->setSpeed(this->getOldSpeed());
      k = 0;
    }
  else if (this->getEnergy() > 1)
    {
      if (k == 0)
	{
	  this->setOldSpeed(this->getSpeed());
	  if (this->getSpeed() > 40)
	    this->setSpeed(this->getSpeed() / 2);
	  k++;
	}
      this->setEnergy(this->getEnergy() - 2);
    }
  else
    this->setSpeedUp(false);
  return (0);
}

/* Increase speed over the time */

int			Snake::increase_speed()
{
  int			ntime;
  std::list<Food *> 	*list = this->getFood();
  std::list<Food *>::iterator	it = list->begin();
  int			count = 0;

  while (it != list->end() && count == 0)
    {
      if ((*it)->getSpecial() == true && (*it)->check_ftimer() == -1)
	{
	  list->remove(*it);
	  count = 1;
	}
      else
	it++;
    }
  ntime = clock();
  if (ntime - this->getDelay() >= 200000 && this->getSpeed() > 40)
    {
      this->setSpeed(this->getSpeed() - 2);
      this->setDelay(ntime);
    }
  return (0);
}

/* Set snake's new direction according to the key pressed */

int			Snake::moveSnake(eKey key)
{
  eDirection		dir = this->getDirection();

  if (this->getLock() != 0)
    return (-1);
  if ((dir == SOUTH && (key == RIGHT || key == Q)) || (dir == NORTH && (key == LEFT || key == Q)))
    this->setDirection(WEST);
  else if ((dir == SOUTH && (key == LEFT || key == D)) || (dir == NORTH && (key == RIGHT || key == D)))
    this->setDirection(EAST);
  else if ((dir == WEST && (key == RIGHT || key == Z)) || (dir == EAST && (key == Z || key == LEFT)))
    this->setDirection(NORTH);
  else if ((dir == WEST && (key == LEFT || key == S)) || (dir == EAST && (key == RIGHT || key == S)))
    this->setDirection(SOUTH);
  this->setLock(1);
  return (0);
}

/* BONUS: allow the player to have the best score */

int					Snake::checkScore() const
{
  std::ifstream	sfile;
  std::string	value;
  std::stringstream	scr;
  int res = 0;
  int	pos1, pos2 = 0;

  sfile.open(".score.txt", std::ios::out | std::ios::in);
  if (sfile)
    {
      std::string line;
      getline(sfile, line);
      pos1 = line.find_first_of(' ');
      pos2 = line.find_first_of(';');
      value = line.substr(pos1, pos2 - pos1);
      scr << value;
      scr >> res;
      if (res < this->getScore())
	{
	  std::cout << "Vous avez fait le meilleur score ! Rentrez donc dans le panthéon ! Quel est votre pseudo ?" << std::endl;
	  std::cin >> line;
	  std::ofstream fichier(".score.txt", std::ios::out | std::ios::trunc);
	  fichier << line << " " << this->getScore() << ";" << std::endl;
	}
    }
  return (0);
}

std::string  		Snake::getBestScore()
{
  std::ifstream	sfile;
  std::string line;

  sfile.open(".score.txt", std::ios::out | std::ios::in); 
  if (sfile)
    getline(sfile, line);
  sfile.close();
  return (line);
}

/* BONUS: set random walls in the map if activaded through the menu */

int					Snake::addRandomWalls()
{
  int	nb_walls = std::rand() % 11;
  int	k = 0;
  std::list<Walls *>	*list= this->getWalls();
  eDirection dir;
  int	len;
  int	r;

  while (k != nb_walls)
    {
      len = std::rand() % 10;
      r = std::rand() % 4;
      if (r == 1)
	dir = SOUTH;
      else if (r == 2)
	dir = NORTH;
      else if (r == 3)
	dir = EAST;
      else if (r == 4)
	dir = WEST;
      list->push_back(new Walls(*this, dir, len));
      k++;
    }
 return (0);
}

/* BONUS: Delete all random walls */

int		Snake::deleteRandWalls()
{
  std::list<Walls *>	*list = this->getWalls();
  
  list->clear();
  return (0);
}

/* Check if the snake hits a random wall */

int					Snake::check_wall_hits()
{
  std::list<Walls *>	*list = this->getWalls();
  std::list<Walls *>::iterator		itWalls = list->begin();
  int	k = 0;
  std::list<Maillon *>			*liste = this->getSnake();
  std::list<Maillon *>::iterator	head = liste->begin();

  while (itWalls != list->end())
    {
      int	x = (*itWalls)->getX();
      int	y = (*itWalls)->getY();
      while (k != (*itWalls)->getLength())
	{
	  if ((*head)->getX() == x && (*head)->getY() == y)
	    return (-1);
	  if ((*itWalls)->getDir() == SOUTH)
	    y++;
	  else if ((*itWalls)->getDir() == NORTH)
	    y--;
	  else if ((*itWalls)->getDir() == WEST)
	    x--;
	  else if ((*itWalls)->getDir() == EAST)
	    x++; 
	  k++;
	}
      k = 0;
      itWalls++;
    }
  return (0);
}

/* Main function of the file: move the snake, eat the food and check if a side wall was hit */

int					Snake::forward(int c)
{
  eDirection				dir = this->getDirection();
  std::list<Maillon *>			*list = this->getSnake();
  std::list<Food *>			*listFood = this->getFood();
  std::list<Maillon *>::iterator	head = list->begin(), it = list->begin();
  std::list<Food *>::iterator		itFood = listFood->begin();

  if (this->getEnd() == true)
    return (-1);

  /*** Add Food ***/
  if (c == -1)
    this->setEnd(true);
  else if (c == 1)
    listFood->push_back(new Food(*this, true));

  /*** Hit Snake ***/
  while (++it != list->end())
    {
      if ((*head)->getX() == (*it)->getX() && (*head)->getY() == (*it)->getY())
	return (-1);
    }

  /*** Hit Food ***/
  while (itFood != listFood->end())
    {
      if ((*head)->getX() == (*itFood)->getX() && (*head)->getY() == (*itFood)->getY())
	{
	  if ((*itFood)->getSpecial() == true)
	    {
	      this->setEnergy(this->getEnergy() + 30);
	      this->addTail();
	    }
	  else
	    {
	      this->setEnergy(this->getEnergy() + 10);
	      listFood->push_back(new Food(*this, false));
	    }
	  this->addTail();
	  this->setScore(this->getScore() + (*itFood)->getScore());
	  listFood->remove(*itFood);
	  break;
	}
      ++itFood;
    }

  /*** Hit Walls ***/
  if ((*head)->getX() >= this->getX() || (*head)->getY() >= this->getY()
      || (*head)->getX() < 1 || (*head)->getY() < 1)
    return (-1);

  /*** Hit Walls according to the direction ***/
  if (check_wall_hits() == -1)
    return (-1);
  if (dir == SOUTH && (*head)->getY() + 1 == this->getY() - 1)
    return (-1);
  else if (dir == NORTH && (*head)->getY() - 1 == 0)
    return (-1);
  else if (dir == EAST && (*head)->getX() + 1 == this->getX() - 1)
    return (-1);
  else if (dir == WEST && (*head)->getX() - 1 == 0)
    return (-1);

  /*** Move one case to the direction ***/
  if (dir == SOUTH)
    (*head)->swapValues((*head)->getX(), (*head)->getY() + 1);
  else if (dir == NORTH)
    (*head)->swapValues((*head)->getX(), (*head)->getY() - 1);
  else if (dir == EAST)
    (*head)->swapValues((*head)->getX() + 1, (*head)->getY());
  else if (dir == WEST)
    (*head)->swapValues((*head)->getX() - 1, (*head)->getY());
  (*head)->swapListValues(list);
  this->setLock(0);
  return (0);
}

/* Increase the length of the snake by adding a maillon to the tail */

void					Snake::addTail(void)
{
  std::list<Maillon *>			*list = this->getSnake();
  std::list<Maillon *>::iterator	it = list->begin();

  while (++it != list->end());
  --it;
  list->push_back(new Maillon((*it)->getOldX(), (*it)->getOldY()));
}
