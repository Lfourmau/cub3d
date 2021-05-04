/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:41:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 11:19:11 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_init(t_big_struct *bs)
{
	bs->ts.n.img = mlx_xpm_file_to_image(bs->ws.mlx_ptr, bs->ps.NO, &bs->ts.n.width, &bs->ts.n.height);
	bs->ts.s.img = mlx_xpm_file_to_image(bs->ws.mlx_ptr, bs->ps.SO, &bs->ts.s.width, &bs->ts.s.height);
	bs->ts.e.img = mlx_xpm_file_to_image(bs->ws.mlx_ptr, bs->ps.EA, &bs->ts.e.width, &bs->ts.e.height);
	bs->ts.w.img = mlx_xpm_file_to_image(bs->ws.mlx_ptr, bs->ps.WE, &bs->ts.w.width, &bs->ts.w.height);
	bs->ts.sp.img = mlx_xpm_file_to_image(bs->ws.mlx_ptr, bs->ps.S, &bs->ts.sp.width, &bs->ts.sp.height);
	bs->ts.n.buff = mlx_get_data_addr(bs->ts.n.img, &bs->ts.n.bits_per_pixel, &bs->ts.n.line_length, &bs->ts.n.endian);
	bs->ts.s.buff = mlx_get_data_addr(bs->ts.s.img, &bs->ts.s.bits_per_pixel, &bs->ts.s.line_length, &bs->ts.s.endian);
	bs->ts.e.buff = mlx_get_data_addr(bs->ts.e.img, &bs->ts.e.bits_per_pixel, &bs->ts.e.line_length, &bs->ts.e.endian);
	bs->ts.w.buff = mlx_get_data_addr(bs->ts.w.img, &bs->ts.w.bits_per_pixel, &bs->ts.w.line_length, &bs->ts.w.endian);
	bs->ts.sp.buff = mlx_get_data_addr(bs->ts.sp.img, &bs->ts.sp.bits_per_pixel, &bs->ts.sp.line_length, &bs->ts.sp.endian);
}

void	put_wall_north(t_big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int		color;

	i = 0;
	if (bs->rs.begin_wall < 0)
		i = 0 - bs->rs.begin_wall;
	texture_x = bs->ts.n.width * (bs->rs.inter_wall.y - (int)bs->rs.inter_wall.y);
	ratio = (float)bs->ts.n.height / bs->rs.wall_onscreen_size;
	while (i < bs->rs.wall_onscreen_size && j < bs->ps.vertic_res)
	{
		color = bs->ts.n.buff[texture_x + (int)((float)(i) *ratio) *64];
		my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}

void	put_wall_south(t_big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int		color;

	i = 0;
	if (bs->rs.begin_wall < 0)
		i = 0 - bs->rs.begin_wall;
	texture_x = bs->ts.s.width * (bs->rs.inter_wall.y - (int)bs->rs.inter_wall.y);
	ratio = (float)bs->ts.s.height / bs->rs.wall_onscreen_size;
	while (i < bs->rs.wall_onscreen_size && j < bs->ps.vertic_res)
	{
		color = bs->ts.s.buff[texture_x + (int)((float)(i) *ratio) *64];
		my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}

void	put_wall_west(t_big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int		color;

	i = 0;
	if (bs->rs.begin_wall < 0)
		i = 0 - bs->rs.begin_wall;
	texture_x = bs->ts.w.width * (bs->rs.inter_wall.x - (int)bs->rs.inter_wall.x);
	ratio = (float)bs->ts.w.height / bs->rs.wall_onscreen_size;
	while (i < bs->rs.wall_onscreen_size && j < bs->ps.vertic_res)
	{
		color = bs->ts.w.buff[texture_x + (int)((float)(i) *ratio) *64];
		my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}

void	put_wall_east(t_big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int		color;

	i = 0;
	if (bs->rs.begin_wall < 0)
		i = 0 - bs->rs.begin_wall;
	texture_x = bs->ts.e.width * (bs->rs.inter_wall.x - (int)bs->rs.inter_wall.x);
	ratio = (float)bs->ts.e.height / bs->rs.wall_onscreen_size;
	while (i < bs->rs.wall_onscreen_size && j < bs->ps.vertic_res)
	{
		color = bs->ts.e.buff[texture_x + (int)((float)(i) *ratio) *64];
		my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}
