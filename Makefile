##
## EPITECH PROJECT, 2019
## makz
## File description:
## makz
##

SRC	=	src/bsq.c	\
		src/count.c	\
		src/my_putchar.c	\
		src/algo.c	\
		src/find_big.c	\
		src/open.c

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all
