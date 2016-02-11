//
// OpenGLImpl.cpp for OpenGLImpl in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 10:52:15 2014 benzah_m
// Last update Fri May  9 22:41:19 2014 benzah_m
//

#include "OpenGLImpl.hpp"

OpenGLImpl	*opengl;

extern "C" AGraph	*load(int x, int y) {
  opengl = new OpenGLImpl(x, y);
  return (opengl);
}

extern "C" void		unload(AGraph *lib) {
  delete (lib);
}

OpenGLImpl::OpenGLImpl(int x, int y) : AGraph(x, y) {
  this->setXCam(0);
  this->setYCam(0);
  this->setZCam(150);
  this->setIndice(1);
  this->setR(DEFAULT_R);
  this->setG(DEFAULT_G);
  this->setB(DEFAULT_B);
  this->setEasterEgg(0);
  this->setPause(1);
}

OpenGLImpl::OpenGLImpl(const OpenGLImpl &gl) : AGraph(gl) {
  if (this != &gl)
    {
      this->setXCam(gl.getXCam());
      this->setYCam(gl.getYCam());
      this->setZCam(gl.getZCam());
      this->setIndice(gl.getIndice());
      this->setR(gl.getR());
      this->setG(gl.getG());
      this->setB(gl.getB());
      this->setEasterEgg(gl.getEasterEgg());
      this->setPause(gl.getPause());
    }
}

OpenGLImpl::~OpenGLImpl(void) {
}

OpenGLImpl	&OpenGLImpl::operator=(const OpenGLImpl &gl) {
  if (this != &gl)
    {
      this->setXCam(gl.getXCam());
      this->setYCam(gl.getYCam());
      this->setZCam(gl.getZCam());
      this->setIndice(gl.getIndice());
      this->setR(gl.getR());
      this->setG(gl.getG());
      this->setB(gl.getB());
      this->setEasterEgg(gl.getEasterEgg());
      this->setPause(gl.getPause());
    }
  return (*this);
}

Snake	*OpenGLImpl::getSnake(void) const {
  return (this->_snake);
}

void	OpenGLImpl::setXCam(int x) {
  this->_xcam = x;
}

int	OpenGLImpl::getXCam(void) const {
  return (this->_xcam);
}

void	OpenGLImpl::setYCam(int y) {
  this->_ycam = y;
}

int	OpenGLImpl::getYCam(void) const {
  return (this->_ycam);
}

void	OpenGLImpl::setZCam(int z) {
  this->_zcam = z;
}

int	OpenGLImpl::getZCam(void) const {
  return (this->_zcam);
}

void	OpenGLImpl::setIndice(double ind) {
  this->_ind = ind;
}

double	OpenGLImpl::getIndice(void) const {
  return (this->_ind);
}

void	OpenGLImpl::setR(int r) {
  this->_r = r;
}

int	OpenGLImpl::getR(void) const {
  return (this->_r);
}

void	OpenGLImpl::setG(int g) {
  this->_g = g;
}

int	OpenGLImpl::getG(void) const {
  return (this->_g);
}

void	OpenGLImpl::setB(int b) {
  this->_b = b;
}

int	OpenGLImpl::getB(void) const {
  return (this->_b);
}

void	OpenGLImpl::setEasterEgg(int egg) {
  this->_easterEgg = egg;
}

int	OpenGLImpl::getEasterEgg(void) const {
  return (this->_easterEgg);
}

void	OpenGLImpl::setPause(int pause) {
  this->_pause = pause;
}

int	OpenGLImpl::getPause(void) const {
  return (this->_pause);
}

int	OpenGLImpl::getRandomRGB(void) const {
  return (rand() % 256);
}

float	OpenGLImpl::getRandomCoord(void) const {
  return (rand() % (CASE_SIZE / 4));
}

void	OpenGLImpl::drawBottomFace(int x, int y, int z, int r, int g, int b) const {
  glBegin(GL_POLYGON);
  glColor3ub(r, g, b);
  glVertex3d(x - LEN, y - LEN, z + ZLEN);
  glVertex3d(x - LEN, y - LEN, z - ZLEN);
  glVertex3d(x + LEN, y - LEN, z - ZLEN);
  glVertex3d(x + LEN, y - LEN, z + ZLEN);
  glEnd();
}

