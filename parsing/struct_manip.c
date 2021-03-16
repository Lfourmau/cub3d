/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:38:42 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/16 08:32:31 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing_struct_init(big_struct *bs)
{
	bs->ps->horiz_res = 0;
 	bs->ps->vertic_res = 0;
	bs->ps->color_f = -1;
	bs->ps->color_c = -1;
	bs->ps->NO = 0;
	bs->ps->SO = 0;
	bs->ps->WE = 0;
	bs->ps->EA = 0;
	bs->ps->S = 0;
	bs->ms->nb_spawns = 0;
	bs->ms->map = NULL;
	bs->ws->player_pos_x = 0;
	bs->ws->player_pos_y = 0;
	bs->ws->minimap_pos_x = 0;
	bs->ws->minimap_pos_y = 0;
}

int		check_struct(big_struct *bs)
{
	if (bs->ps->horiz_res == 0 || bs->ps->vertic_res == 0
	|| bs->ps->color_c == -1 || bs->ps->color_f == -1
	|| bs->ps->NO == 0 || bs->ps->S == 0 || bs->ps->SO == 0 || bs->ps->EA == 0 
	|| bs->ps->WE == 0)
		return (1);
	if (bs->ms->map == 0)
		return (2);
	return (0);
}
