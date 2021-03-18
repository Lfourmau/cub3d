/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:03:19 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/18 12:42:45 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		multiplicator(big_struct *bs)
{
	if (bs->ps->vertic_res / number_of_split(bs->ms->map) > bs->ps->horiz_res / max_len_map(bs->ms->map))
		bs->ws->multiplicator = bs->ps->horiz_res / max_len_map(bs->ms->map);
	else
		bs->ws->multiplicator = bs->ps->horiz_res / max_len_map(bs->ms->map);
}

void	detect_spawn_dir(big_struct *bs)
{
	if (bs->ms->spawn == 'S')
		bs->ws->p_angle = (3 * M_PI) / 2;
	else if (bs->ms->spawn == 'N')
		bs->ws->p_angle = M_PI / 2;
	else if (bs->ms->spawn == 'W')
		bs->ws->p_angle = M_PI;
	else if (bs->ms->spawn == 'E')
		bs->ws->p_angle = 0;
}