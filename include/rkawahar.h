/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkawahar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:43:14 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/18 20:52:01 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RKAWAHAR_H
# define RKAWAHAR_H

typedef struct s_info
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*flooring;
	int		*ceiling;
	char	**map;
}			t_info;

size_t	ft_strlen(char *str);
void	analysis_file(int fd);
t_info	init_info(void);
int		check_info(t_info info);
int		ft_isspace(char c);
char	*ft_strcpy(char *str);
void	printf_exit(char *str);
char	**insert_map(char *str, int fd);
int		*ft_insertion(char *str, int *nums);

#endif