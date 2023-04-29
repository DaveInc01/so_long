/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines-validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:19:03 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/02 20:29:11 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	only_one_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	line_valid(char *line, int line_len, int order, int lines_count)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (len == line_len)
	{
		if (order == 0 || order == (lines_count - 1))
		{
			if (only_one_in_line(line))
				return (1);
			return (0);
		}
		else
		{
			if (line[0] == '1' && line[ft_strlen(line) - 2] == '1')
			{
				return (1);
			}
			else
				return (0);
		}
	}
	return (0);
}

int	lines_count(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	return (i);
}

void	line_fill(char **map, char *line, int line_len, int i)
{
	int	j;

	j = 0;
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (j < line_len)
	{
		map[i][j] = line[j];
		j++;
	}
	map[i][j] = '\0';
}
