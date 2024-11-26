/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:42:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/11/27 01:24:10 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

int	check_file_extension(char *file, char *ext)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (1);
	len -= 4;
	while (file[len] && *ext && file[len] == *ext)
	{
		ext++;
		len++;
	}
	return (file[len] - *ext);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("Arguments error: write a filename.\n");
		exit(1);
	}
	if (check_file_extension(av[1], ".cub"))
	{
		printf("File error: %s: File extension must be .cub\n", av[1]);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("File error: %s: cannot open the file\n", av[1]);
		exit(1);
	}
	analysis_file(fd);
}
