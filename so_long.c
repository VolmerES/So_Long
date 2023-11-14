/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/14 19:31:07 by jdelorme         ###   ########.fr       */
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
	char	**map_copy;
	int		map_x;
	int		map_y;
	int		collectables;
	int		walls;
	int		spaces;
	int		exit;
}				t_game;

/*

					! ZONA GUARRA !

*/
char	*long_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		if (str[i] == '\n')
			i++;
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		if (str[i + j] == '\n')
			j++;
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}
/*

					! FIN DE ZONA GUARRA !

*/
void	ft_error(char *error)
{
	ft_putstr_fd (error, 1);
	exit (1);
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
	while (mapline[i++])
	{
		if (mapline[i] == 'C')
			j++;
		if (mapline[i] == 'E')
			k++;
		if (mapline[i] == 'P')
			e++;
	}
	if (j != 1 || k != 1 || e != 1)
		ft_error("Error: Invalid Map (Not enough elements)");
}

// ! Arreglar la condicion del salto de linea
void	ft_check_for_characters(char *mapline)
{
	int	i;

	i = 0;
	while (mapline[i] != '\0')
	{
		if (mapline[i] != 'C' && mapline[i] != 'E' && mapline[i] != 'P' && mapline[i] != '1' && mapline[i] != '0' && mapline[i] != '\n')
		{
			ft_error("Error: Invalid map (Invalid symbols)");
		}
		i++;
	}
}
// void	ft_check_for_walls(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int len_x
	
// 	len_x =	strange_strlen()
// 	i = -1;
// 	j = -1;
	
// 	while (game->map_y[++i])
// 	{
// 		if (game->map_y[i] != 1)
// 			ft_error("Error: Invalid map (Invalid walls)")
// 		if ()
// 	}
	
// }
void	ft_check_for_rectangle(t_game *game)
{
	int area;
	int len;

	len = ft_strlen(game->map_line);
	area = game->map_x * game->map_y;
	printf("area %i, mapx = %i, mapy = %i, len = %i \n", area, game->map_x, game->map_y, len);
	if ((len - 3) != area )
	{
		ft_error("Error: Invalid map (Not squared)");
	}
}

void	ft_check_valid_map(t_game *game)
{
	// * Funcion para comprobar que existan una unica saluda y puntos de partida, y al menos un coleccionable
	ft_check_for_elements(game->map_line);
	// * Funcion para comprobar que no existan caracteres distitntos a los validos en el mapa
	ft_check_for_characters(game->map_line);
	// ! Comprobar que el mapa este enteramente rodeado por muros 
	//	ft_check_for_walls(&game)
	// ! Comprobar que exista el menos un camino valido en hasta la salida, y que es camino hacia el coleccionable sea viable
	// ! Comprobar si e mapa es rectangular (probllema en determinados casos)
	ft_check_for_rectangle(game);
}

void	ft_read_map(t_game *game)
{
	int		fd;
	char	*line;
	// ! Llamar a funcion para verificar si es .ber
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
	game->map_x = (ft_strlen(line) - 1);
	free(line);
	game->map_line = NULL;
	while (line)
	{
		// ! Problema en el strjoin
		game->map_line = long_strjoin(game->map_line, line);
		line = get_next_line(fd);
		game->map_y++;
		printf("%s\n", line);
		// if (game->map_x != ft_strlen(line) - 1)
		// 	ft_error("TOPOTAMADRE");
	}
	close(fd);
	ft_check_valid_map(game);
}
/*Funcion presionar teclas*/
int	ft_deal_key(int key, t_vars *vars)
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
	{
		printf("Ha presionado ESC \n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit (1);
	}
	return 0;
}

int	main(void)
{
	t_game	game;
	t_vars	vars;
	
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1080, 1080, "so_long");
	mlx_key_hook(vars.mlx_win, ft_deal_key, &vars);
	ft_read_map(&game);
	// ! mlx_loop_hook(vars.mlx, &ft_steps, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
