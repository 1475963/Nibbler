//
// AGraph.cpp for AGraph in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 11:09:34 2014 benzah_m
// Last update Tue Apr  1 12:01:48 2014 benzah_m
//

#include "AGraph.hpp"

AGraph::AGraph(void) {
  this->setX(0);
  this->setY(0);
}

AGraph::AGraph(int x, int y) {
  this->setX(x);
  this->setY(y);
}

AGraph::AGraph(const AGraph &graph) {
  this->setX(graph.getX());
  this->setY(graph.getY());
}

AGraph	&AGraph::operator=(const AGraph &graph) {
  if (this != &graph)
    {
      this->setX(graph.getX());
      this->setY(graph.getY());
    }
  return (*this);
}

void	AGraph::setX(int x) {
  this->_x = x;
}

int	AGraph::getX(void) const {
  return (this->_x);
}

void	AGraph::setY(int y) {
  this->_y = y;
}

int	AGraph::getY(void) const {
  return (this->_y);
}
