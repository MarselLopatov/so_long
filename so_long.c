/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:20 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/24 17:40:46 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(int flag)//, t_vars *vars)
{
	if (flag)
		write(2, "Error\n", 6);
	exit(1);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
		ft_exit(0);
	if (keycode == 17)
		ft_exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_map map;
	t_vars vars;

	if (argc != 2 || !check_valid_map(&vars, &map, argv[1]))
		ft_exit(1);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1600, 1000, "HUI!");
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	// mlx_hook(vars.mlx_win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
