/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:47 by jdelorme          #+#    #+#             */
/*   Updated: 2024/02/02 14:37:29 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

#define KEY_ESC			53
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define ARROW_UP		126
#define ARROW_DOWN		125
#define ARROW_LEFT		123
#define ARROW_RIGHT		124
#define RED_TEXT 		"\033[31m"

typedef struct s_game	t_game;
typedef struct s_vars	t_vars;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
}				t_vars;

typedef struct s_game
{
	char	*player_img;
	char	*wall_img;
	char	*exit_img;
	char	*ground_img;
	char	*collectable_img;
	char	*game;
	char	*map_line;
	char	**map_matrix;
	char	**map_matrix_copy;
	int		map_x;
	int		map_y;
	int		p_y;
	int		p_x;
	int		img_width;
	int		img_height;
	int		coins;
	int		steps;
	int		step_flag;
}				t_game;

void	ft_error(char *error);
void	ft_check_ber(char *arg);
void	ft_put_img(t_vars *vars);
void	ft_move_up(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_right(t_vars *vars);
void	ft_steps_window(t_vars *vars);
void	ft_check_valid_map(t_game *game);
void	ft_check_for_walls(t_game *game);
void	ft_check_for_elements(t_game *game);
void	ft_check_for_rectangle(t_game *game);
void	ft_read_map(t_game *game, char *arg);
void	ft_check_for_characters(t_game *game);
void	ft_check_for_collectables(t_game *game);
void	ft_check_for_path_recursive(t_game *game);
void	ft_put_img_util(t_vars *vars, int y, int x);
void	ft_mlx_initialiter(t_vars *vars, t_game *game);
int		ft_close(t_vars *vars);
int		ft_set_img(t_vars *vars);
int		ft_count_steps(t_vars *vars);
int		ft_deal_key(int key, t_vars *vars);
int		ft_path_cross_checker(char **map_matrix_copy, int p_y, int p_x);
