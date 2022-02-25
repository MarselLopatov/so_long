/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:20 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/25 19:50:55 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(int flag)
{
	if (flag)
		write(2, "Error\n", 6);
	exit(1);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53) // ESC
		ft_exit(0);
	if (keycode == 0) // A
		;
	if (keycode == 1) // S
		;
	if (keycode == 2) // D
		;
	if (keycode == 13) // D
		;
	return (0);
}

int main(int argc, char **argv)
{
	t_map map;
	t_vars vars;

	if (argc != 2 || !check_valid_map(&vars, &map, argv[1]))
		ft_exit(1);
	make_window(&map, &vars);
	// mlx_key_hook(vars.mlx_win, key_hook, &vars);
	// mlx_hook(vars.mlx_win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
