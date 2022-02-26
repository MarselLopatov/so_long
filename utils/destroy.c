/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:01:16 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/27 00:00:33 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all(t_map *map)//, t_vars *vars)
{
	int	i;

	i = 0;
	while (map->map[i++])
		free(map->map[i]);
	free(map->map);
	// free(vars->img);
	// free(vars->mlx);
	// free(vars->mlx_win);
}

int	destroy(t_map *map, t_vars *vars)
{
	(void) vars;
	(void) map;
	mlx_destroy_image(vars->mlx, FLOOR);
	mlx_destroy_image(vars->mlx, WALL);
	mlx_destroy_image(vars->mlx, COIN);
	mlx_destroy_image(vars->mlx, EXIT);
	mlx_destroy_image(vars->mlx, PLAYER);
	free_all(map);//, vars);
	// exit (0);
	return (1);
}
