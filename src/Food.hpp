//
// Food.hpp for Food in /home/benzah_m/rendu/cpp_nibbler/trash
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Tue Mar 18 02:51:24 2014 benzah_m
// Last update Sun Apr  6 19:19:07 2014 benzah_m
//

#ifndef		__FOOD_HPP__
# define	__FOOD_HPP__

class Snake;

# include	"Snake.hpp"

# define	SPECIAL_SCORE (50)
# define	DEFAULT_SCORE (10)

class Food
{
private:
  int	_x;
  int	_y;
  int	_score;
  bool	_special;
  int	_delay;
public:
  Food(const Snake &, bool);
  Food(const Food &);
  ~Food(void);
  Food	&operator=(const Food &);
  void	setX(int);
  int	getX(void) const;
  void	setY(int);
  int	getY(void) const;
  int	getDelay(void) const;
  void	setScore(int);
  int	getScore(void) const;
  void	setSpecial(bool);
  bool	getSpecial(void) const;
  int	check_ftimer();
};

#endif		/* !__FOOD_HPP__ */
