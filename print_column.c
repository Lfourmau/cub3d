/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:12:12 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/26 11:19:44 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_column(big_struct *bs, int x, int y)
{
	int i = 0;
	int j = 0;

	while (i < bs->ps->horiz_res)
	{
		j = 0;
		while (j < y)
		{
			my_mlx_pixel_put(bs, x, j, 16731903);
			j++;
		}
		i++;
	}
}