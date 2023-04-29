/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:06:58 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/08/31 23:11:57 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arr_line_len(char **arr)
{
	int	j;

	j = 0;
	if (arr[0][j])
	{
		while (arr[0][j])
			j++;
	}
	return (j);
}

int	map_collectable_count(char **map)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collect += 1;
			j++;
		}
		i++;
	}
	return (collect);
}

int	get_hero_row(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				ret = i;
			j++;
		}
		i++;
	}
	return (ret);
}

int	get_hero_column(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				ret = j;
			j++;
		}
		i++;
	}
	return (ret);
}
