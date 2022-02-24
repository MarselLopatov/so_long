/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:52 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/24 18:26:41 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
#include <stdio.h>//ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА
// УДАЛИ НА ХУЙ ЭТУ ХУЕТУ ЕБАНАТ ЕБАНЫЙ СУКА

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_vars{
	void	*mlx;
	void	*mlx_win;
	int		fd;
	char	*line_map;
}			t_vars;

typedef struct s_map{
	char	**map;
	int		wall;
	int		collectible;
	int		exit;
	int		player;
	int		x;
	int		y;
	int		rows;
	int		columns;
}			t_map;

char	**ft_split(char const *s, char c);
int	read_map(t_vars *vars, t_map *map, const char *file_name);
int		check_valid_map(t_vars *vars, t_map *map, const char *file_name);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);
void	ft_exit(int flag);


//init
void	ft_init_vars(t_vars *vars);
void	ft_init_map(t_map *map);

#endif