void	OpenGLImpl::drawTopFace(int x, int y, int z, int r, int g, int b) const {
  glBegin(GL_POLYGON);
  glColor3ub(r, g, b);
  glVertex3d(x + LEN, y + LEN, z + ZLEN);
  glVertex3d(x + LEN, y + LEN, z - ZLEN);
  glVertex3d(x - LEN, y + LEN, z - ZLEN);
  glVertex3d(x - LEN, y + LEN, z + ZLEN);
  glEnd();
}

void	OpenGLImpl::drawFrontFace(int x, int y, int z, int r, int g, int b) const {
  glBegin(GL_POLYGON);
  glColor3ub(r, g, b);
  glVertex3d(x + LEN, y - LEN, z + ZLEN);
  glVertex3d(x + LEN, y + LEN, z + ZLEN);
  glVertex3d(x - LEN, y + LEN, z + ZLEN);
  glVertex3d(x - LEN, y - LEN, z + ZLEN);
  glEnd();
}

void	OpenGLImpl::drawBackFace(int x, int y, int z, int r, int g, int b) const {
  glBegin(GL_POLYGON);
  glColor3ub(r, g, b);
  glVertex3d(x + LEN, y + LEN, z - ZLEN);
  glVertex3d(x + LEN, y - LEN, z - ZLEN);
  glVertex3d(x - LEN, y - LEN, z - ZLEN);
  glVertex3d(x - LEN, y + LEN, z - ZLEN);
  glEnd();
}

void	OpenGLImpl::drawLeftFace(int x, int y, int z, int r, int g, int b) const {
  glBegin(GL_POLYGON);
  glColor3ub(r, g, b);
  glVertex3d(x - LEN, y + LEN, z + ZLEN);
  glVertex3d(x - LEN, y + LEN, z - ZLEN);
  glVertex3d(x - LEN, y - LEN, z - ZLEN);
  glVertex3d(x - LEN, y - LEN, z + ZLEN);
  glEnd();
}

void	OpenGLImpl::drawRightFace(int x, int y, int z, int r, int g, int b) const {
  glBegin(GL_POLYGON);
  glColor3ub(r, g, b);
  glVertex3d(x + LEN, y - LEN, z + ZLEN);
  glVertex3d(x + LEN, y - LEN, z - ZLEN);
  glVertex3d(x + LEN, y + LEN, z - ZLEN);
  glVertex3d(x + LEN, y + LEN, z + ZLEN);
  glEnd();
}

void	OpenGLImpl::drawCube(int x, int y, int z, int r, int g, int b) const {
  this->drawBottomFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
  this->drawTopFace(x, y, z, r / 2, g / 2, b / 2);
  this->drawFrontFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
  this->drawBackFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
  this->drawLeftFace(x, y, z, r, g, b);
  this->drawRightFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
}

void	OpenGLImpl::drawRandomCube(int x, int y, int z, int r, int g, int b) const {
  x = x - this->getRandomCoord();
  y = y - this->getRandomCoord();
  z = z - this->getRandomCoord();
  this->drawBottomFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
  this->drawTopFace(x, y, z, r / 2, g / 2, b / 2);
  this->drawFrontFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
  this->drawBackFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
  this->drawLeftFace(x, y, z, r, g, b);
  this->drawRightFace(x, y, z, r / 1.5, g / 1.5, b / 1.5);
}

void				OpenGLImpl::printRandomWalls(void) const {
  std::list<Walls *>		*list = this->getSnake()->getWalls();
  std::list<Walls *>::iterator	it = list->begin();
  int				x = 0, y = 0, k = 0;

  while (it != list->end())
    {
      x = (*it)->getX();
      y = (*it)->getY();
      for (k = 0; k < (*it)->getLength(); k++)
	{
	  if (x < this->getX() && x > 0 && y < this->getY() && y > 0)
	    this->drawCube(x * CASE_SIZE, y * CASE_SIZE, 2, 255, 0, 0);
	  if ((*it)->getDir() == SOUTH)
	    y++;
	  else if ((*it)->getDir() == NORTH)
	    y--;
	  else if ((*it)->getDir() == WEST)
	    x--;
	  else if ((*it)->getDir() == EAST)
	    x++;
	}
      it++;
    }
}

