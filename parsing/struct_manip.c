/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:38:42 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/10 08:41:37 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing_struct_init(parse_struct *ps, map_struct *ms)
{
	ps->horiz_res = 0;
 	ps->vertic_res = 0;
	ps->color_f = -1;
	ps->color_c = -1;
	ps->NO = 0;
	ps->SO = 0;
	ps->WE = 0;
	ps->EA = 0;
	ps->S = 0;
	ms->nb_spawns = 0;
	ms->map = NULL;
}

int		check_struct(parse_struct *ps, map_struct *ms)
{
	if (ps->horiz_res == 0 || ps->vertic_res == 0
	|| ps->color_c == -1 || ps->color_f == -1
	|| ps->NO == 0 || ps->S == 0 || ps->SO == 0 || ps->EA == 0 
	|| ps->WE == 0)
		return (1);
	if (ms->map == 0)
		return (2);
	return (0);
}
