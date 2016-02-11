//
// Core.hpp for Core in /home/benzah_m/rendu/cpp_nibbler
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 10:40:08 2014 benzah_m
// Last update Sun Apr  6 19:03:19 2014 benzah_m
//

#ifndef		__CORE_HPP__
# define	__CORE_HPP__

# include	<iostream>
# include	<string>
# include	<sstream>
# include	<ctime>
# include	<cmath>
# include	"../libs/common/AGraph.hpp"
# include	"LibLoader.hpp"
# include	"../src/Snake.hpp"

# define	X_WIN_MAX	(2000)
# define	Y_WIN_MAX	(X_WIN_MAX / 2)

class Core {
private:
  int			_x;
  int			_y;
  const std::string	&_lib;
  time_t		_time;
public:
  Core(char *, char *, const std::string &);
  Core(const Core &);
  ~Core(void);
  Core			&operator=(const Core &);
  void			setX(int);
  int			getX(void) const;
  void			setY(int);
  int			getY(void) const;
  const std::string	&getLib(void) const;
  void			setTime(time_t);
  time_t		getTime(void) const;
  int			convertStringValue(char *) const;
  char			*parseCoord(char *) const;
  void			checkExtension(void) const;
  int			getTimer(void);
  void			run(void);
};

#endif		/* !__CORE_HPP__ */
