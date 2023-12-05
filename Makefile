NAME = so_long
CC = gcc
SRC =	so_long.c \
		image_set.c \
		mlx_utils.c \
		player_movement.c \
		valid_map.c \
		valid_path.c


OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
OBJS_BONUS = $(SRC_BONUS:.c=.o )
MLX_FLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -LLibft -lft
MLX_LIB = ./mlx/libmlx.a
FT_LIB = ./libft/libft.a

all : $(NAME)
	@echo "\x1b[32m Compilacion so_long: OK"

$(NAME) : $(OBJS) $(MLX_LIB) $(FT_LIB)
	@$(CC)  $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB) : 
	@make -C ./mlx/

$(FT_LIB) : 
	@make -C ./libft/

%.o : %.c
	@$(CC) -c $(CFLAGS) $?

BONUS : $(OBJS_BONUS) $(OBJS)
	@ar -crs $(NAME) $?

clean:
	@rm -f *.o
	@make clean -C ./libft/
	@make clean -C ./mlx/
run:
	./$(NAME) ./Maps/map.ber

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

bonus: BONUS

.PHONY : clean fclean bonus run
