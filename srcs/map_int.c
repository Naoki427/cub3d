/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:50:09 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/19 17:20:29 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

int	ft_atoi(char *str, int *i, char end)
{
	int	ans;

	ans = 0;
	while (str[*i] != end)
	{
		if (str[*i] < '0' || '9' < str[*i])
		{
			printf("str = [%s], str[i] = [%c]\n", str, str[*i]);
			printf_exit("Number error: number format error");
		}
		ans = ans * 10 + (str[*i] - '0');
		if (ans < 0 || 255 < ans)
			printf_exit("Number error: number must be 0 - 255");
		(*i)++;
	}
	return (ans);
}

void	ft_insertion(char *str, int *nums)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (ft_isspace(str[i]))
		i++;
	nums[index++] = ft_atoi(str, &i, ',');
	i++;
	nums[index++] = ft_atoi(str, &i, ',');
	i++;
	nums[index++] = ft_atoi(str, &i, '\n');
}
