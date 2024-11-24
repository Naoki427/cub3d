/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:35 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/20 18:31:29 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

int	start_check(char s)
{
	if (ft_isspace(s))
		return (0);
	if (s == '1' || s == '0')
		return (0);
	if (s == 'N' || s == 'S')
		return (1);
	if (s == 'W' || s == 'E' || s == '\n')
		return (1);
	printf_exit("Map error: there is a invalid character.");
}

void	check_char(char **map)
{
	int	x;
	int	y;
	int	flg;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			flg += start_check(map[x]);
		y++;
	}
	if (flg != 1)
		printf_exit("Map error: start point must be a point as S,N,W,E.");
}

void	check_map(t_info info)
{
	int	max_y;
	int max_x;

	check_char(info.map);
	info.map = re_map(info.map);
}
