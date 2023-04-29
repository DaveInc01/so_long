/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:30:20 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/02 20:29:35 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_HEIGHT 100
# define IMG_WIDTH 100

# include "get_next_line.h"
# include "ft_printf.h"
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img
{
	char	*relative_path;
	int		width;
	int		height;
	void	*img;
}				t_img;

typedef struct s_map
{
	int		fd;
	int		map_lines;
	int		map_line_len;
	char	*map_file;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		steps;
	t_map	m_map;
	t_data	img;
	t_img	wall;
	t_img	hero;
	t_img	gem;
	t_img	portal;
}				t_mlx;

void	put_wall(t_mlx *mlx, int x, int y);
void	put_hero(t_mlx *mlx, int x, int y);
void	put_coll(t_mlx *mlx, int x, int y);
void	put_portal(t_mlx *mlx, int x, int y);
int		arr_line_len(char **arr);
int		map_collectable_count(char **map);
int		get_hero_column(char **map);
int		get_hero_row(char **map);
int		move_up(t_mlx *mlx);
int		move_left(t_mlx *mlx);
int		move_down(t_mlx *mlx);
int		move_right(t_mlx *mlx);
int		close_game(t_mlx *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_background_fill(t_data img, int width, int height);
void	clear_window(t_mlx *mlx, t_data *img);
int		map_checker(char **map);
void	init_mlx(t_mlx *mlx);
void	get_textures(t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);
int		only_one_in_line(char *line);
int		line_valid(char *line, int line_len, int order, int lines_count);
int		lines_count(int fd);
void	line_fill(char **map, char *line, int line_len, int i);

#endif
