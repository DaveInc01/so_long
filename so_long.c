/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:38:35 by dmkhitar          #+#    #+#             */
/*   Updated: 2023/04/17 20:52:06 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				put_wall(mlx, j, i);
			else if (mlx->map[i][j] == 'P')
				put_hero(mlx, j, i);
			else if (mlx->map[i][j] == 'C')
				put_coll(mlx, j, i);
			else if (mlx->map[i][j] == 'E')
				put_portal(mlx, j, i);
			j++;
		}
		i++;
	}
}

int	game_render(t_mlx *mlx)
{
	clear_window(mlx, &mlx->img);
	my_background_fill(mlx->img,
		(IMG_WIDTH * mlx->m_map.map_line_len),
		(IMG_HEIGHT * mlx->m_map.map_lines));
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	put_images(mlx);
	mlx_do_sync(mlx->mlx);
	return (1);
}

int	close_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
	{
		free(mlx->map[i]);
		i++;
	}
	free (mlx->map);
	mlx_destroy_image(mlx->mlx, mlx->wall.img);
	mlx_destroy_image(mlx->mlx, mlx->hero.img);
	mlx_destroy_image(mlx->mlx, mlx->gem.img);
	mlx_destroy_image(mlx->mlx, mlx->portal.img);
	mlx_destroy_window (mlx->mlx, mlx->mlx_win);
	exit (0);
	return (0);
}

int	run_game(t_mlx *mlx, int ac)
{
	if (mlx->m_map.map_lines && mlx->m_map.map_line_len
		&& ft_strstr(mlx->m_map.map_file, ".ber")
		&& ac == 2 && mlx->m_map.map_lines)
	{
		init_mlx(mlx);
		mlx->steps = 0;
		mlx_hook(mlx->mlx_win, 17, 0, close_game, mlx);
		mlx_hook(mlx->mlx_win, 2, 0, key_press, mlx);
		mlx_loop_hook(mlx->mlx, game_render, mlx);
		mlx_loop(mlx->mlx);
	}
	else
	{
		write(1, "Oops, somethings wents wrong", 29);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		run;
	int		i;

	mlx.m_map.map_file = argv[1];
	mlx.m_map.fd = open(mlx.m_map.map_file, O_RDONLY);
	mlx.map = get_map(mlx.m_map.fd, mlx.m_map.map_file);
	if (mlx.map)
	{
		mlx.m_map.map_lines = map_checker(mlx.map);
		mlx.m_map.map_line_len = ft_strlen(mlx.map[0]) - 1;
		run = run_game(&mlx, argc);
		if (!run)
			return (0);
	}
	else
	{
		write(1, "Error\nPlease check your map file", 33);
		return (0);
	}
	i = -1;
	while (mlx.map[++i])
		free(mlx.map[i]);
	free(mlx.map);
	return (0);
}