void	OpenGLImpl::printWalls(void) const {
  for (int y = 0; y < this->getY(); y++)
    for (int x = 0; x < this->getX(); x++)
      if (y == 0 || y == this->getY() - 1
	  || x == 0 || x == this->getX() - 1)
	this->drawCube(x * CASE_SIZE, y * CASE_SIZE, 2, 255, 0, 0);
      else if ((y % 2 == 0 && x % 2 == 0) || (y % 2 == 1 && x % 2 == 1))
	this->drawCube(x * CASE_SIZE, y * CASE_SIZE, -10, this->getR(), this->getG(), this->getB());
      else if ((y % 2 == 0 && x % 2 == 1) || (y % 2 == 1 && x % 2 == 0))
	this->drawCube(x * CASE_SIZE, y * CASE_SIZE, -10, this->getR(), this->getG() + 30, this->getB());
  this->printRandomWalls();
}

void				OpenGLImpl::printFood(void) const {
  std::list<Food *>		*list = this->getSnake()->getFood();
  std::list<Food *>::iterator	it = list->begin();

  while (it != list->end())
    {
      if ((*it)->getSpecial() == true)
	this->drawCube((*it)->getX() * CASE_SIZE, (*it)->getY() * CASE_SIZE, 2, 0, 255, 255);
      else
	this->drawCube((*it)->getX() * CASE_SIZE, (*it)->getY() * CASE_SIZE, 2, 255, 255, 0);
      ++it;
    }
}

void					OpenGLImpl::printSnake(void) {
  std::list<Maillon *>			*list = this->getSnake()->getSnake();
  std::list<Maillon *>::iterator	it = list->begin();
  int					inc = 100;
  int					incr = 17;

  while (it != list->end())
    {
      if (it == list->begin())
	{
	  this->drawCube((*it)->getX() * CASE_SIZE, (*it)->getY() * CASE_SIZE, 20, 0, 255, 0);
	  this->setXCam((*it)->getX() * CASE_SIZE);
	  this->setYCam((*it)->getY() * CASE_SIZE);
	}
      else
	{
	  this->drawRandomCube((*it)->getX() * CASE_SIZE, (*it)->getY() * CASE_SIZE, 20, inc / 2, 255, inc);
	  if (inc + incr > 255 || inc + incr < 0)
	    incr *= -1;
	  else
	    inc += incr;
	}
      ++it;
    }
}

void		keyboard(unsigned char key, int x, int y) {
  x = x;
  y = y;

  if (key == 27)
    {
      opengl->setPause(opengl->getPause() * -1);
      opengl->getSnake()->forward(-1);
    }
  else if (key == ' ')
    {
      if (opengl->getSnake()->getSpeedUp() == false)
	opengl->getSnake()->setSpeedUp(true);
      else
	opengl->getSnake()->setSpeedUp(false);
    }
  else if (key == 'p')
    opengl->setPause(opengl->getPause() * -1);
}

