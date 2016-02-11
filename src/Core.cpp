//
// Core.cpp for Core in /home/benzah_m/rendu/cpp_nibbler
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 10:41:04 2014 benzah_m
// Last update Mon Jul 21 02:42:15 2014 benzah_m
//

#include "Menu.hpp"
#include "Core.hpp"

Core::Core(char *x, char *y, const std::string &lib) : _lib(lib) {
  this->setX(this->convertStringValue(this->parseCoord(x)));
  if (this->getX() < 15)
    throw ("x too small, try again !");
  else if (this->getX() * CASE_SIZE > X_WIN_MAX)
    throw ("x too big, try again !");
  this->setY(this->convertStringValue(this->parseCoord(y)));
  if (this->getY() < 15)
    throw ("y too small, try again !");
  else if (this->getY() * CASE_SIZE > Y_WIN_MAX)
    throw ("y too big, try again !");
  this->checkExtension();
  this->setTime(time(0));
}

Core::Core(const Core &core) : _lib(core.getLib()) {
  if (this != &core)
    {
      this->setX(core.getX());
      this->setY(core.getY());
      this->checkExtension();
      this->setTime(core.getTime());
    }
}

Core::~Core(void) {
}

Core	&Core::operator=(const Core &core) {
  if (this != &core)
    {
      this->setX(core.getX());
      this->setY(core.getY());
      this->checkExtension();
      this->setTime(core.getTime());
    }
  return (*this);
}

void	Core::setX(int x) {
  this->_x = x;
}

int	Core::getX(void) const {
  return (this->_x);
}

void	Core::setY(int y) {
  this->_y = y;
}

int	Core::getY(void) const {
  return (this->_y);
}

const std::string	&Core::getLib(void) const {
  return (this->_lib);
}

void	Core::setTime(time_t time) {
  this->_time = time;
}

time_t	Core::getTime(void) const {
  return (this->_time);
}

int			Core::convertStringValue(char *value) const {
  int			ret;
  std::stringstream	ss;

  ss << value;
  ss >> ret;
  return (ret);
}

char	*Core::parseCoord(char *str) const {
  for (int i = 0; str[i]; ++i)
    if (str[i] < '0' || str[i] > '9')
      throw ("width & height must contain only numeric chars");
  return (str);
}

void	Core::checkExtension(void) const {
  int	len = this->getLib().size() - 1;

  if (len < 3 || this->getLib().data()[len] != 'o' || this->getLib().data()[len - 1] != 's' || this->getLib().data()[len - 2] != '.')
    throw ("lib file must have .so as extension");
}

int		Core::getTimer(void) {
  static int	state;

  if (fmod(difftime(time(0), this->getTime()), 2) == 1)
    {
      this->setTime(time(0));
      if (state < 6)
	++state;
      else
	{
	  state = 0;
	  return (1);
	}
    }
  return (0);
}

void		Core::run(void) 
{
  LibLoader	*libLoader = new LibLoader();
  AGraph	*lib;
  Snake		*snake = new Snake(this->getX(), this->getY());
  Menu		*menu = new Menu();

  if (menu->main_loop_launch(snake) == -1)
    {
      delete menu;
      return ;
    }
  delete menu;
  menu = new Menu();
  std::srand(std::time(NULL));
  if ((lib = libLoader->load(this->getLib(), this->getX(), this->getY())) != NULL)
    {
      lib->init(snake);
      while (snake->forward(this->getTimer()) != -1)
	{
	  if (lib->display() == -1 || lib->getEvent() == -1)
	    {
	      if (menu->loop_ingame(snake) == 0)
		break ;
	      else
		{
		  lib->close();
		  lib->init(snake);
		}
	    }
	  //	  snake->increase_speed();
	  if (snake->getSpeedUp() == true)
	    snake->speedBoost(0);
	  else
	    snake->speedBoost(-1);
	}
      lib->close();
    }
  libLoader->unload(lib);
}
