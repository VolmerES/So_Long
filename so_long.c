/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/27 18:34:16 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_game *game, char *arg)
{
	char	readed;
	char	*temp_map_line;
	int		fd;

	readed = 0;
	temp_map_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_map_line)
		return ;
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
	return (0);
}

void	ft_check_ber(char *arg)
{
	size_t	i;

	i = ft_strlen(arg);
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e'
		||arg[i - 3] != 'b' || arg[i - 4] != '.')
		ft_error("ERROR: Wrong map extension");
}

int	main(int argc, char **argv)
{
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
	mlx_loop(vars.mlx);
	return (0);
}
