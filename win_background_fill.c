/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_background_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:24:17 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/01 21:57:55 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_window(t_mlx *mlx, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (IMG_WIDTH * mlx->m_map.map_line_len))
	{
		j = -1;
		while (++j < (IMG_HEIGHT * mlx->m_map.map_lines))
		{
			my_mlx_pixel_put(img, i, j, 0);
		}
	}
}

void	my_background_fill(t_data img, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= width)
	{
		my_mlx_pixel_put(&img, i, j, 0xfbbf42);
		i++;
		if (i == width)
		{
			i = 0;
			j++;
		}
		if (j == height)
			break ;
	}
}
