/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:20 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/26 23:36:54 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(int flag)
{
	if (flag)
		write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;

	if (argc != 2 || !check_valid_map(&vars, &map, argv[1]))
		ft_exit(1);
	start_game(&map, &vars);
	return (0);
}
