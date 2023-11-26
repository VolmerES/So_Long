/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/26 20:22:02 by jdelorme         ###   ########.fr       */
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
# define RED_TEXT 		"\033[31m"

typedef struct s_game t_game;
typedef struct s_vars t_vars;
int	ft_close(t_vars *vars);

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
}				t_vars;

typedef struct s_game
{
	char	*player_img;
	char	*wall_img;
	char	*exit_img;
	char	*ground_img;
	char	*collectable_img;
	char	*game;
	char 	*map_line;
	char	**map_matrix;
	char	**map_matrix_copy;
	int		map_x;
	int		map_y;
	int		p_y;
	int		p_x;
	int		img_width;
	int		img_height;
	int		coins;
	int		steps;
	int		step_flag;
}				t_game;

int	ft_count_steps(t_game *game)
{
	if (game->step_flag == 1)
	{
		ft_putstr_fd("Steps: ", 1);
		ft_putnbr_fd(game->steps, 1);
		ft_putchar_fd('\n', 1);
		game->step_flag = 0;
	}
	return (0);
}
void	ft_error(char *error)
{
	ft_putstr_fd (error, 1);
	exit (1);
}

// !  ||||  MOVIMIENTO JUGADOR   ||||

void	ft_move_right(t_vars *vars)
{
	t_game *game;

	game = vars->game;
	
	if (game->map_matrix[game->p_y][game->p_x + 1] != '1')
	{
		if (game->map_matrix[game->p_y][game->p_x + 1] == 'C')
			game->coins--;
		if (game->map_matrix[game->p_y][game->p_x + 1] == 'E')
			{
				if (game->coins == 0)
					ft_close(vars);	
				else
					return ;
			}
		game->map_matrix[game->p_y][game->p_x] = '0';
		game->map_matrix[game->p_y][game->p_x + 1] = 'P';
		game->p_x += 1;
		game->steps++;
		game->step_flag = 1; 
	}
}
void	ft_move_up(t_vars *vars)
{
	t_game *game;

	game = vars->game;
	
	if (game->map_matrix[game->p_y - 1][game->p_x] != '1')
	{
		if (game->map_matrix[game->p_y - 1][game->p_x] == 'C')
			game->coins--;
		if (game->map_matrix[game->p_y - 1][game->p_x] == 'E')
			{
				if (game->coins == 0)
					ft_close(vars);	
				else
					return ;
			}
		game->map_matrix[game->p_y][game->p_x] = '0';
		game->map_matrix[game->p_y - 1][game->p_x] = 'P';
		game->p_y -= 1;
		game->steps++;
		game->step_flag = 1;
	}
}
void	ft_move_down(t_vars *vars)
{
	t_game *game;

	game = vars->game;
	
	if (game->map_matrix[game->p_y + 1][game->p_x] != '1')
	{
		if (game->map_matrix[game->p_y + 1][game->p_x] == 'C')
			game->coins--;
		if (game->map_matrix[game->p_y + 1][game->p_x] == 'E')
			{
				if (game->coins == 0)
					ft_close(vars);	
				else
					return ;
			}
		game->map_matrix[game->p_y][game->p_x] = '0';
		game->map_matrix[game->p_y + 1][game->p_x] = 'P';
		game->p_y += 1;
		game->steps++;
		game->step_flag = 1;
	}
}
void	ft_move_left(t_vars *vars)
{
	t_game *game;

	game = vars->game;
	
	if (game->map_matrix[game->p_y][game->p_x - 1] != '1')
	{
		if (game->map_matrix[game->p_y][game->p_x - 1] == 'C')
			game->coins--;
		if (game->map_matrix[game->p_y][game->p_x - 1] == 'E')
			{
				if (game->coins == 0)
					ft_close(vars);	
				else
					return ;
			}
		game->map_matrix[game->p_y][game->p_x] = '0';
		game->map_matrix[game->p_y][game->p_x - 1] = 'P';
		game->p_x -= 1;
		game->steps++;
		game->step_flag = 1;
	}
}

// !  ||||  PONER IMAGENES EN MAPA   ||||


