/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:07 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/27 18:18:33 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_vars *vars)
{
	t_game	*game;

	game = vars->game;
	if (game->map_matrix[game->p_y][game->p_x + 1] != '1')
	{
		if (game->map_matrix[game->p_y][game->p_x + 1] == 'C')
			game->coins--;
		if (game->map_matrix[game->p_y][game->p_x + 1] == 'E')
		{
			if (game->coins == 0)
				ft_close (vars);
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
	t_game	*game;

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
	t_game	*game;

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
	t_game	*game;

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
