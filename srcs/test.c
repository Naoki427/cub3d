/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:32:25 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/27 01:45:26 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

char	*re_create_test(char *str, char tmp)
{
	char	*ans;
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	ans = (char *)malloc(i + 2);
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

char	*test_gnl(int fd)
{
	char	tmp;
	char	*ans;
	int		i;

	ans = (char *)malloc(1);
	ans[0] = '\0';
	while (1)
	{
		i = read(fd, &tmp, 1);
		if (i == 0)
			break ;
		ans = re_create_test(ans, tmp);
		if (tmp == '\n')
			break ;
	}
	if (ft_strlen(ans) == 0 && i == 0)
		return (NULL);
	return (ans);
}

char	**add_str(char **str, char *s)
{
	int		i;
	char	**ans;

	i = 0;
	while (str[i])
		i++;
	ans = (char **)malloc(sizeof(char *) * (i + 2));
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

char	**test(char *file)
{
	int		fd;
	char	**ans;
	char	*tmp;

	ans = (char **)malloc(sizeof(char *) * 1);
	ans[0] = NULL;
	fd = open(file, O_RDONLY);
	while (1)
	{
		tmp = test_gnl(fd);
		if (tmp == NULL)
			break ;
		ans = add_str(ans, tmp);
		free(tmp);
	}
	return (ans);
}

void	check_struct(t_info info)
{
	int	i;

	printf("north = %s\n", info.north);
	printf("south = %s\n", info.south);
	printf("east = %s\n", info.east);
	printf("west = %s\n", info.west);
	printf("flooring = [%d, %d, %d]\n", info.flooring[0], info.flooring[1], info.flooring[2]);
	printf("ceiling = [%d, %d, %d]\n", info.ceiling[0], info.ceiling[1], info.ceiling[2]);
	i = 0;
	while (info.map[i])
	{
		printf("[%s]\n", info.map[i++]);
	}
}
