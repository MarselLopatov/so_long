/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:13:13 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/15 17:02:42 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	hold_time(void)
{
	static int	step = 0;
	static int	time = 0;

	time++;
	if (time == 25)
	{
		time = 0;
		step++;
		if (step > 2)
			step = 0;
	}
	return (step);
}

void	find_patrol_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map->map[i])
	{
		j = 0;
		while (vars->map->map[i][j])
		{
			if (vars->map->map[i][j] == 'X' && vars->steps != 2)
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img_patrol[vars->steps], j * 32, i * 32);
			if (vars->map->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img_player[vars->steps], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

int	player_patrol_animation(t_vars *vars)
{
	vars->steps = hold_time();
	find_patrol_player(vars);
	return (1);
}

void	animation(t_vars *vars)
{
	vars->img_player[0] = mlx_xpm_file_to_image
		(vars->mlx, PLAYER1, &vars->pxl_x, &vars->pxl_y);
	vars->img_player[1] = mlx_xpm_file_to_image
		(vars->mlx, PLAYER2, &vars->pxl_x, &vars->pxl_y);
	vars->img_player[2] = mlx_xpm_file_to_image
		(vars->mlx, PLAYER3, &vars->pxl_x, &vars->pxl_y);
	vars->img_patrol[0] = mlx_xpm_file_to_image
		(vars->mlx, PATROL1, &vars->pxl_x, &vars->pxl_y);
	vars->img_patrol[1] = mlx_xpm_file_to_image
		(vars->mlx, PATROL2, &vars->pxl_x, &vars->pxl_y);
	mlx_loop_hook(vars->mlx, &player_patrol_animation, vars);
}
