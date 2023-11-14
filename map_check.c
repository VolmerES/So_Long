/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:26:20 by jdelorme          #+#    #+#             */
/*   Updated: 2023/11/14 17:27:39 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		ft_matrix_len(t_game *game)
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

void	ft_check_valid_map(t_game *game)
{
	// * Funcion para comprobar que existan una unica saluda y puntos de partida, y al menos un coleccionable
	ft_check_for_elements(game->map_line);
	// * Funcion para comprobar que no existan caracteres distitntos a los validos en el mapa
	ft_check_for_characters(game->map_line);
	// ! Comprobar que el mapa este enteramente rodeado por muros 
	// ! Comprobar que exista el menos un camino valido en hasta la salida, y que es camino hacia el coleccionable sea viable
//	ft_check_for_walls(&game)
	// ! Comprobar si e mapa es rectangular
}

void	ft_read_map(t_game *game)
{
	int		fd;
	char	*line;
	// ! llamar a funcion para verificar si es .ber
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
	free(line);
	game->map_line = NULL;
	while (line)
	{
		game->map_line = gnl_strjoin(game->map_line, line);
		line = get_next_line(fd);
		game->map_y++;
	}
	close(fd);
	f