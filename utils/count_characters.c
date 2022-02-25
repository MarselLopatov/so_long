/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:29:14 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/25 18:38:19 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cout_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player++;
				map->x = i;
				map->y = j;
			}
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == 'C')
				map->collectible++;
			j++;
		}
		i++;
	}
}
