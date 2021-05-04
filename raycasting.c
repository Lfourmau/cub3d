/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:01:43 by loic              #+#    #+#             */
/*   Updated: 2021/05/04 08:38:38 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_column(t_big_struct *bs, int x, float y)
{
	int	j;

	j = -1;
	bs->rs->begin_wall = bs->ps->vertic_res / 2 - y / 2;
	bs->rs->end_wall = bs->ps->vertic_res / 2 + y / 2;
	bs->rs->wall_onscreen_size = bs->rs->end_wall - bs->rs->begin_wall;
	while (++j < bs->rs->begin_wall && j < bs->ps->vertic_res)
		my_mlx_pixel_put(bs, x, j, bs->ps->color_c);
	if (bs->rs->side == 1 && bs->rs->r_angle > 0 && bs->rs->r_angle < M_PI)
		put_wall_south(bs, x, j);
	else if (bs->rs->side == 1 && bs->rs->r_angle > M_PI && bs->rs->r_angle < 2 * M_PI)
		put_wall_north(bs, x, j);
	else if (bs->rs->side == 0 && bs->rs->r_angle > M_PI / 2 && bs->rs->r_angle < 3 * M_PI / 2)
		put_wall_east(bs, x, j);
	else
		put_wall_west(bs, x, j);
	j = bs->rs->end_wall - 1;
	while (++j < bs->ps->vertic_res)
		my_mlx_pixel_put(bs, x, j, bs->ps->color_f);
}

static void	check_step(t_big_struct *bs, float angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
	{
		bs->rs->xstep = -1;
		bs->rs->xnear = (bs->ws->player_pos.x - bs->rs->map_case.x) * bs->rs->deltax;
	}
	else
	{
		bs->rs->xstep = 1;
		bs->rs->xnear = (bs->rs->map_case.x + 1.0 - bs->ws->player_pos.x) * bs->rs->deltax;
	}
	if (angle > 0 && angle < M_PI)
	{
		bs->rs->ystep = -1;
		bs->rs->ynear = (bs->ws->player_pos.y - bs->rs->map_case.y) * bs->rs->deltay;
	}
	else
	{
		bs->rs->ystep = 1;
		bs->rs->ynear = (bs->rs->map_case.y + 1.0 - bs->ws->player_pos.y) * bs->rs->deltay;
	}
}

static void	check_hit(t_big_struct *bs, int i)
{
	t_sprites_struct	spritestab[50];

	bs->ss->spritenum = 0;
	while (bs->rs->hit == 0)
	{
		if (bs->rs->xnear < bs->rs->ynear)
		{
			bs->rs->raydist = bs->rs->xnear;
			bs->rs->xnear += bs->rs->deltax;
			bs->rs->map_case.x += bs->rs->xstep;
			bs->rs->side = 0;
		}
		else
		{
			bs->rs->raydist = bs->rs->ynear;
			bs->rs->ynear += bs->rs->deltay;
			bs->rs->map_case.y += bs->rs->ystep;
			bs->rs->side = 1;
		}
		if (bs->ms->map[bs->rs->map_case.y][bs->rs->map_case.x] == '2')
		{
			bs->ss->spritenum++;
			sprite_infos(bs, &spritestab[bs->ss->spritenum]);
		}
		else if (bs->ms->map[bs->rs->map_case.y][bs->rs->map_case.x] && (bs->ms->map[bs->rs->map_case.y][bs->rs->map_case.x] == '1' || bs->ms->map[bs->rs->map_case.y][bs->rs->map_case.x] == '3'))
		{
			bs->rs->hit = 1;
			bs->rs->inter_wall.x = bs->ws->player_pos.y + bs->rs->base_x * bs->rs->raydist;
			bs->rs->inter_wall.y = bs->ws->player_pos.x + bs->rs->base_y * bs->rs->raydist;
			bs->rs->raydist *= cos(bs->ws->p_angle - bs->rs->r_angle);
			//TODO : mettre le raydist a 0.01 si il vaut 0 pour ne pas segfault dans certains cas
			bs->rs->wall_height = bs->ps->vertic_res / bs->rs->raydist;
			print_column(bs, i, bs->rs->wall_height);
		}
	}
	if (bs->ss->spritenum > 0)
		put_all_sprites(bs, i, spritestab);
	bs->rs->hit = 0;
}

static void	raycasting(t_big_struct *bs, float angle, int i)
{
	bs->rs->map_case.x = (int)bs->ws->player_pos.x;
	bs->rs->map_case.y = (int)bs->ws->player_pos.y;
	bs->rs->deltax = sqrt(1 + (sin(angle) * sin(angle)) / (cos(angle) * cos(angle)));
	bs->rs->deltay = sqrt(1 + (cos(angle) * cos(angle)) / (sin(angle) * sin(angle)));
	check_step(bs, angle);
	check_hit(bs, i);
}

void	raycasting_loop(t_big_struct *bs)
{
	int		i;
	float	ratioangle;

	ratioangle = (60 * 0.0174532925) / bs->ps->horiz_res;
	i = -1;
	bs->rs->r_angle = bs->ws->p_angle + 30 * 0.0174532925;
	xpm_init(bs);
	while (++i < bs->ps->horiz_res)
	{
		if (bs->rs->r_angle > 2 * M_PI)
			bs->rs->r_angle -= 2 * M_PI;
		if (bs->rs->r_angle < 0)
			bs->rs->r_angle += 2 * M_PI;
		rotate_vector(bs);
		raycasting(bs, bs->rs->r_angle, i);
		bs->rs->r_angle -= ratioangle;
	}
}
