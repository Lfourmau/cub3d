/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:01:43 by loic              #+#    #+#             */
/*   Updated: 2021/05/04 11:18:13 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_step(t_big_struct *bs, float angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
	{
		bs->rs.xstep = -1;
		bs->rs.xnear = (bs->ws.player_pos.x - bs->rs.map_case.x) * bs->rs.deltax;
	}
	else
	{
		bs->rs.xstep = 1;
		bs->rs.xnear = (bs->rs.map_case.x + 1.0 - bs->ws.player_pos.x) * bs->rs.deltax;
	}
	if (angle > 0 && angle < M_PI)
	{
		bs->rs.ystep = -1;
		bs->rs.ynear = (bs->ws.player_pos.y - bs->rs.map_case.y) * bs->rs.deltay;
	}
	else
	{
		bs->rs.ystep = 1;
		bs->rs.ynear = (bs->rs.map_case.y + 1.0 - bs->ws.player_pos.y) * bs->rs.deltay;
	}
}

static void	check_hit(t_big_struct *bs, int i)
{
	t_sprites_struct	spritestab[50];

	bs->ss.spritenum = 0;
	while (bs->rs.hit == 0)
	{
		moove_ray(bs);
		if (bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] == '2')
		{
			bs->ss.spritenum++;
			sprite_infos(bs, &spritestab[bs->ss.spritenum]);
		}
		else if (bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] && (bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] == '1' || bs->ms.map[bs->rs.map_case.y][bs->rs.map_case.x] == '3'))
		{
			bs->rs.hit = 1;
			bs->rs.inter_wall.x = bs->ws.player_pos.y + bs->rs.base_x * bs->rs.raydist;
			bs->rs.inter_wall.y = bs->ws.player_pos.x + bs->rs.base_y * bs->rs.raydist;
			bs->rs.raydist *= cos(bs->ws.p_angle - bs->rs.r_angle);
			//TODO : mettre le raydist a 0.01 si il vaut 0 pour ne pas segfault dans certains cas
			bs->rs.wall_height = bs->ps.vertic_res / bs->rs.raydist;
			print_column(bs, i, bs->rs.wall_height);
		}
	}
	if (bs->ss.spritenum > 0)
		put_all_sprites(bs, i, spritestab);
	bs->rs.hit = 0;
}

static void	raycasting(t_big_struct *bs, float angle, int i)
{
	bs->rs.map_case.x = (int)bs->ws.player_pos.x;
	bs->rs.map_case.y = (int)bs->ws.player_pos.y;
	bs->rs.deltax = sqrt(1 + (sin(angle) * sin(angle)) / (cos(angle) * cos(angle)));
	bs->rs.deltay = sqrt(1 + (cos(angle) * cos(angle)) / (sin(angle) * sin(angle)));
	check_step(bs, angle);
	check_hit(bs, i);
}

void	raycasting_loop(t_big_struct *bs)
{
	int		i;
	float	ratioangle;

	ratioangle = (60 * 0.0174532925) / bs->ps.horiz_res;
	i = -1;
	bs->rs.r_angle = bs->ws.p_angle + 30 * 0.0174532925;
	xpm_init(bs);
	while (++i < bs->ps.horiz_res)
	{
		if (bs->rs.r_angle > 2 * M_PI)
			bs->rs.r_angle -= 2 * M_PI;
		if (bs->rs.r_angle < 0)
			bs->rs.r_angle += 2 * M_PI;
		rotate_vector(bs);
		raycasting(bs, bs->rs.r_angle, i);
		bs->rs.r_angle -= ratioangle;
	}
}
