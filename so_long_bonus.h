/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:46:51 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/15 17:37:42 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
# include <stdio.h>//ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА

# define WALL "images/wall_bonus.xpm"
# define PLAYER1 "images/player_bonus_1.xpm"
# define PLAYER2 "images/player_bonus_2.xpm"
# define PLAYER3 "images/player_bonus_3.xpm"
# define EXIT "images/exit_bonus.xpm"
# define COIN "images/collectible_bonus.xpm"
# define FLOOR "images/floor_bonus.xpm"
# define PATROL1 "images/patrol1.xpm"
# define PATROL2 "images/patrol2.xpm"

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_map{
	char	**map;
	int		collectible;
	int		exit;
	int		player;
	int		x;
	int		y;
	int		rows;
	int		columns;
}			t_map;

typedef struct s_vars{
	t_map	*map;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	int		fd;
	int		pxl_x;
	int		pxl_y;
	long	count_steps;
	char	*line_map;
	void	*img_wall;
	void	*img_player[3];
	void	*img_coin;
	void	*img_floor;
	void	*img_exit;
	void	*img_patrol[2];
}			t_vars;

//utils
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);
void	ft_exit(int flag);
void	start_game(t_map *map, t_vars *vars);
int		end_prog(t_vars *vars);
void	draw_map(t_map *map, t_vars *vars);
char	*ft_itoa(int n);
void	animation(t_vars *vars);
void	ft_exit_lost(void);
void	ft_exit_win(void);

//valid
void	cout_characters(t_map *map, int i);
int		check_valid_map(t_vars *vars, t_map *map, const char *file_name);
int		read_map(t_vars *vars, t_map *map, const char *file_name);

//init
void	ft_init_vars(t_vars *vars);
void	ft_init_map(t_map *map);

//move
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

#endif