void		skeyboard(int key, int x, int y) {
  x = x;
  y = y;
  
  if (key == GLUT_KEY_LEFT)
    opengl->getSnake()->moveSnake(RIGHT);
  else if (key == GLUT_KEY_RIGHT)
    opengl->getSnake()->moveSnake(LEFT);
  else if (key == GLUT_KEY_UP && opengl->getZCam() < 500)
    opengl->setZCam(opengl->getZCam() + 10);
  else if (key == GLUT_KEY_DOWN && opengl->getZCam() > 40)
    opengl->setZCam(opengl->getZCam() - 10);
  else if (key == GLUT_KEY_PAGE_UP)
    {
      if (opengl->getIndice() <= 2)
	opengl->setIndice(opengl->getIndice() + 0.1);
      else
	opengl->setIndice(1);
    }
  else if (key == GLUT_KEY_PAGE_DOWN)
    {
      if (opengl->getIndice() == 0.1 || opengl->getIndice() == -0.1)
	opengl->setIndice(opengl->getIndice() * (-1));
      else if (opengl->getIndice() >= 0.5 && opengl->getIndice() < 0)
	opengl->setIndice(1);
      else
	opengl->setIndice(opengl->getIndice() - 0.1);
    }
  else if (key == GLUT_KEY_F1)
    {
      if (opengl->getR() < 256)
	opengl->setR(opengl->getR() + 17);
      else
	opengl->setR(0);
    }
  else if (key == GLUT_KEY_F2)
    {
      if (opengl->getG() < 256)
	opengl->setG(opengl->getG() + 17);
      else
	opengl->setG(0);
    }
  else if (key == GLUT_KEY_F3)
    {
      if (opengl->getB() < 256)
	opengl->setB(opengl->getB() + 17);
      else
	opengl->setB(0);
    }
  else if (key == GLUT_KEY_F4)
    {
      opengl->setR(DEFAULT_R);
      opengl->setG(DEFAULT_G);
      opengl->setB(DEFAULT_B);
    }
  else if (key == GLUT_KEY_F5)
    opengl->setEasterEgg(1);
  else if (key == GLUT_KEY_F6)
    opengl->setEasterEgg(0);
}

void		OpenGLImpl::init(Snake *snake) {
  int		test = 0;

  this->_snake = snake;
  glutInit(&test, NULL);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(this->getX() * CASE_SIZE, this->getY() * CASE_SIZE);
  glutCreateWindow("NIBBLER");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(500,(double)this->getX() / this->getY(), 1, this->getX() * this->getY() * CASE_SIZE * 2);
  glEnable(GL_DEPTH_TEST);
  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(skeyboard);
}

int		OpenGLImpl::display(void) {
  while (this->getPause() == -1)
    glutMainLoopEvent();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColor3ub(0x99, 0xCC, 0xFF);
  gluSphere(gluNewQuadric(), 2000, 20, 20);

  if (this->getEasterEgg() == 0)
    {
      if (this->getSnake()->getDirection() == WEST)
	gluLookAt(this->getXCam() / this->getIndice(), this->getYCam() / this->getIndice(), this->getZCam(), this->getXCam() - CASE_SIZE * 5, this->getYCam(), 10, 0, 0, 1);
      else if (this->getSnake()->getDirection() == EAST)
	gluLookAt(this->getXCam() / this->getIndice(), this->getYCam() / this->getIndice(), this->getZCam(), this->getXCam() + CASE_SIZE * 5, this->getYCam(), 10, 0, 0, 1);
      else if (this->getSnake()->getDirection() == NORTH)
	gluLookAt(this->getXCam() / this->getIndice(), this->getYCam() / this->getIndice(), this->getZCam(), this->getXCam(), this->getYCam() - CASE_SIZE * 5, 10, 0, 0, 1);
      else if (this->getSnake()->getDirection() == SOUTH)
	gluLookAt(this->getXCam() / this->getIndice(), this->getYCam() / this->getIndice(), this->getZCam(), this->getXCam(), this->getYCam() + CASE_SIZE * 5, 10, 0, 0, 1);
    }
  else
    gluLookAt((*this->getSnake()->getFood()->begin())->getX() * CASE_SIZE, (*this->getSnake()->getFood()->begin())->getY() * CASE_SIZE, 100, this->getXCam(), this->getYCam(), 10, 0, 0, 1);

  this->printSnake();
  this->printFood();
  this->printWalls();

  glFlush();
  glutSwapBuffers();
  usleep(((this->getSnake()->getSpeed()) * 1000) / 1.5);
  return (0);
}

int		OpenGLImpl::getEvent(void) {
  glutMainLoopEvent();
  return (0);
}

void		OpenGLImpl::close(void) {
  std::cout << "Your score is : " << this->getSnake()->getScore() << std::endl;
  this->getSnake()->checkScore();
}
