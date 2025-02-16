/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:35 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/27 02:00:26 by rkawahar         ###   ########.fr       */
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
	if (s == 'W' || s == 'E')
		return (1);
	if (s == ' ' || s == '\n')
		return (0);
	printf_exit("Map error: there is a invalid character.");
	return (1);
}

void	check_char(char **map)
{
	int	x;
	int	y;
	int	flg;

	x = 0;
	y = 0;
	flg = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			flg += start_check(map[y][x++]);
		y++;
	}
	if (flg != 1)
		printf_exit("Map error: start point must be a point as S,N,W,E.");
}

char	**map_copy(int max_x, int max_y, char **map)
{
	char	**ans;
	int		i;

	ans = (char **)malloc(sizeof(char *) * (max_y + 3));
	if (ans == NULL)
		printf_exit("malloc error");
	i = 0;
	while (i < max_y + 2)
	{
		if (i == 0 || i == (max_y + 1))
			ans[i] = set_space(max_x);
		else
			ans[i] = copy_map_str(max_x, map[i - 1]);
		i++;
	}
	ans[i] = NULL;
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
		if ((int)ft_strlen(map[max_y]) > max_x)
			max_x = ft_strlen(map[max_y]);
		max_y++;
	}
	if (max_x > 1000 || max_y > 1000)
		printf_exit("Map error: Max map size is 1000x1000");
	ans = map_copy(max_x, max_y, map);
	back_track(ans);
	return (ans);
}

char	**check_map(t_info info)
{
	char	**ans;
	int		i;
	int		y;

	check_char(info.map);
	ans = re_map(info.map);
	i = 0;
	y = 0;
	while (ans[y])
	{
		i = 0;
		while (ans[y][i])
		{
			if (ans[y][i] == ' ')
				printf_exit("Map error: No space inside the wall.");
			if (ans[y][i] == '2')
				ans[y][i] = ' ';
			i++;
		}
		y++;
	}
	ft_free(info.map);
	return (ans);
}
