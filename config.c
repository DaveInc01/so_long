/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:45:15 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/02 20:45:16 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_mlx *mlx)
{
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, "./images/tree.xpm", \
					&mlx->wall.width, &mlx->wall.height);
	mlx->hero.img = mlx_xpm_file_to_image(mlx->mlx, "./images/dino.xpm", \
					&mlx->hero.width, &mlx->hero.height);
	mlx->gem.img = mlx_xpm_file_to_image(mlx->mlx, "./images/gem.xpm", \
					&mlx->gem.width, &mlx->gem.height);
	mlx->portal.img = mlx_xpm_file_to_image(mlx->mlx, "./images/portal.xpm", \
					&mlx->portal.width, &mlx->portal.height);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, \
				(IMG_WIDTH * mlx->m_map.map_line_len), \
					(IMG_HEIGHT * mlx->m_map.map_lines), "./so_long");
	mlx->img.img = mlx_new_image(mlx->mlx, \
					(IMG_WIDTH * mlx->m_map.map_line_len), \
					(IMG_HEIGHT * mlx->m_map.map_lines));
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
					&mlx->img.bits_per_pixel, \
					&mlx->img.line_length, &mlx->img.endian);
	get_textures(mlx);
}
