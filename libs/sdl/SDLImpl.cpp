//
// SDLImpl.cpp for SDLImpl in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 13:44:33 2014 benzah_m
// Last update Sun Apr  6 22:31:56 2014 dequid_v
//

#include "SDLImpl.hpp"

extern "C" AGraph	*load(int x, int y) {
  return (new SDLImpl(x, y));
}

extern "C" void		unload(AGraph *lib) {
  delete (lib);
}

SDLImpl::SDLImpl(int x, int y) : AGraph(x, y) {
  std::cout << "SDL" << std::endl;
  this->_screen = NULL;
  this->loadImg(&(this->_food), new std::string("libs/sdl/ressources/Spider.bmp"));
  this->loadImg(&(this->_spefood), new std::string("libs/sdl/ressources/Untitled.bmp"));
  this->_walls = SDL_LoadBMP("libs/sdl/ressources/walls.bmp");
  this->setTime(time(0));
}

SDLImpl::SDLImpl(const SDLImpl &sdl) : AGraph(sdl) {
  if (this != &sdl)
    {
      this->setX(sdl.getX());
      this->setY(sdl.getY());
      this->_screen = sdl.getScreen();
      this->_food = sdl.getFood();
      this->_snake = sdl.getSnake();
      this->_spefood = sdl.getSpeFood();
    }
}

SDLImpl::~SDLImpl(void) {
}

SDLImpl		&SDLImpl::operator=(const SDLImpl &sdl) {
  if (this != &sdl)
    {
      this->setX(sdl.getX());
      this->setY(sdl.getY());
      this->_screen = sdl.getScreen();
      this->_food = sdl.getFood();
      this->_snake = sdl.getSnake();
      this->_spefood = sdl.getSpeFood();
    }
  return (*this);
}

Snake		*SDLImpl::getSnake(void) const {
  return (this->_snake);
}

SDL_Surface	*SDLImpl::getScreen(void) const {
  return (this->_screen);
}

SDL_Event	*SDLImpl::getEvents(void) {
  return (&(this->_event));
}

SDL_Surface	*SDLImpl::getSpeFood(void) const {
  return (this->_spefood);
}

SDL_Surface	*SDLImpl::getFood() const {
  return (this->_food);
}

SDL_Surface	*SDLImpl::getWalls() const
{
  return (this->_walls);
}

void		SDLImpl::setTime(time_t time) {
  this->_time = time;
}

time_t		SDLImpl::getTime(void) const {
  return (this->_time);
}

void		SDLImpl::setRect(int x, int y, int w, int h) {
  this->getRect()->x = x;
  this->getRect()->y = y;
  this->getRect()->w = w;
  this->getRect()->h = h;
}

SDL_Rect	*SDLImpl::getRect(void) {
  return (&(this->_point));
}

void		SDLImpl::loadImg(SDL_Surface **img, std::string *path) {
  if ((*img = SDL_LoadBMP(path->data())) == NULL)
    throw (SDL_GetError());
}

void		SDLImpl::printImg(SDL_Surface *img, int x, int y) 
{
  SDL_Rect	point;

  point.x = x * CASE_SIZE;
  point.y = y * CASE_SIZE;
  if (SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 28, 220, 28)) == -1)
    throw (SDL_GetError());
  if (SDL_BlitSurface(img, NULL, this->getScreen(), &point) == -1)
    throw (SDL_GetError());
}

void		SDLImpl::printRandWalls()
{
  std::list<Walls *>		*list = this->getSnake()->getWalls();
  std::list<Walls *>::iterator	it = list->begin();
  int	k = 0;

  while (it != list->end())
    {
      int	x = (*it)->getX();
      int	y = (*it)->getY();
      while (k != (*it)->getLength())
	{
	  this->setRect(x * CASE_SIZE, y * CASE_SIZE, 100, 100);
	  if (SDL_BlitSurface(this->getWalls(), NULL, this->getScreen(), this->getRect()) == -1)
	    throw (SDL_GetError());
	  if ((*it)->getDir() == SOUTH)
	    y++;
	  else if ((*it)->getDir() == NORTH)
	    y--;
	  else if ((*it)->getDir() == WEST)
	    x--;
	  else if ((*it)->getDir() == EAST)
	    x++; 
	  k++;
	}
      k = 0;
      it++;
    }
}

