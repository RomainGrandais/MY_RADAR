##
## EPITECH PROJECT, 2022
## task02 Makefile
## File description:
## This will help compile code for task 02
##

SRC	=	src/main.c	\
		src/count_a_and_t.c	\
		src/set_window.c	\
		src/my_radar.c	\
		src/display_tower.c	\
		src/display_plane.c	\
		src/moove_plane.c	\
		src/timer.c	\
		src/end_radar.c	\
		src/display_usage.c	\
		src/message.c	\
		src/if_collision.c	\
		src/destroy.c	\

# this will do the first step of compilation automatically
OBJ	=	$(SRC:.c=.o)
# this will only be used in the first step of compilation
INC	=	-I include/ -I lib/my/include/

CRITERION	=	tests/testing.c

NAME	=	my_radar

INSERT_LIB	=	-Llib/my -lmy

UNIT_TEST_NAME	=	unit_tests

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	compile_lib
	gcc -o $(NAME) $(SRC) $(INSERT_LIB) $(INC) $(CSFML) -g -lm

compile_lib 	:
			$(MAKE) -C lib/my re

clean:
	rm -f $(OBJ)
	rm -f *~ *.o vgcore*

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && make clean

re:	fclean all

compile_test:	compile_lib
		gcc -o $(UNIT_TEST_NAME) $(CRITERION)\
		$(INSERT_LIB) $(CFLAGS) --coverage -lcriterion -g

tests_run:	fclean compile_test
