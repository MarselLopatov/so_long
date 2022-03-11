/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:46:29 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/11 20:54:28 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;

	if (argc != 2 || !check_valid_map(&vars, &map, argv[1]))
		ft_exit(1);
	start_game(&map, &vars);
	return (0);
}
