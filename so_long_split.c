/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/23 19:25:18 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define RED_TEXT "\033[31m"

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}				t_vars;

typedef struct s_game
{
	char	*game;
	char 	*map_line;
	char	**map_matrix;
	char	**map_matrix_copy;
	int		map_x;
	int		map_y;
	int		p_y;
	int		p_x;
}				t_game;

void	ft_error(char *error)
{
	ft_putstr_fd (error, 1);
	exit (1);
}
void	ft_check_for_collectables(t_game *game)
{
	int	y;
	int x;
	
	y = -1;
	while (game->map_matrix_copy[++y])
	{
		x = -1;
		while (game->map_matrix_copy[y][++x])
		{
			if (game->map_matrix_copy[y][x] == 'C')
			{
				ft_error("ERROR: Not all collectables are reachable");
				free (game->map_matrix_copy);
			}
		}
	}
}
int	ft_path_cross_checker(char **map_matrix_copy, int p_y, int p_x)
{
	int	flag;
	
	flag = 0;
	if (map_matrix_copy[p_y][p_x] == 'E')
		return (1);
	else
		map_matrix_copy[p_y][p_x] = '1';
	if (map_matrix_copy[p_y][p_x + 1] != '1')
		flag += ft_path_cross_checker(map_matrix_copy, p_y, p_x + 1);
	if (map_matrix_copy[p_y][p_x - 1] != '1')
		flag += ft_path_cross_checker(map_matrix_copy, p_y, p_x - 1);
	if (map_matrix_copy[p_y + 1][p_x] != '1')
		flag += ft_path_cross_checker(map_matrix_copy, p_y + 1, p_x);
	if (map_matrix_copy[p_y - 1][p_x] != '1')
		flag += ft_path_cross_checker(map_matrix_copy, p_y - 1, p_x);
	return (flag);
}
void	ft_check_for_path_recursive(t_game *game)
{
	int	y;
	int	valid;
	int x;
	
	y = -1;
	game->map_matrix_copy = (char **)malloc((game->map_y + 1) * (sizeof (char *)));
	while (game->map_matrix[++y])
	{
		game->map_matrix_copy[y] = ft_strdup(game->map_matrix[y]),
		printf("SEGUNDO CHECK:\n%s\n", game->map_matrix_copy[y]);
	}
	valid = ft_path_cross_checker(game->map_matrix_copy, game->p_y, game->p_x);
	if (valid  == 0)
		ft_error("ERROR: No avaliable path");
	ft_check_for_collectables(game);
	free (game->map_matrix_copy);
}
 
void	ft_check_for_elements(t_game *game)
{
	int y;
	int j;
	int k;
	int e;
	int x;

	y = -1;
	j = 0;
	k = 0;
	e = 0;
	while (game->map_matrix[++y])
	{
		x = -1;
		while (game->map_matrix[y][++x])
		{
			if (game->map_matrix[y][x] == 'C')
				j++;
			if (game->map_matrix[y][x] == 'E')
				k++;
			if (game->map_matrix[y][x] == 'P')
				e++;
		}
	}
	if (j != 1 || k != 1 || e != 1)
		ft_error("Error: Invalid Map (Not enough elements)");
}

void	ft_check_for_characters(t_game *game)
{
	int	x;
	int y;
	
	x = -1;
	y = -1;
	while (game->map_matrix[++y])
	{
		x = -1;
		while (game->map_matrix[y][++x]) 
		{
			if (game->map_matrix[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
			}
			if (((game->map_matrix[y][x] != 'C'
					&& game->map_matrix[y][x] != 'E' &&
					game->map_matrix[y][x] != 'P' && game->map_matrix[y][x] != '1' &&
					game->map_matrix[y][x] != '0')))
			{
				ft_error("ERROR: Invalid map (Invalid characters)");
			}
		}
	}
}

void	ft_check_for_walls(t_game *game)
{
	int	x;
	int y;
	
	y = -1;
	printf("NUMERO FILAS:%i \n", game->map_y);
	while (game->map_matrix[++y])
	{
		x = -1;
		while (game->map_matrix[y][++x])
		{
			if (game->map_matrix[0][x] != '1'|| game->map_matrix[game->map_y - 1][x] != '1')
				ft_error("ERROR: Invalid map (Not surrounded by walls)");
			else if (game->map_matrix[y][0] != '1' || game->map_matrix[y][game->map_x - 1] != '1')
				ft_error("ERROR: Invalid map (Not surrounded by walls)");
		}
	}
}
void	ft_check_for_rectangle(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	game->map_x = ft_strlen(game->map_matrix[j]);
	j = -1;
	while(game->map_matrix[++j])
	{
		if(game->map_x != ft_strlen(game->map_matrix[j]))
			ft_error("ERROR: Invalid map (Not rectangular)");
	}
	game->map_y = j;
}

void	ft_check_valid_map(t_game *game)
{
	ft_check_for_elements(game);
	ft_check_for_characters(game);
	ft_check_for_rectangle(game);
	ft_check_for_walls(game);
	ft_check_for_path_recursive(game);
}
void	ft_read_map(t_game *game, char *arg)
{
	char	readed;
	char	*temp_map_line;
	int		fd;
	
	readed = 0;
	temp_map_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_map_line)
		return;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		free (temp_map_line);
		ft_error("ERROR: The map could not be read");
	}
	readed = read(fd, temp_map_line, BUFFER_SIZE);
	if (readed == -1)
	{
		free (temp_map_line);
		ft_error("ERROR: The map could not be read");
	}
	game->map_matrix = ft_split(temp_map_line, '\n');
	printf("PRIMER CHECK:\n%s\n", temp_map_line);
	free (temp_map_line);
	close(fd);
	ft_check_valid_map(game);
}

int	ft_deal_key(int key, t_vars *vars)
{
	if (key == KEY_A)
		printf("Ha presionado A \n");
	if (key == KEY_W)
		printf("Ha presionado W \n");
	if (key == KEY_S)
		printf("Ha presionado S \n");
	if (key == KEY_D)
		printf("Ha presionado D \n");
	if (key == ARROW_RIGHT)
		printf("Ha presionado DERECHA \n");
	if (key == ARROW_LEFT)
		printf("Ha presionado IZQUIERDA \n");
	if (key == ARROW_DOWN)
		printf("Ha presionado ABAJO \n");
	if (key == ARROW_UP)
		printf("Ha presionado ARRIBA \n");
	if (key == KEY_ESC)
	{
		printf("Ha presionado ESC \n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit (1);
	}
	return 0;
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (1);
	return (0);
}
// void	ft_check_ber(char *arg)
// {
// 	int	i;

// 	i = ft_strlen((arg) - 1);
// 	if (arg[i] != 'r' || arg[i - 1] != 'e' || arg[i - 2] != 'b' || arg[i - 3] != '.')
// 		ft_error("ERROR: Wrong map extension");
// }
int	main(int argc, char **argv)
{
	// ! Estructurar mi main con argumentos
	// ! Llamar a funcion para verificar si es .ber
	// ! Funcion para contar los pasos reales que da el jugador 					
 	// ! Que el jugador no pueda entrar dentro de las paredes
	// ! Establecer la imagenes y el movimiento del jugador
	// ! Establecer la animaicones
	// ! Establecer un limite de mapa.
	// ! Cambiar el printf por el mio.
	
	t_game	game;
	t_vars	vars;
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_error("ERROR: Not valid arguments");
	//ft_check_ber(argv[1]);
	ft_read_map(&game, argv[1]);
	close (fd);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1080, 1080, "so_long");
	mlx_key_hook(vars.mlx_win, ft_deal_key, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
