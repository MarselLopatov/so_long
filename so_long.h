/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:52 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/26 23:57:44 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
#include <stdio.h>//ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА

# define WALL "images/wall.xpm"
# define PLAYER "images/player.xpm"
# define EXIT "images/exit.xpm"
# define COIN "images/collectible.xpm"
# define FLOOR "images/floor.xpm"

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
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	int		fd;
	int		pxl_x;
	int		pxl_y;
	char	*line_map;
	char	*img;
}			t_vars;

//utils
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);
void	ft_exit(int flag);
void	start_game(t_map *map, t_vars *vars);
int		destroy(t_map *map, t_vars *vars);

//valid
void	cout_characters(t_map *map);
int		check_valid_map(t_vars *vars, t_map *map, const char *file_name);
int		read_map(t_vars *vars, t_map *map, const char *file_name);

//init
void	ft_init_vars(t_vars *vars);
void	ft_init_map(t_map *map);

#endif