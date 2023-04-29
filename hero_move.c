/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:48:28 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/02 20:51:51 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keys.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == 53)
		close_game(mlx);
	else if (key == KEY_W)
		move_up(mlx);
	else if (key == KEY_A)
		move_left(mlx);
	else if (key == KEY_S)
		move_down(mlx);
	else if (key == KEY_D)
		move_right(mlx);
	return (0);
}

int	move_up(t_mlx *mlx)
{
	int	i;
	int	j;

	i = get_hero_row(mlx->map);
	j = get_hero_column(mlx->map);
	if (mlx->map[i - 1][j] != '1')
	{
		if (mlx->map[i - 1][j] == 'E')
		{
			if (!(map_collectable_count(mlx->map)))
			{
				mlx->map[i][j] = '0';
				mlx->map[i - 1][j] = 'P';
				ft_printf("%d\n", ++mlx->steps);
				close_game(mlx);
			}
			else
				return (0);
		}
		else
			mlx->map[i - 1][j] = 'P';
		mlx->map[i][j] = '0';
		ft_printf("%d\n", ++mlx->steps);
	}
	return (0);
}

int	move_left(t_mlx *mlx)
{
	int	i;
	int	j;

	i = get_hero_row(mlx->map);
	j = get_hero_column(mlx->map);
	if (mlx->map[i][j - 1] != '1')
	{
		if (mlx->map[i][j - 1] == 'E')
		{
			if (!(map_collectable_count(mlx->map)))
			{
				mlx->map[i][j - 1] = 'P';
				ft_printf("%d\n", ++mlx->steps);
				close_game(mlx);
			}
			else
				return (0);
		}
		else
			mlx->map[i][j - 1] = 'P';
		mlx->map[i][j] = '0';
		ft_printf("%d\n", ++mlx->steps);
	}
	return (0);
}

int	move_down(t_mlx *mlx)
{
	int	i;
	int	j;

	i = get_hero_row(mlx->map);
	j = get_hero_column(mlx->map);
	if (mlx->map[i + 1][j] != '1')
	{
		if (mlx->map[i + 1][j] == 'E')
		{
			if (!(map_collectable_count(mlx->map)))
			{
				mlx->map[i + 1][j] = 'P';
				ft_printf("%d\n", ++mlx->steps);
				close_game(mlx);
			}
			else
				return (0);
		}
		else
			mlx->map[i + 1][j] = 'P';
		mlx->map[i][j] = '0';
		ft_printf("%d\n", ++mlx->steps);
	}
	return (0);
}

int	move_right(t_mlx *mlx)
{
	int	i;
	int	j;

	i = get_hero_row(mlx->map);
	j = get_hero_column(mlx->map);
	if (mlx->map[i][j + 1] != '1')
	{
		if (mlx->map[i][j + 1] == 'E')
		{
			if (!(map_collectable_count(mlx->map)))
			{
				mlx->map[i][j + 1] = 'P';
				ft_printf("%d\n", ++mlx->steps);
				close_game(mlx);
			}
			else
				return (0);
		}
		else
			mlx->map[i][j + 1] = 'P';
		mlx->map[i][j] = '0';
		ft_printf("%d\n", ++mlx->steps);
	}
	return (0);
}
