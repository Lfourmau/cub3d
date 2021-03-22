/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:57:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/22 14:27:06 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmoove(big_struct *bs)
{
	bs->ws->player_pos_y -= sin(bs->ws->p_angle);
	bs->ws->player_pos_x += cos(bs->ws->p_angle);
	render_next_frame(bs);
}

void	smoove(big_struct *bs)
{

	bs->ws->player_pos_y += sin(bs->ws->p_angle);
	bs->ws->player_pos_x -= cos(bs->ws->p_angle);
	render_next_frame(bs);
}

void 	amoove(big_struct *bs)
{
	bs->ws->player_pos_y -= sin(bs->ws->p_angle + (M_PI / 2));
	bs->ws->player_pos_x += cos(bs->ws->p_angle + (M_PI / 2));
	render_next_frame(bs);
}

void	dmoove(big_struct *bs)
{
	bs->ws->player_pos_y += sin(bs->ws->p_angle + (M_PI / 2));
	bs->ws->player_pos_x -= cos(bs->ws->p_angle + (M_PI / 2));
	render_next_frame(bs);
}

void	lookmoove(big_struct *bs, int key)
{
	if (key == LEFTLOOK)
		bs->ws->p_angle += 0.3;
	if (key == RIGHTLOOK)
		bs->ws->p_angle -= 0.3;
}