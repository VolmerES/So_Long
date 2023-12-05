#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -DGL_SILENCE_DEPRECATION

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\x1b[32m Compilacion MLX: OK"
	@ar -r $(NOM) $(OBJ) > /dev/null 2>&1
	@ranlib $(NOM) > /dev/null 2>&1

%.o: %.c
	@gcc -Wdeprecated-declarations -Wno-deprecated-declarations -DSTRINGPUTX11 -DGL_SILENCE_DEPRECATION -c $< -o $@

mlx_new_window.o: mlx_new_window.m
	@gcc -Wdeprecated-declarations -Wno-deprecated-declarations -DSTRINGPUTX11 -DGL_SILENCE_DEPRECATION -c $< -o $@

%.o: %.m
	@gcc -Wdeprecated-declarations -Wno-deprecated-declarations -DSTRINGPUTX11 -DGL_SILENCE_DEPRECATION -c $< -o $@ > /dev/null 2>&1

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
