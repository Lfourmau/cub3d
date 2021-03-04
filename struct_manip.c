/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:38:42 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/04 17:39:08 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_struct_init(parse_struct *ps, map_struct *ms)
{
	ps->horiz_res = 0;
 	ps->vertic_res = 0;
	ps->color_f = 0;
	ps->color_c = 0;
	ps->NO = 0;
	ps->SO = 0;
	ps->WE = 0;
	ps->EA = 0;
	ps->S = 0;
	ms->nb_spawns = 0;
}

int		check_struct(parse_struct *ps, map_struct *ms)
{
	if (ms->map == 0)
		return (1);
	if (ps->horiz_res == 0 || ps->vertic_res == 0
	|| ps->color_c == 0 || ps->color_f == 0
	|| ps->NO == 0 || ps->S == 0 || ps->SO == 0 || ps->EA == 0 
	|| ps->WE == 0)
		return (1);
	return (0);
}
