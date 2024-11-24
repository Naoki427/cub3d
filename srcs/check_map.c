/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:35 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/24 23:05:57 by kawaharadar      ###   ########.fr       */
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

char	**map_copy(int max_x, int max_y, char **map)
{
	char	**ans;
	int		i;

	ans = (char *)malloc(sizeof(char *) * (max_y + 3));
	if (ans == NULL)
		printf_exit("malloc error");
	i = 0;
	while (i < max_y + 2)
	{
		if (i == 0 || i == (max_y + 1))
			ans[i] = set_space(max_x);
		else if (i == (max_y + 2))
			ans[i] = NULL;
		else
			ans[i] = copy_map_str(max_x, map[i - 1]);
		i++;
	}
	return (ans);
}

char	**re_map(char **map)
{
	int		max_x;
	int		max_y;
	char	**ans;

	max_x = 0;
	max_y = 0;
	while (map[max_y])
	{
		if (ft_strlen(map[max_y] > max_x))
			max_x = ft_strlen(map[max_y]);
		max_y++;
	}
	ans = map_copy(max_x, max_y, map);
	return (ans);
}

void	check_map(t_info info)
{
	int	max_y;
	int max_x;

	check_char(info.map);
	info.map = re_map(info.map);
}
