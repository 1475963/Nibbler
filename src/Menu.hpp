//
// Menu.hpp for  in /home/ravale_b/rendu/cpp_nibbler/src
// 
// Made by bastien ravalet
// Login   <ravale_b@epitech.net>
// 
// Started on  Thu Apr  3 16:45:45 2014 bastien ravalet
// Last update Sun Apr  6 22:33:03 2014 bastien ravalet
//

#ifndef		MENU_HPP
# define	MENU_HPP

# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<SDL/SDL_image.h>
# include	<SDL/SDL_mixer.h>
# include	"LibLoader.hpp"
# include	<iostream>
# include	"Snake.hpp"

# define	POLICE		("libs/sdl/ressources/arial.ttf")
# define	TEXT_SIZE	(32)

class Menu {
private:
  bool		walls_on;
  SDL_Surface	*screen;
  SDL_Surface	*BackGround;
  SDL_Event	_event;
  TTF_Font	*police;
  int		width;
  int		height;
  int		cur;
  SDL_Rect	point;
public:
  Menu();
  ~Menu();
  int	DisplayMenu();
  int	getEvent();
  void	initMenu();
  void	printModes(std::string, int, int);
  void	printcur(int);
  void	printRect(int);
  int	main_loop_launch(Snake *);
  int	loop_ingame(Snake *);

  //Getters
  SDL_Surface	*getScreen() const;
  SDL_Event	*getEvents();
  int		getWidth() const;
  int		getHeight() const;
  void		setRect(int, int, int, int);
  void		setWalls_on(bool);
  SDL_Rect	*getRect();
  bool		getWalls_on() const;
};

#endif		/* !MENU_HPP */
