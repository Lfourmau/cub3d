/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:58:30 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:45:50 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_big_struct *bs, int x, int y, int color)
{
	char	*dst;

	if (x < bs->ps->horiz_res && x > 0 && y < bs->ps->vertic_res && y > 0)
	{
		dst = bs->ws->img_ptr + (y * bs->ws->line_length + x * (bs->ws->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	print_square(t_big_struct *bs, int posx, int posy, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= bs->ws->mltp -2 )
	{
		x = 0;
		while (x <= bs->ws->mltp - 2)
		{
			my_mlx_pixel_put(bs, posx + x, posy + y, color);
			x++;
		}
		y++;
	}
}

void	print_minisquare(t_big_struct *bs, int posx, int posy, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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

void	print_minimap(t_big_struct *bs)
{
	int	i;
	int	j;

	i = 0;
	while (bs->ms->map[i])
	{
		j = 0;
		while (bs->ms->map[i][j])
		{
			if (bs->ms->map[i][j] != '1' && bs->ms->map[i][j] != ' ')
				print_square(bs, bs->ws->minimap_pos.x, bs->ws->minimap_pos.y, 15327486);
			if (bs->ms->map[i][j] == '1')
				print_square(bs, bs->ws->minimap_pos.x, bs->ws->minimap_pos.y, 5405748);
			else if (bs->ms->map[i][j] == '2')
				print_square(bs, bs->ws->minimap_pos.x, bs->ws->minimap_pos.y, 10446148);
			else if (bs->ms->map[i][j] == '0')
				print_square(bs, bs->ws->minimap_pos.x, bs->ws->minimap_pos.y, 15327486);
			else if (bs->ms->map[i][j] == '3')
				print_square(bs, bs->ws->minimap_pos.x, bs->ws->minimap_pos.y, 15327486 /2 );
			j++;
			bs->ws->minimap_pos.x += bs->ws->mltp;
		}
		bs->ws->minimap_pos.x = 0;
		bs->ws->minimap_pos.y += bs->ws->mltp;
		i++;
	}
	bs->ws->minimap_pos.x = 0;
	bs->ws->minimap_pos.y = 0;
}
