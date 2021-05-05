/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:47:02 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/05 10:14:59 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_x(t_point a1, t_point b1, float	slope_a, float slope_b)
{
	return ((slope_a * a1.x - slope_b * b1.x + b1.y - a1.y) \
		/ (slope_a - slope_b));
}

double	line_slope(float a1, float a2, float b1, float b2)
{
	if (a1 - b1 == 0.0)
		return (NAN);
	else
		return ((a2 - b2) / (a1 - b1));
}

t_point	intersection_sprite(t_big_struct *bs, t_point a1, t_point b1, t_point b2)
{
	double	slope_a;
	double	slope_b;
	t_point	res;
	t_point	a2;

	a2.x = bs->ws.player_pos.x + cos(bs->rs.r_angle);
	a2.y = bs->ws.player_pos.y - sin(bs->rs.r_angle);
	slope_a = line_slope(a1.x, a1.y, a2.x, a2.y);
	slope_b = line_slope(b1.x, b1.y, b2.x, b2.y);
	if (isnan(slope_a) && !isnan(slope_b))
	{
		res.x = a1.x;
		res.y = (a1.x - b1.x) * slope_b + b1.y;
	}
	else if (isnan(slope_b) && !isnan(slope_a))
	{
		res.x = b1.x;
		res.y = (b1.x - a1.x) * slope_a + a1.y;
	}
	else
	{
		res.x = set_x(a1, b1, slope_a, slope_b);
		res.y = slope_b * (res.x - b1.x) + b1.y;
	}
	return (res);
}

void	sprite_infos(t_big_struct *bs, t_sprites_struct *spritestab)
{
	spritestab->center_sprite.x = bs->rs.map_case.x + 0.5;
	spritestab->center_sprite.y = bs->rs.map_case.y + 0.5;
	spritestab->secondpoint.x = spritestab->center_sprite.x + cos(bs->ws.p_angle + (M_PI / 2));
	spritestab->secondpoint.y = spritestab->center_sprite.y - sin(bs->ws.p_angle + (M_PI / 2));
	spritestab->inter_sprite = intersection_sprite(bs, bs->ws.player_pos, spritestab->center_sprite, spritestab->secondpoint);
	spritestab->raydist_sprite = sqrt(pow(spritestab->center_sprite.x - bs->ws.player_pos.x, 2) + pow(spritestab->center_sprite.y - bs->ws.player_pos.y, 2));
	//bs->ss->raydist_sprite *= cos(bs->ws.p_angle - bs->rs.r_angle) / 1.33;
	spritestab->sprite_onscreen_size = bs->ps.vertic_res / spritestab->raydist_sprite;
	spritestab->begin_sprite = bs->ps.vertic_res / 2 - spritestab->sprite_onscreen_size / 2;
	spritestab->mapx_sprite = bs->rs.map_case.x;
	spritestab->mapy_sprite = bs->rs.map_case.y;
}

void	put_sprite(t_big_struct *bs, int x, int j, t_sprites_struct sprite)
{
	int		texture_x;
	float	ratio;
	int		i;
	int		color;
	float	distance;

	i = 0;
	distance = dist(sprite.center_sprite.x, sprite.inter_sprite.x, sprite.center_sprite.y, sprite.inter_sprite.y);
	if ((bs->ws.p_angle < M_PI && sprite.center_sprite.x > sprite.inter_sprite.x) || (bs->ws.p_angle > M_PI && sprite.center_sprite.x < sprite.inter_sprite.x))
		distance *= -1;
	// else if ((bs->ws.p_angle == M_PI || bs->ws.p_angle ==  0) && sprite.center_sprite.y > sprite.inter_sprite.y)
	// 	distance *= -1;
	texture_x = bs->ts.sp.width / 2 + bs->ts.sp.width * distance;
	ratio = (float)bs->ts.sp.height / sprite.sprite_onscreen_size;
	while (i < sprite.sprite_onscreen_size && j < bs->ps.vertic_res)
	{
		if (texture_x <= 63 && texture_x >= 0)
		{
			color = bs->ts.sp.buff[texture_x + (int)((float)(i) *ratio) *bs->ts.sp.width];
			if (color != 0)
				my_mlx_pixel_put(bs, x, j, color);
		}
		j++;
		i++;
	}
}
