/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:51:07 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:14:32 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	moove_ray(t_big_struct *bs)
{
	if (bs->rs.xnear < bs->rs.ynear)
	{
		bs->rs.raydist = bs->rs.xnear;
		bs->rs.xnear += bs->rs.deltax;
		bs->rs.map_case.x += bs->rs.xstep;
		bs->rs.side = 0;
	}
	else
	{
		bs->rs.raydist = bs->rs.ynear;
		bs->rs.ynear += bs->rs.deltay;
		bs->rs.map_case.y += bs->rs.ystep;
		bs->rs.side = 1;
	}
}

void	moove_ray_check_wall(t_big_struct *bs, int i)
{
	if (bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] &&
		(bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] == '1' ||
		bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] == '3'))
	{
		bs->rs.hit = 1;
		bs->rs.inter_wall.x = bs->ws.player_pos.y + \
		bs->rs.base_x * bs->rs.raydist;
		bs->rs.inter_wall.y = bs->ws.player_pos.x + \
		bs->rs.base_y * bs->rs.raydist;
		bs->rs.raydist *= cos(bs->ws.p_angle - bs->rs.r_angle);
		if (bs->rs.raydist <= 0.002)
			bs->rs.raydist = 0.002;
		bs->rs.wall_height = bs->ps.vertic_res / bs->rs.raydist;
		print_column(bs, i, bs->rs.wall_height);
	}
}

void	print_column(t_big_struct *bs, int x, float y)
{
	int	j;

	j = -1;
	bs->rs.begin_wall = bs->ps.vertic_res / 2 - y / 2;
	bs->rs.end_wall = bs->ps.vertic_res / 2 + y / 2;
	bs->rs.wall_onscreen_size = bs->rs.end_wall - bs->rs.begin_wall;
	while (++j < bs->rs.begin_wall && j < bs->ps.vertic_res)
		my_mlx_pixel_put(bs, x, j, bs->ps.color_c);
	if (bs->rs.side == 1 && bs->rs.r_angle > 0 && bs->rs.r_angle < M_PI)
		put_wall_south(bs, x, j);
	else if (bs->rs.side == 1 && bs->rs.r_angle > \
	M_PI && bs->rs.r_angle < 2 * M_PI)
		put_wall_north(bs, x, j);
	else if (bs->rs.side == 0 && bs->rs.r_angle > M_PI / \
	2 && bs->rs.r_angle < 3 * M_PI / 2)
		put_wall_east(bs, x, j);
	else
		put_wall_west(bs, x, j);
	j = bs->rs.end_wall - 1;
	while (++j < bs->ps.vertic_res)
		my_mlx_pixel_put(bs, x, j, bs->ps.color_f);
}
