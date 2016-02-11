//
// NCurseImpl.cpp for NCurseImpl in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 14:25:43 2014 benzah_m
// Last update Sun Apr  6 22:01:20 2014 benzah_m
//

#include "NCurseImpl.hpp"

extern "C" AGraph	*load(int x, int y) {
  return (new NCurseImpl(x, y));
}

extern "C" void		unload(AGraph *lib) {
  delete (lib);
}

NCurseImpl::NCurseImpl(int x, int y) : AGraph(x, y) {
  std::cout << "NCURSES" << std::endl;
}

NCurseImpl::NCurseImpl(const NCurseImpl &ncurse) : AGraph(ncurse) {
}

NCurseImpl::~NCurseImpl(void) {
}

NCurseImpl	&NCurseImpl::operator=(const NCurseImpl &ncurse) {
  if (this != &ncurse)
    {
      this->setX(ncurse.getX());
      this->setY(ncurse.getY());
    }
  return (*this);
}

Snake		*NCurseImpl::getSnake(void) const {
  return (this->_snake);
}

void		NCurseImpl::printRandomWalls(void) const {
  std::list<Walls *>		*list = this->getSnake()->getWalls();
  std::list<Walls *>::iterator	it = list->begin();
  int				x = 0, y = 0, k = 0;

  if (wattron(this->win, COLOR_PAIR(1)) == ERR)
    throw ("wattron failed");
  while (it != list->end())
    {
      x = (*it)->getX();
      y = (*it)->getY();
      for (k = 0; k < (*it)->getLength(); k++)
	{
	  if (x < this->getX() - 1 && x > 0 && y < this->getY() - 1 && y > 0)
	    if (mvwprintw(this->win, y, x, " ") == ERR)
	      throw ("mvwprintw failed");
	  if ((*it)->getDir() == SOUTH)
	    y++;
	  else if ((*it)->getDir() == NORTH)
	    y--;
	  else if ((*it)->getDir() == WEST)
	    x--;
	  else if ((*it)->getDir() == EAST)
	    x++;
	}
      it++;
    }
  if (wattroff(this->win, COLOR_PAIR(1)) == ERR)
    throw ("wattroff failed");
}

void		NCurseImpl::do_walls(void) {
  if (wattron(this->win, COLOR_PAIR(1)) == ERR)
    throw ("wattron failed");
  for (int y = 0; y < this->getY(); y++)
    for (int x = 0; x < this->getX(); x++)
      if (y == 0 || y == this->getY() - 1 || x == 0 || x == this->getX() - 1)
	if (mvwprintw(this->win, y, x, " ") == ERR)
	  throw ("mvwprintw failed");
  if (wattroff(this->win, COLOR_PAIR(1)) == ERR)
    throw ("wattron failed");
  this->printRandomWalls();
}

void					NCurseImpl::printFood(void) {
  std::list<Food *>			*list = this->getSnake()->getFood();
  std::list<Food *>::iterator		it = list->begin();

  while (it != list->end())
    {
      if ((*it)->getSpecial() == true)
	{
	  if (wattron(this->win, COLOR_PAIR(2)) == ERR)
	    throw ("wattron failed");
	  if (mvwprintw(this->win, (*it)->getY(), (*it)->getX(), " ") == ERR)
	    throw ("mvwprintw failed");
	  if (wattroff(this->win, COLOR_PAIR(3)) == ERR)
	    throw ("wattroff failed");
	}
      else
	{
	  if (wattron(this->win, COLOR_PAIR(4)) == ERR)
	    throw ("wattron failed");
	  if (mvwprintw(this->win, (*it)->getY(), (*it)->getX(), " ") == ERR)
	    throw ("mvwprintw failed");
	  if (wattroff(this->win, COLOR_PAIR(4)) == ERR)
	    throw ("wattroff failed");
	}
      ++it;
      if (refresh() == ERR)
	throw ("refresh failed");
    }
}

void					NCurseImpl::printSnake(void) {
  std::list<Maillon *>			*Snake = this->getSnake()->getSnake();
  std::list<Maillon *>::iterator	it = Snake->begin();

  if (it != Snake->end())
    {
      if (wattron(this->win, COLOR_PAIR(5)) == ERR)
	throw ("wattron failed");
      if (mvwprintw(this->win, (*it)->getY(), (*it)->getX(), " ") == ERR)
	throw ("mvwprintw failed");
      if (wattroff(this->win, COLOR_PAIR(5)) == ERR)
	throw ("wattroff failed");
      ++it;
    }
  while (it != Snake->end())
    {
      if (wattron(this->win, COLOR_PAIR(3)) == ERR)
	throw ("wattron failed");
      if (mvwprintw(this->win, (*it)->getY(), (*it)->getX(), " ") == ERR)
	throw ("mvwprintw failed");
      if (wattroff(this->win, COLOR_PAIR(3)) == ERR)
	throw ("wattroff failed");
      ++it;
      if (refresh() == ERR)
	throw ("refresh failed");
    }
}

void		NCurseImpl::init(Snake *snake) {
  this->_snake = snake;
  if (initscr() == NULL)
    throw ("initscr failed");
  if ((this->win = newwin(this->getY() + 1, this->getX() + 1, 0, 0)) == NULL)
    throw ("newwin failed");
  if (start_color() == ERR)
    throw ("start_color failed");
  if (init_pair(1, COLOR_WHITE, COLOR_GREEN) == ERR
      || init_pair(2, COLOR_WHITE, COLOR_RED) == ERR
      || init_pair(3, COLOR_WHITE, COLOR_BLUE) == ERR
      || init_pair(4, COLOR_WHITE, COLOR_YELLOW) == ERR
      || init_pair(5, COLOR_WHITE, COLOR_MAGENTA) == ERR)
    throw ("init_pair failed");
  if (curs_set(0) == ERR)
    throw ("curs_set failed");
  raw();
  if (noecho() == ERR)
    throw ("noecho failed");
  if (keypad(this->win, TRUE) == ERR)
    throw ("keypad failed");
  if (nodelay(this->win, true) == ERR)
    throw ("nodelay failed");
}

int		NCurseImpl::display(void) {
  if (wclear(this->win) == ERR)
    throw ("wclear failed");
  this->do_walls();
  this->printFood();
  this->printSnake();
  if (halfdelay(1) == ERR)
    throw ("halfdelay failed");
  return (0);
}

int		NCurseImpl::getEvent(void) {
  int		key = 0;

  key = wgetch(this->win);
  if (key == KEY_UP)
    this->getSnake()->moveSnake(Z);
  else if (key == KEY_DOWN)
    this->getSnake()->moveSnake(S);
  else if (key == KEY_LEFT)
    this->getSnake()->moveSnake(Q);
  else if (key == KEY_RIGHT)
    this->getSnake()->moveSnake(D);
  else if (key == 27)
    return (-1);
  return (0);
}

void		NCurseImpl::close(void) {
  if (endwin() == ERR)
    throw ("endwin failed");
  std::cout << "THIS IS YOUR SCORE : " << this->getSnake()->getScore() << std::endl;
}
