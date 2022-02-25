/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:29:13 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/25 20:12:17 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map(t_map *map, t_vars *vars)
{
	int	i;
	
	i = 0;
	while (map->map[i])
	{
		put_img(map->map[i]);
		i++;
	}
}

void	make_window(t_map *map, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx,
		map->rows * 48, map->columns * 48, "LOL!");
	vars->img_player = mlx_xpm_file_to_image(vars->mlx,
			"/images/player.xpm", &vars->pxl_x, &vars->pxl_y);
	vars->img_collectible = mlx_xpm_file_to_image(vars->mlx,
		"/images/collectible.xpm", &vars->pxl_x, &vars->pxl_y);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx,
		"/images/exit.xpm", &vars->pxl_x, &vars->pxl_y);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
		"/images/wall.xpm", &vars->pxl_x, &vars->pxl_y);
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx,
		"/images/floor.xpm", &vars->pxl_x, &vars->pxl_y);
	draw_map(map, vars);
}
