/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:57:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/24 18:30:04 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmoove(big_struct *bs)
{
	bs->ws->player_pos_y -= sin(bs->ws->p_angle);
	bs->ws->player_pos_x += cos(bs->ws->p_angle);
}

void	smoove(big_struct *bs)
{

	bs->ws->player_pos_y += sin(bs->ws->p_angle);
	bs->ws->player_pos_x -= cos(bs->ws->p_angle);
}

void 	amoove(big_struct *bs)
{
	bs->ws->player_pos_y -= sin(bs->ws->p_angle + (M_PI / 2));
	bs->ws->player_pos_x += cos(bs->ws->p_angle + (M_PI / 2));
}

void	dmoove(big_struct *bs)
{
	bs->ws->player_pos_y += sin(bs->ws->p_angle + (M_PI / 2));
	bs->ws->player_pos_x -= cos(bs->ws->p_angle + (M_PI / 2));
}

void	lookmoove(big_struct *bs, int key)
{
	if (key == LEFTLOOK)
		bs->ws->p_angle += 0.3;
	if (key == RIGHTLOOK)
		bs->ws->p_angle -= 0.3;
}