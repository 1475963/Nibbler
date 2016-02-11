//
// SDLImpl.hpp for SDLImpl in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 13:40:57 2014 benzah_m
// Last update Sun Apr  6 18:05:11 2014 benzah_m
//

#ifndef		__SDLIMPL_HPP__
# define	__SDLIMPL_HPP__

# include	<SDL/SDL.h>
# include	<SDL/SDL_image.h>
# include	<SDL/SDL_mixer.h>
# include	<SDL/SDL_ttf.h>
# include	<iostream>
# include	<sstream>
# include	<ctime>
# include	<cmath>
# include	"../common/AGraph.hpp"
# include	"../../src/Snake.hpp"

# define	DEFAULT_DELAY	(120)
# define	SPEEDUP_DELAY	(40)
# define	HEAD_COLOR	(0xFF0000)
# define	SNAKE_COLOR	(0x00FF00)
# define	POLICE		("libs/sdl/ressources/arial.ttf")
# define	TEXT_SIZE	(32)
# define	BAR_SIZE	(100)

class SDLImpl : public AGraph {
private:
  Mix_Chunk	*music;
  Mix_Chunk	*eat;  
  Mix_Chunk	*die;
  Mix_Chunk	*speed;
  SDL_Surface	*_screen;
  SDL_Event	_event;
  TTF_Font	*_police;
  Snake		*_snake;
  SDL_Surface	*_food;
  SDL_Surface	*_spefood;
  SDL_Surface	*_walls;
  SDL_Rect	_point;
  time_t	_time;
public:
  SDLImpl(int, int);
  SDLImpl(const SDLImpl &);
  ~SDLImpl(void);
  SDLImpl	&operator=(const SDLImpl &);
  SDL_Surface	*getScreen(void) const;
  SDL_Event	*getEvents(void);
  Snake		*getSnake(void) const;
  SDL_Surface	*getFood() const;
  SDL_Surface	*getSpeFood() const;
  SDL_Surface	*getWalls() const;
  void		setTime(time_t);
  time_t	getTime(void) const;
  void		setRect(int, int, int, int);
  SDL_Rect	*getRect(void);
  void		loadImg(SDL_Surface **, std::string *);
  void		printImg(SDL_Surface *, int, int);
  void		printText(std::string *, int, int);
  void		printRect(int);
  void		printFood(void);
  void		printSnake(void);
  void		printWalls(void);
  void		printEnergy(void);
  int		getTimer(void);
  void		init(Snake *);
  int		display(void);
  int		getEvent(void);
  void		close(void);
  void		printRandWalls();
  int		audio_Init();
  Mix_Chunk	*getSound(std::string s);
};

#endif		/* !__SDLIMPL_HPP__ */
