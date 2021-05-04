/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:57:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 11:16:56 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmoove(t_big_struct *bs)
{
	if (bs->ks.w == 1)
	{
		if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle))][(int)bs->ws.player_pos.x] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle))][(int)bs->ws.player_pos.x] != '2')
				bs->ws.player_pos.y -= sin(bs->ws.p_angle) / 4;
		if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle))] != '1')
			if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle))] != '2')
				bs->ws.player_pos.x += cos(bs->ws.p_angle) / 4;
	}
}

void	smoove(t_big_struct *bs)
{
	if (bs->ks.s == 1)
	{
		if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle))][(int)bs->ws.player_pos.x] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle))][(int)bs->ws.player_pos.x] != '2')
				bs->ws.player_pos.y += sin(bs->ws.p_angle) / 4;
		if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x - cos(bs->ws.p_angle))] != '1')
			if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x - cos(bs->ws.p_angle))] != '2')
				bs->ws.player_pos.x -= cos(bs->ws.p_angle) / 4;
	}
}

void 	sidemooves(t_big_struct *bs)
{
	if (bs->ks.a == 1)
	{
		if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle + (M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y - sin(bs->ws.p_angle + (M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '2')
				bs->ws.player_pos.y -= sin(bs->ws.p_angle + (M_PI / 2)) / 4;
		if (bs->ms.map[(int)(bs->ws.player_pos.y)][(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle + (M_PI / 2)))] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y)][(int)(bs->ws.player_pos.x + cos(bs->ws.p_angle + (M_PI / 2)))] != '2')
				bs->ws.player_pos.x += cos(bs->ws.p_angle + (M_PI / 2)) / 4;
	}
	else if (bs->ks.d == 1)
	{
		if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle + (M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '1')
			if (bs->ms.map[(int)(bs->ws.player_pos.y + sin(bs->ws.p_angle + (M_PI / 2)))][(int)(bs->ws.player_pos.x)] != '2')
				bs->ws.player_pos.y += sin(bs->ws.p_angle + (M_PI / 2)) / 4;
		if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x - cos(bs->ws.p_angle + (M_PI / 2)))] != '1')
			if (bs->ms.map[(int)bs->ws.player_pos.y][(int)(bs->ws.player_pos.x - cos(bs->ws.p_angle + (M_PI / 2)))] != '2')
				bs->ws.player_pos.x -= cos(bs->ws.p_angle + (M_PI / 2)) / 4;
	}
}

void	lookmoove(t_big_struct *bs)
{
	if (bs->ks.left == 1)
	{
		bs->ws.p_angle += M_PI / 25;
		if (bs->ws.p_angle > 2 * M_PI)
			bs->ws.p_angle -= 2 * M_PI;
	}
	else if (bs->ks.right == 1)
	{
		bs->ws.p_angle -= M_PI / 25;
		if (bs->ws.p_angle < 0)
			bs->ws.p_angle += 2 * M_PI;
	}
}

void	updatecoord(t_big_struct *bs)
{
	wmoove(bs);
	smoove(bs);
	sidemooves(bs);
	lookmoove(bs);
}
