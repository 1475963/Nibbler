//
// LibLoader.cpp for LibLoader in /home/benzah_m/rendu/cpp_nibbler/src
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Fri Mar 14 15:26:18 2014 benzah_m
// Last update Sun Apr  6 23:25:46 2014 benzah_m
//

#include "LibLoader.hpp"

LibLoader::LibLoader(void) {
  this->_handler = NULL;
  this->_loader = NULL;
  this->_unloader = NULL;
}

LibLoader::LibLoader(const LibLoader &loader) {
  if (this != &loader)
    {
      this->_handler = loader._handler;
      this->_loader = loader._loader;
      this->_unloader = loader._unloader;
    }
}

LibLoader::~LibLoader(void) {
}

LibLoader	&LibLoader::operator=(const LibLoader &loader) {
  if (this != &loader)
    {
      this->_handler = loader._handler;
      this->_loader = loader._loader;
      this->_unloader = loader._unloader;
    }
  return (*this);
}

void		LibLoader::setHandler(void *handler) {
  this->_handler = handler;
}

void		*LibLoader::getHandler(void) {
  return (this->_handler);
}

AGraph		*LibLoader::load(const std::string &filename, int x, int y) {
  if (this->getHandler() != NULL)
    throw ("Library already loaded");
  this->setHandler(dlopen(filename.data(), RTLD_LAZY | RTLD_GLOBAL));
  if (this->getHandler() != NULL)
    {
      this->_loader = (loadFunct) (dlsym(this->getHandler(), LOADER));
      this->_unloader = (unloadFunct) (dlsym(this->getHandler(), UNLOADER));
      if (this->_loader && this->_unloader)
	return (this->_loader(x, y));
      else
	throw ("Functions not found in library");
    }
  throw (dlerror());
  return (NULL);
}

void		LibLoader::unload(AGraph *graph) {
  if (this->getHandler() == NULL)
    throw ("Library already unloaded");
  this->_unloader(graph);
}
