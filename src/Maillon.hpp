//
// Maillon.hpp for Maillon in /home/benzah_m/cpp_nibbler/src
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Tue Mar 18 11:07:49 2014 benzah_m
// Last update Tue Apr  1 11:57:43 2014 benzah_m
//

#ifndef		__MAILLON_HPP__
# define	__MAILLON_HPP__

# include	<list>
# include	<iterator>
# include	<iostream>

class Maillon
{
private:
  int	_x;
  int	_y;
  int	_oldx;
  int	_oldy;
public:
  Maillon(int, int);
  Maillon(const Maillon &);
  ~Maillon(void);
  Maillon	&operator=(const Maillon &);
  void		setX(int);
  void		setY(int);
  int		getX(void) const;
  int		getY(void) const;
  void		setOldX(int);
  void		setOldY(int);
  int		getOldX(void) const;
  int		getOldY(void) const;
  void		swapValues(int, int);
  void		swapListValues(std::list<Maillon *> *);
};

#endif		/* !__MAILLON_HPP__ */
