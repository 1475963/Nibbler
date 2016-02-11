//
// Menu.cpp for  in /home/ravale_b/rendu/cpp_nibbler/src
// 
// Made by bastien ravalet
// Login   <ravale_b@epitech.net>
// 
// Started on  Thu Apr  3 16:50:54 2014 bastien ravalet
// Last update Sun Apr  6 22:35:33 2014 bastien ravalet
//

#include "Snake.hpp"
#include "Menu.hpp"

Menu::Menu()
{
  this->width = 30 * 32;
  this->height = 19 * 32;
  this->cur = 1;
  this->walls_on = true;
  this->screen = NULL;
}

Menu::~Menu()
{
  SDL_Quit();
}

int		Menu::getWidth() const
{
  return (this->width);
}

int		Menu::getHeight() const
{
  return (this->height);
}

bool		Menu::getWalls_on() const
{
  return (this->walls_on);
}

SDL_Event	*Menu::getEvents()
{
  return (&(this->_event));
}

SDL_Surface	*Menu::getScreen() const
{
  return (this->screen);
}

void		Menu::setWalls_on(bool walls)
{
  this->walls_on = walls;
}

void		Menu::setRect(int x, int y, int w, int h)
{
  this->getRect()->x = x;
  this->getRect()->y = y;
  this->getRect()->w = w;
  this->getRect()->h = h;
}

SDL_Rect	*Menu::getRect()
{
  return (&(this->point));
}

void	Menu::initMenu()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    throw (SDL_GetError());
  if (TTF_Init() != 0)
    throw ("failed to init TTF");
  if ((this->screen = SDL_SetVideoMode(this->width, this->height, 32, SDL_HWSURFACE)) == NULL)
    throw (SDL_GetError());
  if ((this->police = TTF_OpenFont(POLICE, TEXT_SIZE)) == NULL)
    throw ("failed to TTF_OpenFront");
  this->BackGround = SDL_LoadBMP("libs/sdl/ressources/menu.bmp");
  SDL_WM_SetCaption("Nibbler Menu", NULL);
}

int		Menu::loop_ingame(Snake *snake)
{
  int		ret = 0;
  static bool	iswall = false;
  
  this->initMenu();
  while (1)
    {
      ret = this->getEvent();
      if (this->DisplayMenu() != 0 || ret != 0 || ret == 1)
	{
	  snake = snake;
	  if (this->getWalls_on() == false)
	    {
	      snake->deleteRandWalls();
	      iswall = true;
	    }
	  else if (iswall == true)
	    snake->addRandomWalls();
	  break;
	}
    }
  if (ret == -1)
    return (0);
  else
    return (1);
}

int		Menu::main_loop_launch(Snake *snake)
{
  int		ret = 0;

  this->initMenu();
  while (1)
    {
      ret = this->getEvent();
      this->printModes(snake->getBestScore(), 15 * 32, 4);
      if (this->DisplayMenu() != 0 || ret != 0)
	{
	  if (this->getWalls_on() == 1)
	    snake->addRandomWalls();
	  break;
	}
    }
  if (ret == -1 || ret == -2)
    return (-1);
  return (0);
}

void		Menu::printModes(std::string txt, int y, int witch)
{
  SDL_Surface	*text;
  int		x = 0;
  SDL_Color	color;

  if (witch == 0)
    x = (this->width / 2) - (6 * TEXT_SIZE);
  else if (witch == 1)
    x = (this->width / 2) - (3 * TEXT_SIZE);
  else if (witch == 2)
    x = (this->width / 2) - (5 * TEXT_SIZE);
  else if (witch == 4)
    x = (this->width / 2) + 100;
  else
    x = (this->width / 2) - (1 * TEXT_SIZE);
  this->setRect(x, y, 100, 100);
  color.r = 0xFF;
  color.g = 0xFF;
  color.b = 0xFF;
  if ((text = TTF_RenderText_Solid(this->police, txt.data(), color)) == NULL)
    throw ("failed to TTF_RenderText_Solid");
  if (SDL_BlitSurface(text, NULL, this->getScreen(), this->getRect()) != 0)
    throw ("failed to SDL_BlitSurface");
}

void	Menu::printRect(int color)
{
  if (SDL_FillRect(this->getScreen(), this->getRect(), color) == -1)
    throw (SDL_GetError());
}

