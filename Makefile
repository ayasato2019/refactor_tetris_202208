NAME	=	tetris

CFLAGS	=

# SRCS	=	./srcs/tetris.c \
# 		./srcs/init_game.c \
# 		./srcs/game_loop.c \
# 		./srcs/finish_game.c \
# 		./srcs/common.c \
# 		./srcs/shape.c \
# 		./srcs/display.c \
# 		./srcs/time.c

SRCS	=	tetris.c \
		init_game.c \
		game_loop.c \
		finish_game.c \
		common.c \
		shape.c \
		display.c \
		time.c

SRCS := $(SRCS:%=srcs/%)

HEADERS = ./includes/all_headers.h \
		./includes/types.h \
		./includes/tetris.h

OBJS	=	$(SRCS:%.c=%.o)

RM		= 	rm -rf

all: $(NAME)

$(NAME):	 $(OBJS)
	gcc $(CFLAGS) -lncurses -o $@ $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re