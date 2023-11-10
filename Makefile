NAME = so_long.a
CC = gcc
SRC = so_long.c


OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
OBJS_BONUS = $(SRC_BONUS:.c=.o )
MLX_FLAGS = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -crs  $@ $?

%.o : %.c
	@$(CC) -c $(CFLAGS) $(MLX_FLAGS) $?

BONUS : $(OBJS_BONUS) $(OBJS)
	@ar -crs $(NAME) $?

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: BONUS

.PHONY : clean fclean bonus
