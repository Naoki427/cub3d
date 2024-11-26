/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:50:09 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/27 00:53:51 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

int	ft_atoi(char *str, int *i, char end)
{
	int	ans;

	ans = 0;
	if (str[*i] == end)
		return (-1);
	while (str[*i] != end)
	{
		if (str[*i] < '0' || '9' < str[*i])
		{
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
	if (nums[0] != -1 || nums[1] != -1 || nums[2] != -1)
		printf_exit("Format error: file format error. Read subjectPDF.");
	while (ft_isspace(str[i]))
		i++;
	nums[index++] = ft_atoi(str, &i, ',');
	i++;
	nums[index++] = ft_atoi(str, &i, ',');
	i++;
	nums[index++] = ft_atoi(str, &i, '\n');
}
