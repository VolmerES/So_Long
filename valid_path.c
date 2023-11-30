/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:46:07 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/28 14:44:56 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_for_collectables(t_game *game)
{
	int	y;
	int	x;

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
	if (valid == 0)
		ft_error("ERROR: No avaliable path");
	ft_check_for_collectables(game);
	while (game->map_matrix_copy[y])
		free (game->map_matrix_copy[y++]);
	free (game->map_matrix_copy);
}
