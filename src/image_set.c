/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:15 by jdelorme          #+#    #+#             */
/*   Updated: 2024/02/02 14:32:48 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_put_img_util(t_vars *vars, int y, int x)
{
	if (vars->game->map_matrix[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->wall_img, x * 128, y * 128);
	if (vars->game->map_matrix[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->collectable_img, x * 128, y * 128);
	if (vars->game->map_matrix[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->exit_img, x * 128, y * 128);
	if (vars->game->map_matrix[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->game->ground_img, x * 128, y * 128);
}

void	ft_put_img(t_vars *vars)
{
	int		y;
	int		x;

	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->game->player_img, vars->game->p_x * 128, vars->game->p_y * 128);
	ft_count_steps(vars);
	y = -1;
	while (vars->game->map_matrix[++y])
	{
		x = -1;
		while (vars->game->map_matrix[y][++x])
		{
			ft_put_img_util(vars, y, x);
		}
	}
	ft_steps_window(vars);
}

int	ft_set_img(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	game->player_img = mlx_xpm_file_to_image(vars->mlx, "./img/Hobbit.xpm",
			&game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(vars->mlx, "./img/Walls.xpm",
			&game->img_width, &game->img_height);
	game->collectable_img = mlx_xpm_file_to_image(vars->mlx,
			"./img/Collectable.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(vars->mlx, "./img/Exit.xpm",
			&game->img_width, &game->img_height);
	game->ground_img = mlx_xpm_file_to_image(vars->mlx, "./img/Ground.xpm",
			&game->img_width, &game->img_height);
	ft_put_img(vars);
	return (0);
}
