##
## EPITECH PROJECT, 2017
## makefile
## File description:
## my_screensaver
##

SRC	=	src/my_screensaver.c

CFLAGS += -Wall -Wextra

SRC_LIB	=	src/my_printf.c	\
		src/libprintf.c	\
		src/my_screensaver1.c	\
		src/my_screensaver2.c	\
		src/my_screensaver3.c

OBJ	=	$(SRC:.c=.o)

OBJ_LIB	=	$(SRC_LIB:.c=.o)

NAME	=	my_screensaver

NAME1	=	libmy.a

all: $(NAME1) $(NAME)

$(NAME1):	$(OBJ_LIB)
	ar rc $(NAME1) $(OBJ_LIB)

$(NAME):	$(OJB)
	gcc $(SRC) -o $(NAME) $(NAME1) -lc_graph_prog -lm -g

clean:
	rm -f $(OBJ) $(OBJ_LIB)

fclean:	clean
	rm -f $(NAME) $(NAME1)

re:	fclean all

.PHONY:	all re clean fclean
