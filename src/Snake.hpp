//
// Snake.hpp for Snake in /home/benzah_m/cpp_nibbler/src
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Tue Mar 18 11:12:54 2014 dequid_v
// Last update Sun Apr  6 21:54:49 2014 dequid_v
//

#ifndef		__SNAKE_HPP__
# define	__SNAKE_HPP__

class Walls;
class Food;

# include	<list>
# include	<iterator>
# include	<iostream>
# include	<ctime>
# include	<cstdlib>
# include	"Key.hpp"
# include	"Maillon.hpp"
# include	"Food.hpp"
# include	"Walls.hpp"

# define	CASE_SIZE		(20)
# define	DEFAULT_SNAKE_SIZE	(4)
# define	DEFAULT_DIR		(WEST)
# define	START_SCORE		(0)

class Snake
{
private:
  int			_x;
  int			_y;
  eDirection		_d;
  int			_score;
  std::list<Maillon *>	*_snake;
  std::list<Food *>	*_food;
  std::list<Walls *>	*walls;
  int			_delay;
  int			_speed;
  int			_oldSpeed;
  int			_energy;
  bool			_speedup;
  bool			_end;
  int			lock;
public:
  Snake(int, int);
  Snake(const Snake &s);
  ~Snake(void);
  Snake			&operator=(const Snake &s);
  void			setX(int);
  int			getX(void) const;
  void			setY(int);
  int			getY(void) const;
  int			getSpeed() const;
  void			setSpeed(int);
  int			getDelay() const;
  void			setDelay(int);
  int			getOldSpeed() const;
  void			setOldSpeed(int);
  int			getEnergy() const;
  void			setEnergy(int);
  void			setSpeedUp(bool);
  bool			getSpeedUp(void) const;
  void			setEnd(bool);
  bool			getEnd(void) const;
  int			speedBoost(int);
  int			checkScore(void) const;
  void			setDirection(eDirection);
  eDirection		getDirection(void) const;
  void			setScore(int);
  int			getScore(void) const;
  void			setSnake(std::list<Maillon *> *);
  int			increase_speed();
  std::list<Maillon *>	*getSnake(void) const;
  std::list<Walls *>	*getWalls(void) const;
  void			setFood(std::list<Food *> *);
  std::list<Food *>	*getFood(void) const;
  int			moveSnake(eKey);
  int			forward(int);
  void			addTail(void);
  int			addRandomWalls();
  void			setWalls(std::list<Walls *> *);
  int			check_wall_hits();
  int			getLock() const;
  void			setLock(int);
  int			deleteRandWalls();
  std::string		getBestScore();
};

#endif		/* !__SNAKE_HPP_ */
