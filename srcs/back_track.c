/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:23:44 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/25 11:23:40 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

int	check_0(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (0);
	if (x > 0 && y > 0 && map[y - 1][x - 1] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (y > 0 && map[y - 1][x] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (y > 0 && map[y - 1][x + 1] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (x > 0 && map[y][x - 1] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (map[y][x] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (map[y][x + 1] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (map[y + 1] && x > 0 && map[y + 1][x - 1] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (map[y + 1] && map[y + 1][x] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	if (map[y + 1] && map[y + 1][x + 1] == '0')
		printf_exit("Map error: 0 must be surrounded by 1");
	return (1);
}

void	backtrack_core(char **map, int x, int y)
{
	if (map[y][x] && check_0(map, x, y))
	{
		map[y][x] = '2';
		if  (map[y][x + 1] != '\0' && map[y][x + 1] != '2')
			backtrack_core(map, x + 1, y);
		if (map[y + 1] && map[y + 1][x] != '2')
			backtrack_core(map, x, y + 1);
		if (x > 0 && map[y][x - 1] != '2')
			backtrack_core(map, x - 1, y);
		if (y > 0 && map[y - 1][x] != '2')
			backtrack_core(map, x, y - 1);
	}
	else
		return ;
}

void	back_track(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	backtrack_core(map, x, y);
}
