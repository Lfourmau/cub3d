/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:03:19 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 11:20:00 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	multiplicator(t_big_struct *bs)
{
	if (bs->ps.vertic_res / number_of_split(bs->ms.map) > \
	bs->ps.horiz_res / max_len_map(bs->ms.map))
		bs->ws.mltp = (bs->ps.horiz_res / max_len_map(bs->ms.map)) / 2.5;
	else
		bs->ws.mltp = (bs->ps.horiz_res / max_len_map(bs->ms.map)) / 2.5;
}

void	detect_spawn_dir(t_big_struct *bs)
{
	if (bs->ms.spawn == 'S')
		bs->ws.p_angle = 3 * M_PI / 2;
	else if (bs->ms.spawn == 'N')
		bs->ws.p_angle = M_PI / 2;
	else if (bs->ms.spawn == 'W')
		bs->ws.p_angle = M_PI;
	else if (bs->ms.spawn == 'E')
		bs->ws.p_angle = 0;
}

void	rotate_vector(t_big_struct *bs)
{	
	bs->rs.base_x = 0 * cos(bs->rs.r_angle) - 1 * sin(bs->rs.r_angle);
	bs->rs.base_y = 0 * sin(bs->rs.r_angle) + 1 * cos(bs->rs.r_angle);
}
