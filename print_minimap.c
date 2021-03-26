/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:58:30 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/26 13:56:35 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            my_mlx_pixel_put(big_struct *bs, int x, int y, int color)
{
    char    *dst;

    dst = bs->ws->img_ptr + (y * bs->ws->line_length + x * (bs->ws->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void print_square(big_struct *bs, int posx, int posy, int color)
{
	int x = 0;
	int y = 0;
	
	while (y <= bs->ws->multiplicator)
	{
		x = 0;
		while (x <= bs->ws->multiplicator)
		{
			my_mlx_pixel_put(bs, posx + x, posy + y, color);
			x++;
		}
		y++;
	}
}

void print_direction(big_struct *bs, int posx, int posy, int color)
{
	int x = 0;
	int y = 0;
	
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			my_mlx_pixel_put(bs, posx + x, posy + y, color);
			x++;
		}
		y++;
	}
}

void	print_minimap(big_struct *bs)
{
	int i = 0;
	int j;
	while (bs->ms->map[i])
	{
		j = 0;
		while (bs->ms->map[i][j])
		{
			if (bs->ms->map[i][j] != '1' && bs->ms->map[i][j] != ' ')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 15327486);
			if (bs->ms->map[i][j] == '1')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 5405748);
			else if (bs->ms->map[i][j] == '2')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 10446148);
			else if (bs->ms->map[i][j] == '0')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 15327486);
			j++;
			bs->ws->minimap_pos_x += bs->ws->multiplicator;
		}
		bs->ws->minimap_pos_x = 0;
		bs->ws->minimap_pos_y += bs->ws->multiplicator;
		i++;
	}
	bs->ws->minimap_pos_x = 0;
	bs->ws->minimap_pos_y = 0;
}