void	ft_put_img(t_vars *vars)
{
	int		y;
	int		x;
	
	t_game *game;

	game = vars->game;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, game->player_img, game->p_x * 128, game->p_y * 128);
	ft_count_steps(game);
	y = -1;
	while (game->map_matrix[++y])
	{
		x = -1;
		while (game->map_matrix[y][++x])
		{
			if (game->map_matrix[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, game->wall_img, x * 128, y * 128);
			if (game->map_matrix[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, game->collectable_img, x * 128, y * 128);
			if (game->map_matrix[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, game->exit_img, x * 128, y * 128);
			if (game->map_matrix[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, game->ground_img, x * 128, y * 128);
		}
	}
}
int	ft_set_img(t_vars *vars)
{
	t_game *game;

	game = vars->game;
	game->player_img = mlx_xpm_file_to_image(vars->mlx, "./img/Hobbit.xpm", &game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(vars->mlx, "./img/Walls.xpm", &game->img_width, &game->img_height);
	game->collectable_img = mlx_xpm_file_to_image(vars->mlx, "./img/Collectable.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(vars->mlx, "./img/Exit.xpm", &game->img_width, &game->img_height);
	game->ground_img = mlx_xpm_file_to_image(vars->mlx, "./img/Ground.xpm", &game->img_width, &game->img_height);
	ft_put_img(vars);
	return (0);
}

 // !    |||| CHECK FOR VALID PATH ||||
 
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
	int	valid;
	int	y;
	
	y = 0;
	valid = ft_path_cross_checker(game->map_matrix_copy, game->p_y, game->p_x);
	if (valid  == 0)
		ft_error("ERROR: No avaliable path");
	ft_check_for_collectables(game);
	while (game->map_matrix_copy[y])
		free (game->map_matrix_copy[y++]);
	free (game->map_matrix_copy);
}
 
 // !  ||||   CHECK FOR VALID MAP   ||||

 
void	ft_check_for_elements(t_game *game)
{
	int y;
	int k;
	int e;
	int x;

	y = -1;
	game->coins = 0;
	k = 0;
	e = 0;
	while (game->map_matrix[++y])
	{
		x = -1;
		while (game->map_matrix[y][++x])
		{
			if (game->map_matrix[y][x] == 'C')
				game->coins++;
			if (game->map_matrix[y][x] == 'E')
				k++;
			if (game->map_matrix[y][x] == 'P')
				e++;
		}
	}
	if (game->coins < 1 || k != 1 || e != 1)
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
// !   ||||   MLX INIT AND READ MAP   ||||
void	ft_read_map(t_game *game, char *arg)
{
	char	readed;
	char	*temp_map_line;
	int		fd;
	
	readed = 0;
	temp_map_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
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
	game->map_matrix_copy = ft_split(temp_map_line, '\n');
	printf("PRIMER CHECK:\n%s\n", temp_map_line);
	free (temp_map_line);
	close(fd);
	ft_check_valid_map(game);
}

int	ft_deal_key(int key, t_vars *vars)
{
	if (key == KEY_A || key == ARROW_LEFT)
		ft_move_left(vars);
	if (key == KEY_W || key == ARROW_UP)
		ft_move_up(vars);
	if (key == KEY_S || key == ARROW_DOWN)
		ft_move_down(vars);
	if (key == KEY_D || key == ARROW_RIGHT)
		ft_move_right(vars);
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
void	ft_check_ber(char *arg)
{
	size_t	i;

	i = ft_strlen(arg);
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b' || arg[i - 4] != '.')
		ft_error("ERROR: Wrong map extension");
}
void	ft_mlx_initialiter(t_vars *vars, t_game *game)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, game->map_x * 128, game->map_y * 128 , "so_long");
}
int	main(int argc, char **argv)
{
	// ! Funcion para contar los pasos reales que da el jugador 					
	// ! Establecer la animaicones
	
	t_game	game;
	t_vars	vars;
	int		fd;
	
	if (argc != 2)
		ft_error("ERROR: Not valid arguments");
	vars.game = &game;
	ft_check_ber(argv[1]);
	ft_read_map(&game, argv[1]);
	ft_mlx_initialiter(&vars, &game);
	mlx_key_hook(vars.mlx_win, ft_deal_key, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_close, &vars);
	mlx_loop_hook(vars.mlx, ft_set_img, &vars);
	//mlx_loop_hook(vars.mlx, &loop_hook, &game);
	mlx_loop(vars.mlx);
	return 0;
}
