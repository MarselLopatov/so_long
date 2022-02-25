/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:08:03 by cdoria            #+#    #+#             */
/*   Updated: 2022/02/25 19:37:20 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_line(t_map *map, int i)
{
	int j;

	if (i == 0)
	{
		map->rows = ft_strlen(map->map[i]) - 1;
		map->columns++;
		return (1);
	}
	else if (map->rows != ft_strlen(map->map[i]) - 1)
		return (0);
	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '0' && map->map[i][j] != '1' && map->map[i][j] != 'C'
			&& map->map[i][j] != 'E' && map->map[i][j] != 'P')
			return (0);
		j++;
	}
	map->columns++;
	return (1);
}

int	check_valid_file(const char *file_name)
{
	int i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 4] != '.' || file_name[i - 3] != 'b'
		|| file_name[i - 2] != 'e' || file_name[i - 1] != 'r')
		return (0);
	return (1);
}

int	check_valid_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 && map->map[i][j] != '1')
				return (0);	
			else if ((j == 0 || j == map->rows) && map->map[i][j] != '1')
				return (0);
			else if (i == map->columns - 1 && map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_valid_map(t_vars *vars, t_map *map, const char *file_name)
{
	int	i;

	ft_init_map(map);
	ft_init_vars(vars);
	if (!check_valid_file(file_name) || !read_map(vars, map, file_name))
		return (0);
	i = -1;
	while (map->map[++i])
		if (!check_line(map, i))
			return (0);
	if (map->columns - 1 == map->rows || !check_valid_walls(map))
		return (0);
	cout_characters(map);
	if (!map->collectible || !map->exit || !map->player)
		return (0);
	return (1);
}
