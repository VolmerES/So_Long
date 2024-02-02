/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:47:30 by jdelorme          #+#    #+#             */
/*   Updated: 2024/02/02 16:52:00 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_for_elements(t_game *game)
{
	int	y;
	int	k;
	int	e;
	int	x;

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
		ft_error("Error\n Invalid Map (Not enough elements)\n");
}

void	ft_check_for_characters(t_game *game)
{
	int	x;
	int	y;

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
					&& game->map_matrix[y][x] != 'E'
				&& game->map_matrix[y][x] != 'P'
				&& game->map_matrix[y][x] != '1'
				&& game->map_matrix[y][x] != '0')))
			{
				ft_error("Error\n Invalid map (Invalid characters)\n");
			}
		}
	}
}

void	ft_check_for_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map_matrix[++y])
	{
		x = -1;
		while (game->map_matrix[y][++x])
		{
			if (game->map_matrix[0][x] != '1'
				|| game->map_matrix[game->map_y - 1][x] != '1')
				ft_error("Error\n Invalid map (Not surrounded by walls)\n");
			else if (game->map_matrix[y][0] != '1'
				|| game->map_matrix[y][game->map_x - 1] != '1')
				ft_error("Error\n Invalid map (Not surrounded by walls)\n");
		}
	}
}

void	ft_check_for_rectangle(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map_x = ft_strlen(game->map_matrix[j]);
	if (game->map_x >= 21)
		ft_error("Error\n Invalid map (X AXE too long)\n");
	j = -1;
	while (game->map_matrix[++j])
	{
		if (game->map_x != (int)ft_strlen(game->map_matrix[j]))
			ft_error("Error\n Invalid map (Not rectangular)\n");
	}
	game->map_y = j;
	if (game->map_y > 11)
		ft_error("Error\n Invalid map (Y AXE too long)\n");
}

void	ft_check_valid_map(t_game *game)
{
	ft_check_for_elements(game);
	ft_check_for_characters(game);
	ft_check_for_rectangle(game);
	ft_check_for_walls(game);
	ft_check_for_path_recursive(game);
}
