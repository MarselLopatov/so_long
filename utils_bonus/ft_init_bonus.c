/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:47:11 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/15 18:11:24 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_init_map(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->collectible = 0;
	map->exit = 0;
	map->map = NULL;
	map->player = 0;
	map->x = 0;
	map->y = 0;
}

void	ft_init_vars(t_vars *vars)
{
	vars->steps = 0;
	vars->pxl_x = 32;
	vars->pxl_y = 32;
	vars->fd = 0;
	vars->count_steps = 0;
	vars->line_map = NULL;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->img_coin = NULL;
	vars->img_exit = NULL;
	vars->img_floor = NULL;
	vars->img_player[0] = NULL;
	vars->img_player[1] = NULL;
	vars->img_player[2] = NULL;
	vars->img_patrol[0] = NULL;
	vars->img_patrol[1] = NULL;
	vars->img_wall = NULL;
}