void		SDLImpl::printWalls()
{
  for (int y = 0; y < this->getY(); y++)
    for (int x = 0; x < this->getX(); x++)
      if (y == 0 || y == this->getY() - 1
	  || x == 0 || x == this->getX() - 1)
	{
	  this->setRect(x * CASE_SIZE, y * CASE_SIZE, 100, 100);
	  if (SDL_BlitSurface(this->getWalls(), NULL, this->getScreen(), this->getRect()) == -1)
	    throw (SDL_GetError());
	}
  this->printRandWalls();
}

void		SDLImpl::printText(std::string *txt, int x, int y) {
  SDL_Surface	*text;
  SDL_Color	color;

  this->setRect(x, y, 100, 100);
  color.r = 0xFF;
  color.g = 0xFF;
  color.b = 0xFF;
  if ((text = TTF_RenderText_Solid(this->_police, txt->data(), color)) == NULL)
    throw ("failed to TTF_RenderText_Solid");
  if (SDL_BlitSurface(text, NULL, this->getScreen(), this->getRect()) != 0)
    throw ("failed to SDL_BlitSurface");
}

void		SDLImpl::printRect(int color) {
  if (SDL_FillRect(this->getScreen(), this->getRect(), color) == -1)
    throw (SDL_GetError());
}

void				SDLImpl::printFood(void) {
  std::list<Food *>		*list = this->getSnake()->getFood();
  std::list<Food *>::iterator	it = list->begin();

  while (it != list->end())
    {
      if ((*it)->getSpecial() == true)
	this->printImg(this->getSpeFood(), (*it)->getX(), (*it)->getY());
      else
	this->printImg(this->getFood(), (*it)->getX(), (*it)->getY());
      ++it;
    }
}

void					SDLImpl::printSnake(void)
{
  std::list<Maillon *>			*list = this->getSnake()->getSnake();
  std::list<Maillon *>::iterator	it = list->begin();
  static int	len = 0;
  int		k = 0;

  while (it != list->end())
    {
      this->setRect((*it)->getX() * CASE_SIZE, (*it)->getY() * CASE_SIZE, CASE_SIZE - 1, CASE_SIZE -1);
      if (it == list->begin())
	this->printRect(HEAD_COLOR);
      else
	this->printRect(SNAKE_COLOR);
      ++it;
      k++;
    }
  if (k > len)
    {
      len = k;
      Mix_PlayChannel(2, this->getSound("feed"), 0);      
    }
}

void		SDLImpl::printEnergy(void) {
  this->setRect((this->getX() * CASE_SIZE) - BAR_SIZE - 30, 30, this->getSnake()->getEnergy(), 20);
  this->printRect(0xFFFF00);
}

/* check if a special food should spawn at this point of the game */

int		SDLImpl::getTimer(void) {
  static int	state;

  if (fmod(difftime(time(0), this->getTime()), 11) == 10)
    {
      this->setTime(time(0));
      if (state < 4)
	{
	  ++state;
	  return (1);
	}
      else
	{
	  state = 0;
	  return (2);
	}
    }
  return (0);
}

Mix_Chunk	*SDLImpl::getSound(std::string s)
{
  if (s == "music")
    return (this->music);
  else if (s == "die")
    return (this->die);
  else if (s == "feed")
    return (this->eat);
  else if (s == "speed")
    return (this->speed);
  return (NULL);
}

