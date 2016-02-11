//
// NCurseImpl.hpp for NCurseImpl in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 14:24:42 2014 benzah_m
// Last update Sun Apr  6 21:30:09 2014 benzah_m
//

#ifndef		__NCURSEIMPL_HPP__
# define	__NCURSEIMPL_HPP__

# include	<ncurses.h>
# include	<ctime>
# include	<iostream>
# include	"../common/AGraph.hpp"
# include	"../../src/Snake.hpp"

class NCurseImpl : public AGraph {
private:
  Snake		*_snake;
  WINDOW	*win;
public:
  NCurseImpl(void);
  NCurseImpl(int, int);
  NCurseImpl(const NCurseImpl &);
  ~NCurseImpl(void);
  NCurseImpl	&operator=(const NCurseImpl &);
  void		init(Snake *);
  int		display(void);
  int		getEvent(void);
  void		close(void);
  void		printRandomWalls(void) const;
  void		do_walls(void);
  void		printSnake(void);
  void		printFood(void);
  Snake		*getSnake(void) const;
};

#endif		/* !__NCURSEIMPL_HPP__ */
