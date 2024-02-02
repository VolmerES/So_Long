NAME = libft.a
CC = gcc
SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		ft_split.c

SRC_BONUS = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
OBJS_BONUS = $(SRC_BONUS:.c=.o )

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\x1b[32m Compilacion LIBFT: OK"
	@ar -crs  $@ $?

%.o : %.c
	@$(CC) -c $(CFLAGS) $?

BONUS : $(OBJS_BONUS) $(OBJS)
	@ar -crs $(NAME) $?

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: BONUS

.PHONY : clean fclean bonus
