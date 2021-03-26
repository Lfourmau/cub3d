/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:12:12 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/26 13:06:24 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_column(big_struct *bs, int x, int y)
{
	int i = 0;
	int j;
	int begin_wall = bs->ps->vertic_res / 2 - y / 2;
	int end_wall = bs->ps->vertic_res / 2 + y / 2;

	while (i < bs->ps->horiz_res)
	{
		j = 0;
		while (j < begin_wall)
		{
			my_mlx_pixel_put(bs, x, j, bs->ps->color_c);
			j++;
		}
		while (j < end_wall)
		{
			my_mlx_pixel_put(bs, x, j, 16731903);
			j++;
		}
		while (j < bs->ps->vertic_res)
		{
			my_mlx_pixel_put(bs, x, j, bs->ps->color_f);
			j++;
		}
		i++;
	}
}