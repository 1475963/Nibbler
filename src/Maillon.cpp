//
// maillon.cpp for nibbler in /home/dequid_v/rendu/snake
// 
// Made by dequid_v
// Login   <dequid_v@epitech.net>
// 
// Started on  Fri Mar 14 14:44:15 2014 dequid_v
// Last update Tue Apr  1 11:22:47 2014 benzah_m
//

#include "Maillon.hpp"

Maillon::Maillon(int x, int y) {
  this->setX(x);
  this->setY(y);
  this->setOldX(x);
  this->setOldY(y);
}

Maillon::Maillon(Maillon const &m) {
  if (this != &m)
    {
      this->setX(m.getX());
      this->setY(m.getY());
      this->setOldX(m.getOldX());
      this->setOldY(m.getOldY());
    }
}

Maillon::~Maillon(void) {
}

Maillon		&Maillon::operator=(Maillon const &m) {
  if (this != &m)
    {
      this->setX(m.getX());
      this->setY(m.getY());
      this->setOldX(m.getOldX());
      this->setOldY(m.getOldY());
    }
  return (*this);
}

void		Maillon::setX(int x) {
  this->_x = x;
}

int		Maillon::getX(void) const {
  return (this->_x);
}

void		Maillon::setY(int y) {
  this->_y = y;
}

int		Maillon::getY(void) const
{
  return (this->_y);
}

void		Maillon::setOldX(int x) {
  this->_oldx = x;
}

int		Maillon::getOldX(void) const {
  return (this->_oldx);
}

void		Maillon::setOldY(int y) {
  this->_oldy = y;
}

int		Maillon::getOldY(void) const {
  return (this->_oldy);
}

void		Maillon::swapValues(int x, int y) {
  this->setOldX(this->getX());
  this->setOldY(this->getY());
  this->setX(x);
  this->setY(y);
}

void					Maillon::swapListValues(std::list<Maillon *> *s)
{
  std::list<Maillon *>::iterator	it = s->begin();
  int					x, y;

  x = (*it)->getOldX();
  y = (*it)->getOldY();
  it++;
  while (it != s->end())
    {
      (*it)->swapValues(x, y);
      x = (*it)->getOldX();
      y = (*it)->getOldY();
      ++it;
    }
}