void	Menu::printcur(int cur)
{
  if (cur == 0)
    {
      this->setRect((this->width / 2) - (7 * (TEXT_SIZE / 2)), 10 * TEXT_SIZE, 3, 40);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (7 * (TEXT_SIZE / 2)), (11 * TEXT_SIZE) + 8, 190, 3);
      this->printRect(0xFF0000);
      this->setRect(((this->width / 2) - (7 * (TEXT_SIZE / 2)) + 190), (10 * TEXT_SIZE) + 3, 3, 40);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (7 * (TEXT_SIZE / 2)), (10 * TEXT_SIZE), 193, 3);
      this->printRect(0xFF0000);
    }
  else if (cur == 1)
    {
      this->setRect((this->width / 2) - (11 * (TEXT_SIZE / 2)) + 5, (12 * TEXT_SIZE) + 15, 3, 40);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (11 * (TEXT_SIZE / 2)) + 5, (12 * TEXT_SIZE) + 15, 285, 3);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (11 * (TEXT_SIZE / 2)) + 290, (12 * TEXT_SIZE) + 15, 3, 40);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (11 * (TEXT_SIZE / 2)) + 5, (13 * TEXT_SIZE) + 20 , 285, 3);
      this->printRect(0xFF0000);      
    }
  else if (cur == 2)
    {
      this->setRect((this->width / 2) - (3 * (TEXT_SIZE / 2)), 15 * TEXT_SIZE, 3, 40);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (3 * (TEXT_SIZE / 2)), (16 * TEXT_SIZE) + 8, 80, 3);
      this->printRect(0xFF0000);
      this->setRect(((this->width / 2) - (3 * (TEXT_SIZE / 2)) + 80), (15 * TEXT_SIZE) + 3, 3, 40);
      this->printRect(0xFF0000);
      this->setRect((this->width / 2) - (3 * (TEXT_SIZE / 2)), (15 * TEXT_SIZE), 83, 3);
      this->printRect(0xFF0000);
    }
}

int	Menu::DisplayMenu()
{
  if (SDL_FillRect(this->getScreen(), NULL, 0) == -1)
    throw ("SDL_FillRect failed");
  this->setRect(0, 0, this->width, this->height);
  if (SDL_BlitSurface(this->BackGround, NULL, this->getScreen(), this->getRect()) == -1)
    throw (SDL_GetError());
  this->printModes("WELCOME IN NIBBLER", 0 * TEXT_SIZE, 0);
  this->printModes("Play nibbler", 10 * TEXT_SIZE, 1);
  if (this->walls_on == true)
    this->printModes("Random wall : ON", (12 * TEXT_SIZE) + (TEXT_SIZE / 2), 2);
  else
    this->printModes("Random wall : OFF", (12 * TEXT_SIZE) + (TEXT_SIZE / 2), 2);
  this->printModes("Exit", 15 * TEXT_SIZE, 3);
  //  this->printModes("High Score :", 15 * TEXT_SIZE, 4);
  this->printcur(this->cur);
  if (SDL_Flip(this->getScreen()) == -1)
    throw ("SDL_Flip failed");
  return (0);
}

int	Menu::getEvent()
{
  while (SDL_PollEvent(this->getEvents()))
    {
      if (this->getEvents()->type == SDL_QUIT)
	return (-1);
      else if (this->getEvents()->type == SDL_KEYDOWN)
	{
	  if (this->getEvents()->key.keysym.sym == SDLK_ESCAPE)
	    return (-2);
	  else if (this->getEvents()->key.keysym.sym == SDLK_UP)
	    {
	      if (this->cur != 0)
		this->cur--;
	    }
	  else if (this->getEvents()->key.keysym.sym == SDLK_DOWN)
	    {
	      if (this->cur != 2)
		this->cur++;
	    }
	  else if (this->getEvents()->key.keysym.sym == SDLK_RETURN)
	    {
	      if (this->cur == 0)
		return (1);
	      else if (this->cur == 1)
		{
		  if (this->walls_on == true)
		    this->setWalls_on(false);
		  else if (this->walls_on == false)
		    this->setWalls_on(true);
		}
	      else if (this->cur == 2)
		return (-1);
	    }
	}
    }
  return (0);
}
