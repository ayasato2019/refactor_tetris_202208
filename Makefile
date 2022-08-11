NAME	:=	tetris
CFLAGS	:=

SRCS	:=	tetris.c \
		init_game.c \
		game_loop.c \
		finish_game.c \
		common.c \
		shape.c \
		display.c \
		time.c
OBJS	:=	$(SRCS:.c=.o)

RM		:= 	rm -rf
.PHONY:	all clean fclean re
all: $(NAME)
$(NAME):	$(OBJS)
	gcc $(CFLAGS) -lncurses -o $@ $^
clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)
re:		fclean all