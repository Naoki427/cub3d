/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:38:26 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/19 13:32:23 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

size_t	ft_strlen(char *str)
{
	int	ans;

	ans = 0;
	while (str[ans])
		ans++;
	return (ans);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f')
		return (1);
	if (c == '\r' || c == ' ')
		return (1);
	return (0);
}

char	*ft_strcpy(char *str)
{
	char	*ans;
	size_t	i;

	ans = (char *)malloc(ft_strlen(str) + 1);
	if (ans == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	i = 0;
	while (str[i])
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

void	printf_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}
