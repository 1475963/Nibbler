//
// OpenGLImpl.hpp for OpenGLImpl in /home/benzah_m/rendu/cpp_nibbler/libs
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 10:49:05 2014 benzah_m
// Last update Sun Apr  6 18:58:00 2014 benzah_m
//

#ifndef		__OPENGLIMPL_HPP__
# define	__OPENGLIMPL_HPP__

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	<GL/glut.h>
# include	<GL/freeglut.h>
# include	<time.h>
# include	<iostream>
# include	<unistd.h>
# include	"../common/AGraph.hpp"
# include	"../../src/Snake.hpp"

# define	LEN		((CASE_SIZE / 2) - 0)
# define	ZLEN		(LEN)
# define	DEFAULT_R	(0)
# define	DEFAULT_G	(80)
# define	DEFAULT_B	(160)

class OpenGLImpl : public AGraph {
private:
  Snake		*_snake;
  int		_xcam;
  int		_ycam;
  int		_zcam;
  double	_ind;
  int		_r;
  int		_g;
  int		_b;
  int		_easterEgg;
  int		_pause;
public:
  OpenGLImpl(int, int);
  OpenGLImpl(const OpenGLImpl &);
  ~OpenGLImpl(void);
  OpenGLImpl	&operator=(const OpenGLImpl &);
  Snake		*getSnake(void) const;
  void		setXCam(int);
  int		getXCam(void) const;
  void		setYCam(int);
  int		getYCam(void) const;
  void		setZCam(int);
  int		getZCam(void) const;
  void		setIndice(double);
  double	getIndice(void) const;
  void		setR(int);
  int		getR(void) const;
  void		setG(int);
  int		getG(void) const;
  void		setB(int);
  int		getB(void) const;
  void		setEasterEgg(int);
  int		getEasterEgg(void) const;
  void		setPause(int);
  int		getPause(void) const;
  int		getRandomRGB(void) const;
  float		getRandomCoord(void) const;
  void		drawBottomFace(int, int, int, int, int, int) const;
  void		drawTopFace(int, int, int, int, int, int) const;
  void		drawFrontFace(int, int, int, int, int, int) const;
  void		drawBackFace(int, int, int, int, int, int) const;
  void		drawLeftFace(int, int, int, int, int, int) const;
  void		drawRightFace(int, int, int, int, int, int) const;
  void		drawCube(int, int, int, int, int, int) const;
  void		drawRandomCube(int, int, int, int, int, int) const;
  void		printRandomWalls(void) const;
  void		printWalls(void) const;
  void		printFood(void) const;
  void		printSnake(void);
  void		init(Snake *);
  int		display(void);
  int		getEvent(void);
  void		close(void);
};

#endif		/* !__OPENGLIMPL_HPP__ */
