/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/13 19:48:23 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*            || PARTE DE CODIGO DEL JUEGO ||								
 ! Comprobacion de que el mapa es de extension .ber 							
 * Funcion de lectura del mapa con GNL										
 ! Comprobacion que el mapa contenga P, E, C y las paredes sean 1 			
 ! Hacer que al presionar "X" tecla se mueva hacia esa posicion 				
 ! Funcion para contar los pasos reales que da el jugador 					
 ! Que el jugador no pueda entrar dentro de las paredes 						
 * Función de errores 														*/

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

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}				t_vars;

typedef struct s_game
{
	char	*game;
	char 	*map_line;
	int		map_long;
	int		map_large;
	int		collectables;
	int		walls;
	int		spaces;
	int		exit;
}				t_game;

typedef struct s_player
{
	int		x;
	int		y;
}				t_player;

void	ft_error(char *error)
{
	t_vars	vars;
	
	ft_putstr_fd (error, 1);
	mlx_destroy_window(vars.mlx, vars.mlx_win);
}

void	ft_check_for_elements(char *mapline)
{
	int i;
	int j;
	int k;
	int e;

	i = 0;
	j = 0;
	k = 0;
	e = 0;
	// ! PRUEBA
	printf ("%s", mapline);
	// ! FIN PRUEBA
	while (mapline[i++])
	{
		if (mapline[i] == 'C')
			j++;
		if (mapline[i] == 'E')
			k++;
		if (mapline[i] == 'P')
			e++;
	}
	if ((j || k || e) != 1)
		ft_error("Error: Invalid Map (Not enough elements)");
}
void	ft_check_valid_map(t_game *game)
{
	// ! Funcion para comprobar que existan una unica saluda y puntos de partida, y al menos un coleccionable
	ft_check_for_elements(game->map_line);
	// ! Funcion para comprobar que no existan caracteres distitntos a los validos en el mapa
	// ! Comprobar que el mapa este enteramente rodeado por muros 
	// ! Comprobar que exista el menos un camino valido en hasta la salida, y que es camino hacia el coleccionable sea viable
	// ! Comprobar si e mapa es rectangular
}

void	ft_read_map(t_game *game)
{
	int		fd;
	char	*line;
	// ! llamar a funcion para verificar si es .ber
	// ! PRUEBA
	printf ("Breakpoint READMAP");
	// ! FIN PRUEBA
	fd = open("./Maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error: Unable to open map");
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_error("Error: The map is empty");
	}
	while (line)
	{
		line = get_next_line(fd);
	}
	close(fd);
	// ! PRUEBA
	printf ("%s", line);
	// ! FIN PRUEBA
	ft_check_valid_map(game);
}
/*Funcion presionar teclas*/
int	ft_deal_key(int key, t_vars vars)
{
	int steps;

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
		mlx_destroy_window(vars.mlx, vars.mlx_win);
	return 0;
}

int	main(void)
{
	t_game	game;
	t_vars	vars;
	
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1080, 1080, "so_long");
	mlx_key_hook(vars.mlx_win, ft_deal_key, &vars);
	// ! mlx_loop_hook(vars.mlx, &ft_steps, &vars);
	mlx_loop(vars.mlx);
	ft_read_map(&game);
	return 0;
}
