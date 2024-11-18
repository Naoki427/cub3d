#ifndef RKAWAHAR_H
# define RKAWAHAR_H

typedef struct s_info
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		flooring[3];
	int		ceiling[3];
	char	*map;
}			t_info;

size_t	ft_strlen(char *str);
void	analysis_file(int fd);
t_info	init_info(void);
int		check_info(t_info info);
int		ft_isspace(char c);

#endif