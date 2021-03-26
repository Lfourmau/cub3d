/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:57:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/26 14:39:09 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmoove(big_struct *bs)
{
	if (bs->ms->map[(int)(bs->ws->player_pos_y - sin(bs->ws->p_angle))][(int)bs->ws->player_pos_x] != '1')
		bs->ws->player_pos_y -= sin(bs->ws->p_angle);
	if (bs->ms->map[(int)bs->ws->player_pos_y][(int)(bs->ws->player_pos_x + cos(bs->ws->p_angle))] != '1')
		bs->ws->player_pos_x += cos(bs->ws->p_angle);
	bs->ws->key_press = 1;
}

void	smoove(big_struct *bs)
{
	if (bs->ms->map[(int)(bs->ws->player_pos_y + sin(bs->ws->p_angle))][(int)bs->ws->player_pos_x] != '1')
		bs->ws->player_pos_y += sin(bs->ws->p_angle);
	if (bs->ms->map[(int)bs->ws->player_pos_y][(int)(bs->ws->player_pos_x - cos(bs->ws->p_angle))] != '1')
		bs->ws->player_pos_x -= cos(bs->ws->p_angle);
	bs->ws->key_press = 1;
}

void 	amoove(big_struct *bs)
{
	if (bs->ms->map[(int)(bs->ws->player_pos_y - sin(bs->ws->p_angle + (M_PI / 2)))][(int)(bs->ws->player_pos_x)] != '1')
		bs->ws->player_pos_y -= sin(bs->ws->p_angle + (M_PI / 2));
	if (bs->ms->map[(int)(bs->ws->player_pos_y)][(int)(bs->ws->player_pos_x + cos(bs->ws->p_angle + (M_PI / 2)))] != '1')
		bs->ws->player_pos_x += cos(bs->ws->p_angle + (M_PI / 2));
	bs->ws->key_press = 1;
}

void	dmoove(big_struct *bs)
{
	if (bs->ms->map[(int)(bs->ws->player_pos_y + sin(bs->ws->p_angle + (M_PI / 2)))][(int)(bs->ws->player_pos_x)] != '1')
		bs->ws->player_pos_y += sin(bs->ws->p_angle + (M_PI / 2));
	if (bs->ms->map[(int)bs->ws->player_pos_y][(int)(bs->ws->player_pos_x - cos(bs->ws->p_angle + (M_PI / 2)))] != '1')
		bs->ws->player_pos_x -= cos(bs->ws->p_angle + (M_PI / 2));
	bs->ws->key_press = 1;
}

void	lookmoove(big_struct *bs, int key)
{
	if (key == LEFTLOOK)
	{
		bs->ws->p_angle += 0.2;
		if (bs->ws->p_angle > 2 * M_PI)
			bs->ws->p_angle -= 2 * M_PI;
	}

	if (key == RIGHTLOOK)
	{
		bs->ws->p_angle -= 0.2;
		if (bs->ws->p_angle < 0)
			bs->ws->p_angle += 2 * M_PI;
	}
	bs->ws->key_press = 1;
}