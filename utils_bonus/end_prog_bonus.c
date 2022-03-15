/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:01:16 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/15 17:44:12 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_exit_win(void)
{
	write(1, "You won!\n", 9);
	exit(0);
}

void	ft_exit_lost(void)
{
	write(1, "You lost!\n", 10);
	exit(0);
}

void	ft_exit(int flag)
{
	if (flag)
		write(2, "Error\n", 6);
	exit(1);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i++])
		free(map->map[i]);
	free(map->map);
}

int	end_prog(t_vars *vars)
{
	(void) vars;
	exit (0);
	return (1);
}
