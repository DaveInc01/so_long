/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:12:04 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/01 21:57:51 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

inline void	put_wall(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mlx->wall.img, IMG_WIDTH * x, IMG_HEIGHT * y);
}

inline void	put_hero(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx,
		mlx->mlx_win, mlx->hero.img, IMG_WIDTH * x, IMG_HEIGHT * y);
}

inline void	put_coll(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx,
		mlx->mlx_win, mlx->gem.img, IMG_WIDTH * x, IMG_HEIGHT * y);
}

inline void	put_portal(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx,
		mlx->mlx_win, mlx->portal.img, IMG_WIDTH * x, IMG_HEIGHT * y);
}
