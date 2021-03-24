/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:01:43 by loic              #+#    #+#             */
/*   Updated: 2021/03/24 18:30:05 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(big_struct *bs)
{
	bs->rs->mapx = (int)bs->ws->player_pos_x;
	bs->rs->mapy = (int)bs->ws->player_pos_y;
	//bs->rs->ystep = 1; egal a un bloc car on cherche lignes horizontales, donc la question est de savoir combien de x on decale pour un y
	bs->rs->deltax =  sqrt(1 + (sin(bs->ws->p_angle) * sin(bs->ws->p_angle)) / (cos(bs->ws->p_angle) * cos(bs->ws->p_angle)));
	bs->rs->deltay =  sqrt(1 + (cos(bs->ws->p_angle) * cos(bs->ws->p_angle)) / (sin(bs->ws->p_angle) * sin(bs->ws->p_angle)));
 	if (bs->ws->p_angle > M_PI / 2 && bs->ws->p_angle < 3 * M_PI / 2)
     {
       bs->rs->xstep = -1;
       bs->rs->xnear = (bs->ws->player_pos_x - bs->rs->mapx) * bs->rs->deltax;
     }
     else
     {
       bs->rs->xstep = 1;
	   bs->rs->xnear = (bs->rs->mapx + 1.0 - bs->ws->player_pos_x) * bs->rs->deltax;
     }
     if (bs->ws->p_angle > 0 && bs->ws->p_angle < M_PI)
     {
       bs->rs->ystep = -1;
       bs->rs->ynear = (bs->ws->player_pos_y - bs->rs->mapy) * bs->rs->deltay;
     }
     else
     {
       bs->rs->ystep = 1;
	   bs->rs->ynear = (bs->rs->mapy + 1.0 - bs->ws->player_pos_y) * bs->rs->deltay;
     }
	  while (bs->rs->hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
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
        //Check if ray has hit a wall
        if (bs->ms->map[bs->rs->mapy][bs->rs->mapx] == '1')
		{
			bs->rs->hit = 1;
			print_square(bs, bs->rs->mapx * bs->ws->multiplicator, bs->rs->mapy * bs->ws->multiplicator, 16728575);
			break;
		}

      } 
}