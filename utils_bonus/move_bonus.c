/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:40:59 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/15 18:20:25 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	count_steps(t_vars *vars)
{
	char	*steps;

	vars->count_steps++;
	if (vars->count_steps > INT32_MAX)
		vars->count_steps = 0;
	steps = ft_itoa(vars->count_steps);
	mlx_string_put(vars->mlx, vars->mlx_win, 5, 5, 0xFFA500, steps);
	free(steps);
}

void	move_up(t_vars *vars)
{
	if (vars->map->map[vars->map->y - 1][vars->map->x] == '1')
		return ;
	if (vars->map->map[vars->map->y - 1][vars->map->x] == 'E'
		&& vars->map->collectible == 0)
		ft_exit_win();
	else if (vars->map->map[vars->map->y - 1][vars->map->x] == 'E'
		&& vars->map->collectible != 0)
		return ;
	if (vars->map->map[vars->map->y - 1][vars->map->x] == 'X')
		ft_exit_lost();
	if (vars->map->map[vars->map->y - 1][vars->map->x] == 'C')
	{
		vars->map->collectible--;
		vars->map->map[vars->map->y - 1][vars->map->x] = '0';
	}
	vars->map->map[vars->map->y][vars->map->x] = '0';
	vars->map->y--;
	vars->map->map[vars->map->y][vars->map->x] = 'P';
	draw_map(vars->map, vars);
	count_steps(vars);
}

void	move_down(t_vars *vars)
{
	if (vars->map->map[vars->map->y + 1][vars->map->x] == '1')
		return ;
	if (vars->map->map[vars->map->y + 1][vars->map->x] == 'E'
		&& vars->map->collectible == 0)
		ft_exit_win();
	else if (vars->map->map[vars->map->y + 1][vars->map->x] == 'E'
		&& vars->map->collectible != 0)
		return ;
	if (vars->map->map[vars->map->y + 1][vars->map->x] == 'X')
		ft_exit_lost();
	if (vars->map->map[vars->map->y + 1][vars->map->x] == 'C')
	{
		vars->map->collectible--;
		vars->map->map[vars->map->y + 1][vars->map->x] = '0';
	}
	vars->map->map[vars->map->y][vars->map->x] = '0';
	vars->map->y++;
	vars->map->map[vars->map->y][vars->map->x] = 'P';
	draw_map(vars->map, vars);
	count_steps(vars);
}

void	move_left(t_vars *vars)
{
	if (vars->map->map[vars->map->y][vars->map->x - 1] == '1')
		return ;
	if (vars->map->map[vars->map->y][vars->map->x - 1] == 'E'
		&& vars->map->collectible == 0)
		ft_exit_win();
	else if (vars->map->map[vars->map->y][vars->map->x - 1] == 'E'
		&& vars->map->collectible != 0)
		return ;
	if (vars->map->map[vars->map->y][vars->map->x - 1] == 'X')
		ft_exit_lost();
	if (vars->map->map[vars->map->y][vars->map->x - 1] == 'C')
	{
		vars->map->collectible--;
		vars->map->map[vars->map->y][vars->map->x - 1] = '0';
	}
	vars->map->map[vars->map->y][vars->map->x] = '0';
	vars->map->x--;
	vars->map->map[vars->map->y][vars->map->x] = 'P';
	draw_map(vars->map, vars);
	count_steps(vars);
}

void	move_right(t_vars *vars)
{
	if (vars->map->map[vars->map->y][vars->map->x + 1] == '1')
		return ;
	if (vars->map->map[vars->map->y][vars->map->x + 1] == 'E'
		&& vars->map->collectible == 0)
		ft_exit_win();
	else if (vars->map->map[vars->map->y][vars->map->x + 1] == 'E'
		&& vars->map->collectible != 0)
		return ;
	if (vars->map->map[vars->map->y][vars->map->x + 1] == 'X')
		ft_exit_lost();
	if (vars->map->map[vars->map->y][vars->map->x + 1] == 'C')
	{
		vars->map->collectible--;
		vars->map->map[vars->map->y][vars->map->x + 1] = '0';
	}
	vars->map->map[vars->map->y][vars->map->x] = '0';
	vars->map->x++;
	vars->map->map[vars->map->y][vars->map->x] = 'P';
	draw_map(vars->map, vars);
	count_steps(vars);
}
