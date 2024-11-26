/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:29:10 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/26 18:08:56 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

char	*re_create(char *str, char tmp)
{
	char	*ans;
	size_t	len;
	size_t	i;

	len = ft_strlen(str) + 2;
	ans = (char *)malloc(len);
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
	ans[i++] = tmp;
	ans[i] = '\0';
	free(str);
	return (ans);
}

char	*cub3d_gnl(int fd)
{
	char	*str;
	char	tmp;
	int		i;

	str = (char *)malloc(1);
	if (str == NULL)
		printf_exit("malloc error");
	str[0] = '\0';
	while (1)
	{
		i = read(fd, &tmp, 1);
		if (i == 0)
			break;
		else if (i < 0)
			printf_exit("read error");
		str = re_create(str, tmp);
		if (tmp == '\n')
			break;
	}
	return (str);
}

char	*select_path(char *str)
{
	size_t	l;
	size_t	i;
	size_t	j;
	char	*ans;

	l = 0;
	while (ft_isspace(str[l]))
		l++;
	i = l;
	while (!ft_isspace(str[i]) && str[i] != '\n')
		i++;
	ans = (char *)malloc(sizeof(char) * (i - l + 1));
	if (ans == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	j = 0;
	while (l != i)
		ans[j++] = str[l++];
	ans[j] = '\0';
	if (ft_strlen(ans) == 0)
		printf_exit("Infomation lack: write the xpm file path.");
	return (ans);
}

int	insert_info(t_info *info, char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == 'N' && info->north == NULL && str[i + 1] == 'O')
		info->north = select_path(&str[i + 2]);
	else if (str[i] && str[i] == 'S' && info->south == NULL && str[i + 1] == 'A')
		info->south = select_path(&str[i + 2]);
	else if (str[i] && str[i] == 'W' && info->west == NULL && str[i + 1] == 'E')
		info->west = select_path(&str[i + 2]);
	else if (str[i] && str[i] == 'E' && info->east == NULL && str[i + 1] == 'A')
		info->east = select_path(&str[i + 2]);
	else if (str[i] && (str[i] == '1' || str[i] == '0'))
		return (1);
	else if (str[i] && str[i] == 'C')
		ft_insertion(&str[i + 1], info->ceiling);
	else if (str[i] && str[i] == 'F')
		ft_insertion(&str[i + 1], info->flooring);
	else if (str[i] && str[i] == '\n')
		return (0);
	else
		printf_exit("Format error: file format error. Read subjectPDF.");
	return (0);
}

t_info	analysis_file(int fd)
{
	char	*str;
	t_info	info;

	info = init_info();
	while (1)
	{
		str = cub3d_gnl(fd);
		if (ft_strlen(str) == 0)
			break;
		if (insert_info(&info, str))
			break;
		free(str);
	}
	if (ft_strlen(str))
		info.map = insert_map(str, fd);
	free(str);
	if (check_info(info))
	{
		printf("Infomation error: Missing infomation in .cub file\n");
		exit(1);
	}
	info.map = check_map(info);
	return(info);
}
