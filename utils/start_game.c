/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:29:13 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/27 00:00:56 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_vars *vars, int i, int j, char *img_name)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx,
			img_name, &vars->pxl_x, &vars->pxl_y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img, (j * 32), (i * 32));
}

void	draw_map(t_map *map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
				put_img(vars, i, j, FLOOR);
			if (map->map[i][j] == '1')
				put_img(vars, i, j, WALL);
			if (map->map[i][j] == 'E')
				put_img(vars, i, j, EXIT);
			if (map->map[i][j] == 'C')
				put_img(vars, i, j, COIN);
			if (map->map[i][j] == 'P')
				put_img(vars, i, j, PLAYER);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53) // ESC
		exit(0);
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

int	ft_exti(t_vars *vars)
{
	(void) vars;
	exit(0);
	return (1);
}

void	start_game(t_map *map, t_vars *vars)
{
	vars->map = *map;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx,
			(map->rows + 1) * 32, map->columns * 32, "LOL!");
	draw_map(map, vars);
	mlx_key_hook(vars->mlx_win, key_hook, &vars);
	mlx_hook(vars->mlx_win, 17, 0, ft_exti, &vars);
	mlx_loop(vars->mlx);
}
