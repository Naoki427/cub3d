/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:15:30 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/18 20:26:31 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

char	*re_create_2(char *str, char tmp)
{
	char	*ans;
	size_t	i;

	i = ft_strlen(str);
	ans = (char *)malloc(i + 2);
	if (ans == NULL)
		printf_exit("malloc error");
	i = 0;
	while (str[i])
	{
		ans[i] = str[i];
		i++;
	}
	ans[i++] = tmp;
	ans[i] = '\0';
	free(str);
	return (ans);
}

char	*gnl_cub3d_2(int fd)
{
	char	*ans;
	char	tmp;
	char	i;

	ans = (char *)malloc(sizeof(char) * 1);
	if (ans == NULL)
		printf_exit("malloc error");
	ans[0] = '\0';
	while (1)
	{
		i = read(fd, &tmp, 1);
		if (i < 0)
			printf_exit("read error");
		else if (i == 0)
			break;
		ans = re_create_2(ans, tmp);
		if (tmp == '\n')
			break ;
	}
	if (ft_strlen(ans) == 0)
		return NULL;
	return (ans);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
}

char	**re_create_str(char **str, char *s)
{
	int		i;
	char	**ans;

	i = 0;
	while (str[i])
		i++;
	ans = (char **)malloc(sizeof(char *) * (i + 2));
	if (ans == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	i = 0;
	while (str[i])
	{
		ans[i] = ft_strcpy(str[i]);
		i++;
	}
	ans[i++] = ft_strcpy(s);
	ans[i] = NULL;
	ft_free(str);
	return (ans);
}

char	**insert_map(char *str, int fd)
{
	char	**ans;
	char	*tmp;
	int		i;

	ans = (char **)malloc(sizeof(char *) * 2);
	if (ans == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	ans[0] = ft_strcpy(str);
	ans[1] = NULL;
	while (1)
	{
		tmp = gnl_cub3d_2(fd);
		if (tmp == NULL)
			break ;
		ans = re_create_str(ans, tmp);
		free(tmp);
	}
	return (ans);
}
