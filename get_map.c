/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:44:51 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/11/13 22:13:00 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_create(int lines_c, char **map, int fd)
{
	int		i;
	char	*line;
	int		line_len;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			line_len = ft_strlen(line);
		if (line_valid(line, line_len, i, lines_c))
			line_fill(map, line, line_len, i);
		else
		{
			free(line);
			return (0);
		}
		i++;
		free(line);
	}
	map[i] = 0;
	return (1);
}

char	**get_map(int fd, char *f_name)
{
	int		lines_c;
	char	**map;

	lines_c = lines_count(fd);
	close(fd);
	fd = open(f_name, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (lines_c + 1));
	if (!map)
		return (NULL);
	if (map_create(lines_c, map, fd))
		return (map);
	else
		return (NULL);
}

int	map_checker(char **map)
{
	int	i;
	int	j;
	int	p_e;
	int	c;

	i = -1;
	p_e = 0;
	c = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				p_e += 1;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
	}
	if (p_e == 2 && c)
		return (i);
	else
		return (0);
}
