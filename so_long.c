/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/09 18:24:45 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_deal_key(int key, void *param)
{
	int i;


	printf("El jugador ha realizado %i movimientos. \n", i);
		
	return 0;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "so_long");
	mlx_pixel_put(mlx, mlx_win, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx_win, ft_deal_key, (void *)0);
	mlx_loop(mlx);
	return 0;
}
