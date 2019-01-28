##
## EPITECH PROJECT, 2018
## Makefile bootsrap
## File description:
## hunter
##

INC_DIR	=	./include

CC	=	gcc

SRC	=	src/norm.c	\
		src/my_putstr.c	\
		src/my_putchar.c	\
		src/start.c	\
		src/move.c	\
		src/score_life.c	\
		print/*.c	\

LDFLAGS	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-network -g3

NAME	=	my_hunter

all:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
