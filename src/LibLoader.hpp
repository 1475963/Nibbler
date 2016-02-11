//
// LibLoader.hpp for LibLoader in /home/benzah_m/rendu/cpp_nibbler/src
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 15:26:35 2014 benzah_m
// Last update Fri Apr  4 20:57:42 2014 benzah_m
//

#ifndef		__LIBLOADER_HPP__
# define	__LIBLOADER_HPP__

# include	<string>
# include	<dlfcn.h>
# include	"../libs/common/AGraph.hpp"

# define	LOADER ("load")
# define	UNLOADER ("unload")

typedef AGraph	*(*loadFunct)	(int, int);
typedef void	(*unloadFunct)	(AGraph *);

class LibLoader {
private:
  void		*_handler;
  loadFunct	_loader;
  unloadFunct	_unloader;
public:
  LibLoader(void);
  LibLoader(const LibLoader &);
  ~LibLoader(void);
  LibLoader	&operator=(const LibLoader &);
  void		setHandler(void *);
  void		*getHandler(void);
  AGraph	*load(const std::string &, int, int);
  void		unload(AGraph *);
};

#endif		/* !__LIBLOADER_HPP__ */
