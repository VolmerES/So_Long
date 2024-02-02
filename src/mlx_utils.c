/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:51:20 by jdelorme          #+#    #+#             */
/*   Updated: 2024/02/02 16:56:19 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_mlx_initialiter(t_vars *vars, t_game *game)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx,
			game->map_x * 128, game->map_y * 128, "so_long");
}

int	ft_close(t_vars *vars)
{
	ft_count_steps(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
	return (0);
}

void	ft_steps_window(t_vars *vars)
{
	char	*str;
	char	*aux;

	str = ft_itoa(vars->game->steps);
	aux = ft_strjoin("Steps: ", str);
	mlx_string_put(vars->mlx, vars->mlx_win, 50, 50, 0x00FF0000, aux);
	free (str);
	free (aux);
}

int	ft_count_steps(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
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