void		SDLImpl::init(Snake *snake)
{
  this->_snake = snake;
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    throw (SDL_GetError());
  if (TTF_Init() != 0)
    throw ("failed to init TTF");
  if ((this->_screen = SDL_SetVideoMode(this->getX() * CASE_SIZE, this->getY() * CASE_SIZE, 32, SDL_HWSURFACE)) == NULL)
    throw (SDL_GetError());
  if ((this->_police = TTF_OpenFont(POLICE, TEXT_SIZE)) == NULL)
    throw ("failed to TTF_OpenFont");
  SDL_WM_SetCaption("NIBBLER SNAKE", NULL);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    throw ("failed to init audio");
  if (Mix_AllocateChannels(3) == 0)
    throw ("could'nt allocate sounds channels");
  if ((this->music = Mix_LoadWAV("libs/sdl/ressources/lol.wav")) == NULL ||
      (this->eat = Mix_LoadWAV("libs/sdl/ressources/feed.wav")) == NULL ||
      (this->die = Mix_LoadWAV("libs/sdl/ressources/die.wav")) == NULL ||
      (this->speed = Mix_LoadWAV("libs/sdl/ressources/speed.wav")) == NULL)
    throw ("failed to load sounds");
  Mix_VolumeChunk(this->getSound("music"), MIX_MAX_VOLUME/2);
  Mix_VolumeChunk(this->getSound("speed"), MIX_MAX_VOLUME/2);
  Mix_VolumeChunk(this->getSound("feed"), MIX_MAX_VOLUME/2);
  Mix_VolumeChunk(this->getSound("die"), MIX_MAX_VOLUME/2);
  if (Mix_PlayChannel(0, this->music, -1) == -1)
    throw ("failed to play sound");
}

/* Display all informations on the screen such as snake, walls, food */

int			SDLImpl::display(void) 
{
  std::stringstream	ss;

  if (SDL_FillRect(this->getScreen(), NULL, 0) == -1)
    throw ("SDL_FillRect failed");
  ss << this->getSnake()->getScore();
  this->printText(new std::string("Score : " + ss.str()), CASE_SIZE, CASE_SIZE);
  this->printEnergy();
  this->printWalls();
  this->printFood();
  this->printSnake();
  if (SDL_Flip(this->getScreen()) == -1)
    throw ("SDL_Flip failed");
  SDL_Delay(this->getSnake()->getSpeed());
  return (0);
}

int		SDLImpl::getEvent(void)
{
  while (SDL_PollEvent(this->getEvents()))
    {
      if (this->getEvents()->type == SDL_QUIT)
	return (-1);
      else if (this->getEvents()->type == SDL_KEYDOWN)
	{
	  if (this->getEvents()->key.keysym.sym == SDLK_ESCAPE)
	    return (-1);
	  else if (this->getEvents()->key.keysym.sym == SDLK_RIGHT)
	    this->getSnake()->moveSnake(RIGHT);
	  else if (this->getEvents()->key.keysym.sym == SDLK_LEFT)
	    this->getSnake()->moveSnake(LEFT);
	  else if (this->getEvents()->key.keysym.sym == SDLK_z)
	    this->getSnake()->moveSnake(Z);
	  else if (this->getEvents()->key.keysym.sym == SDLK_q)
	    this->getSnake()->moveSnake(Q);
	  else if (this->getEvents()->key.keysym.sym == SDLK_s)
	    this->getSnake()->moveSnake(S);
	  else if (this->getEvents()->key.keysym.sym == SDLK_d)
	    this->getSnake()->moveSnake(D);
	  else if (this->getEvents()->key.keysym.sym == SDLK_p)
	    if (Mix_PausedMusic() == 1)
	      Mix_Resume(-1);
	    else
	      Mix_HaltChannel(-1);
	  else if (this->getEvents()->key.keysym.sym == SDLK_SPACE)
	    {
	      if (this->getSnake()->getEnergy() > 0)
		Mix_PlayChannel(2, this->getSound("speed"), 0);
	      this->getSnake()->setSpeedUp(true);
	    }
	}
      else if (this->getEvents()->type == SDL_KEYUP)
	{
	  if (this->getEvents()->key.keysym.sym == SDLK_SPACE)
	    this->getSnake()->setSpeedUp(false);
	}
    }
  return (0);
}

void		SDLImpl::close(void) {
  std::cout << "Closing gui ... ";
  Mix_HaltChannel(0);
  if (Mix_PlayChannel(1, this->getSound("die"), 0) == -1)
    throw ("failed to play sound");
  SDL_Delay(750);
  SDL_Quit();
  std::cout << "Done" << std::endl;
  this->getSnake()->checkScore();
}
