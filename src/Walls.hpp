//
// Wall.hpp for nibbler in /home/dequid_v/rendu/snake/cpp_nibbler
// 
// Made by dequid_v
// Login   <dequid_v@epitech.net>
// 
// Started on  Fri Apr  4 17:03:07 2014 dequid_v
// Last update Sun Apr  6 16:18:15 2014 dequid_v
//

#ifndef WALLS_HH_
# define WALLS_HH_

#include "Key.hpp"
#include "Snake.hpp"
#include "Food.hpp"

class Walls
{
private:
  int	x;
  int	y;
  eDirection dir;
  int	length;
public:
  Walls();
  Walls(const Walls &w);
  Walls	&operator=(const Walls &w);
  Walls(const Snake &, eDirection, int length);
  int	getX(void) const;
  void	setX(int);
  int	getY(void) const;
  void	setY(int);
  void	setDir(eDirection d);
  eDirection getDir(void) const;
  int	getLength(void) const;
  void	setLength(int);
  bool check_pos(int, int, const Walls *);
  ~Walls();
};

#endif /* !WALLS_HH_ */
