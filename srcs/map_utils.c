/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:53:39 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/24 23:04:49 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

char	*set_space(int x)
{
	int		i;
	char	*ans;

	i = 0;
	ans = (char *)malloc(sizeof(char) * (x + 3));
	if (ans == NULL)
		printf_exit("malloc error");
	while (i < x + 2)
		ans[i++] = ' ';
	ans[i] = '\0';
	return (ans);
}

char	*copy_map_str(int x, char *str)
{
	int		i;
	char	*ans;

	ans = (char *)malloc(sizeof(char) * (x + 3));
	if (ans == NULL)
		printf_exit("malloc error");
	i = 0;
	ans[i++] = ' ';
	while (str[i - 1] != '\n' && str[i - 1] != '\0')
	{
		ans[i] = str[i - 1];
		i++;
	}
	while (i < x + 2)
		ans[i++] = ' ';
	ans[i] = '\0';
	return (ans);
}
