//
// AGraph.hpp for AGraph in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 11:08:02 2014 benzah_m
// Last update Fri Apr  4 20:50:06 2014 benzah_m
//

#ifndef		__AGRAPH_HPP__
# define	__AGRAPH_HPP__

# include	"../../src/Snake.hpp"

class AGraph {
protected:
  int	_x;
  int	_y;
public:
  AGraph(void);
  AGraph(int, int);
  AGraph(const AGraph &);
  virtual ~AGraph(void) {};
  AGraph	&operator=(const AGraph &);
  void		setX(int);
  int		getX(void) const;
  void		setY(int);
  int		getY(void) const;
  virtual void	init(Snake *) = 0;
  virtual int	display(void) = 0;
  virtual int	getEvent(void) = 0;
  virtual void	close(void) = 0;
};

#endif		/* !__AGRAPH_HPP__ */
