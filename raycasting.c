/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:01:43 by loic              #+#    #+#             */
/*   Updated: 2021/03/25 11:17:01 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_step(big_struct *bs, float angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
	{
		bs->rs->xstep = -1;
		bs->rs->xnear = (bs->ws->player_pos_x - bs->rs->mapx) * bs->rs->deltax;
	}
	else
	{
		bs->rs->xstep = 1;
		bs->rs->xnear = (bs->rs->mapx + 1.0 - bs->ws->player_pos_x) * bs->rs->deltax;
	}
	if (angle > 0 && angle < M_PI)
	{
		bs->rs->ystep = -1;
		bs->rs->ynear = (bs->ws->player_pos_y - bs->rs->mapy) * bs->rs->deltay;
	}
	else
	{
		bs->rs->ystep = 1;
		bs->rs->ynear = (bs->rs->mapy + 1.0 - bs->ws->player_pos_y) * bs->rs->deltay;
	}
}

void	check_hit(big_struct *bs)
{
	while (bs->rs->hit == 0)
	{
		//choix de la bonne direction pour le prochain carré
		if (bs->rs->xnear < bs->rs->ynear)
		{
			bs->rs->xnear += bs->rs->deltax;
			bs->rs->mapx += bs->rs->xstep;
			bs->rs->side = 0;
		}
		else
		{
			bs->rs->ynear += bs->rs->deltay;
			bs->rs->mapy += bs->rs->ystep;
			bs->rs->side = 1;
		}
		//touche un mur ou pas
		if (bs->ms->map[bs->rs->mapy][bs->rs->mapx] && bs->ms->map[bs->rs->mapy][bs->rs->mapx] == '1')
		{
			bs->rs->hit = 1;
			print_square(bs, bs->rs->mapx * bs->ws->multiplicator, bs->rs->mapy * bs->ws->multiplicator, 16722254);
		}
	}
	bs->rs->hit = 0;
}

void	raycasting(big_struct *bs, float angle)
{
	bs->rs->mapx = (int)bs->ws->player_pos_x;//pos est en float, on int pour avoir l'index
	bs->rs->mapy = (int)bs->ws->player_pos_y;//pos est en float, on int pour avoir l'index
	bs->rs->deltax =  sqrt(1 + (sin(angle) * sin(angle)) / (cos(angle) * cos(angle)));
	bs->rs->deltay =  sqrt(1 + (cos(angle) * cos(angle)) / (sin(angle) * sin(angle)));
	check_step(bs, angle); //permet de se decaler en fonction de l'angle
	check_hit(bs); //on check le next carré et verifie si c'est un mur ou non
}