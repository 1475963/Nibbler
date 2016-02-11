//
// main.cpp for main in /home/benzah_m/rendu/cpp_nibbler/src
// 
// Made by benzah_m
// Login   <benzah_m@epitech.net>
// 
// Started on  Mon Mar 31 16:16:20 2014 benzah_m
// Last update Sun Apr  6 18:01:05 2014 benzah_m
//

#include "Core.hpp"

int		main(int ac, char **av) {
  if (ac != 4)
    {
      std::cout << "Usage :\t./nibbler width height lib_name" << std::endl;
      return (-1);
    }
  try
    {
      std::string	lib(av[3]);
      Core		*core = new Core(av[1], av[2], lib);
      core->run();
      delete (core);
    }
  catch (const char *msg)
    {
      std::cerr << msg << std::endl;
    }
  return (0);
}
