##
## EPITECH PROJECT, 2018
## my_rpg_2017
## File description:
## Makefile
##

CC		=	gcc

CFLAGS		=	-Wall -Wextra -std=c99 -g -g3

CFLAGS_TEST	=	--coverage

LDFLAGS		=	-lc_graph_prog -lm -L lib/ -lmy -L lib/ -lcl -Wl,-rpath='lib/lua/' -L lib/lua/ -llua

LDFLAGS_TEST	=	-lcriterion -lgcov

NAME		=	my_rpg

SRC		=	src/draw/anim.c			\
			src/draw/interface.c		\
			src/draw/map.c			\
			src/draw/sprite_anim.c		\
			src/draw/sprite.c		\
			src/draw/tile.c			\
			src/event/event.c		\
			src/lua/lua_table_get.c		\
			src/lua/lua_table_goto.c	\
			src/ressource/ressource.c	\
			src/ressource/tileset.c		\
			src/state/interface.c		\
			src/state/play_loader.c		\
			src/state/play.c		\
			src/utils/utils0.c		\
			src/managers/state_manager.c	\
			src/game.c			\
			src/main.c			\
			src/rpg.c			\

OBJ		=	$(SRC:.c=.o)

INCLUDE		=	-I include

TEST		=	tests/tests

SRC_TEST	=

OBJ_TEST	=	$(filter-out src/main.o, $(OBJ))	\
			$(SRC_TEST:.c=.o)			\

.PHONY:	all tests_run clean fclean lib

all:	$(NAME) clean

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

fclean:	clean
	make -C lib/my fclean
	#make -C lib/lizz_overlay fclean
	make -C lib/cl fclean
	rm -f $(NAME)
	rm -f $(TEST)
	find -name '*.gc*' -delete
	find -name 'vgcore.*' -delete
	find -name '.gcov*' -delete
	find -name '*.gch' -delete

re: fclean all
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

tests_run:	$(TEST) clean
	./$(TEST)

$(NAME):	lib obj
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

lib:
	make -C lib/my
	#make -C lib/lizz_overlay
	make -C lib/cl

obj:
	$(foreach src, $(SRC), $(CC) $(CFLAGS) -c $(src) $(INCLUDE) -o $(src:.c=.o);)

$(TEST):	lib obj_test
	$(CC) -o $(TEST) $(OBJ_TEST) $(LDFLAGS) $(LDFLAGS_TEST)

obj_test:
	$(foreach src, $(filter-out src/main.c, $(SRC)), $(CC) $(CFLAGS) $(CFLAGS_TEST) $(INCLUDE) -c $(src) -o $(src:.c=.o);)
	$(foreach src, $(SRC_TEST), $(CC) $(CFLAGS) $(INCLUDE) -c $(src) -o $(src:.c=.o);)

gcov:
	gcov -abcfu $(filter-out src/main.c, $(SRC))
