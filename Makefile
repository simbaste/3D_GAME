##
## Makefile for Makefile in /home/simomb_s/semestre1/tests_maison/TP_systeme_unix/TP1
##
## Made by stephanedarcy simomba
## Login   <simomb_s@epitech.net>
##
## Started on  Mon Nov 24 10:58:02 2014 stephanedarcy simomba
## Last update Sun Jan  4 18:53:41 2015 stephanedarcy simomba
##

SRC		= main.c\
		even.c\
		init_img.c\
		my_map.c\

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -W -Wall -Wextra -g3
CFLAGS		+=
LDFLAGS		+=

NAME		= wolf3d

all		: cmp_minilibx cmp_lib $(NAME)

cmp_lib		:
		cd lib/my && make

cmp_minilibx	:
		cd minilibx && make

$(NAME)		: $(OBJ)
		cc -o $(NAME) $(OBJ) -lmy -lm -L lib -L /usr/lib64 -lmlx_$(HOSTTYPE) -L /usr/lib64/X11 -lXext -lX11 -L minilibx

clean		:
		rm -rf $(OBJ)
		cd lib/my && make clean
		cd minilibx && make clean

fclean		: clean
		rm -rf $(NAME)

re		: fclean all

.PHONY		:
		all clean fclean re
