/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:47:54 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/22 14:51:00 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_horiz_inter(big_struct *bs)
{
	float	dir_x;
	float	dir_y;
	int i;
	int j;

	j = 1;
	dir_x = bs->ws->player_pos_x + cos(bs->ws->p_angle);
	dir_y = bs->ws->player_pos_y - sin(bs->ws->p_angle);


}