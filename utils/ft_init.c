/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:47:11 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/24 18:27:02 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->collectible = 0;
	map->exit = 0;
	map->map = NULL;
	map->player = 0;
	map->wall = 0;
	map->x = 0;
	map->y = 0;
}

void	ft_init_vars(t_vars *vars)
{
	vars->fd = 0;
	vars->line_map = NULL;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
}
