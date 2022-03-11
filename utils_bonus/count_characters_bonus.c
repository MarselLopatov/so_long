/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_characters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:29:14 by cdoria            #+#    #+#             */
/*   Updated: 2022/03/11 19:59:44 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	cout_characters(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == 'P' )
		{
			map->player++;
			if (map->player > 1)
			{
				map->map[i][j] = '0';
				continue ;
			}
			map->x = j;
			map->y = i;
		}
		else if (map->map[i][j] == 'E')
			map->exit++;
		else if (map->map[i][j] == 'C')
			map->collectible++;
		j++;
	}	
}
