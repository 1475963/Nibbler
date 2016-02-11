##
## Makefile for make in /home/benzah_m/rendu/cpp_nibbler
## 
## Made by benzah_m
## Login   <benzah_m@epitech.net>
## 
## Started on  Thu Mar 13 11:50:53 2014 benzah_m
## Last update Sun Apr  6 20:35:40 2014 dequid_v
##

GL_SRC		=	libs/common/AGraph.cpp		\
			libs/opengl/OpenGLImpl.cpp	\
			src/Food.cpp			\
			src/Maillon.cpp			\
			src/Walls.cpp			\
			src/Snake.cpp			

SDL_SRC		=	libs/common/AGraph.cpp		\
			libs/sdl/SDLImpl.cpp		\
			src/Food.cpp			\
			src/Maillon.cpp			\
			src/Walls.cpp			\
			src/Snake.cpp			

NCURSE_SRC	=	libs/common/AGraph.cpp		\
			libs/ncurse/NCurseImpl.cpp	\
			src/Food.cpp			\
			src/Maillon.cpp			\
			src/Walls.cpp			\
			src/Snake.cpp			

SRC		=	src/main.cpp		\
			src/Core.cpp		\
			src/LibLoader.cpp	\
			src/Food.cpp		\
			src/Maillon.cpp		\
			src/Walls.cpp		\
			src/Snake.cpp		\
			src/Menu.cpp

GL_OBJ		=	$(GL_SRC:.cpp=.o)

SDL_OBJ		=	$(SDL_SRC:.cpp=.o)

NCURSE_OBJ	=	$(NCURSE_SRC:.cpp=.o)

OBJ		=	$(SRC:.cpp=.o)

GL_NAME		=	lib_nibbler_opengl.so

SDL_NAME	=	lib_nibbler_sdl.so

NCURSE_NAME	=	lib_nibbler_ncurse.so

NAME		=	nibbler

GL_LIB		=	-lGL -lGLU -lglut

SDL_LIB		=	-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

NCURSE_LIB	=	-lncurses

NAME_LIB	=	-ldl

CC		=	g++

LINKLIB		=	-shared -fPIC

CXXFLAGS	=	-fPIC -W -Wall -Wextra -Werror

RM		=	rm -f

all:	 $(SDL_NAME) $(NCURSE_NAME) $(GL_NAME) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(NAME_LIB) $(SDL_LIB)

$(GL_NAME):	$(GL_OBJ)
	$(CC) $(LINKLIB) $(GL_OBJ) -o $(GL_NAME) $(GL_LIB)

$(SDL_NAME):	$(SDL_OBJ)
	$(CC) $(LINKLIB) $(SDL_OBJ) -o $(SDL_NAME) $(SDL_LIB)

$(NCURSE_NAME):	$(NCURSE_OBJ)
	$(CC) $(LINKLIB) $(NCURSE_OBJ) -o $(NCURSE_NAME) $(NCURSE_LIB)

clean:	
	$(RM) $(OBJ) $(GL_OBJ) $(SDL_OBJ) $(NCURSE_OBJ)

fclean:	clean
	$(RM) $(NAME) $(GL_NAME) $(SDL_NAME) $(NCURSE_NAME)

re:	fclean all

.PHONY:	all clean fclean re
