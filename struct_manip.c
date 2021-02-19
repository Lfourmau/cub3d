/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:38:42 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/19 08:43:07 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_struct_init(parse_struct *ps)
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
	ps->color_f = 0;
	ps->color_c = 0;
}
