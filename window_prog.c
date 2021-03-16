/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:00:44 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/16 09:27:37 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(big_struct *bs)
{
		mlx_destroy_window(bs->ws->mlx_ptr, bs->ws->win_ptr);
		exit(1);
		return (1);
}

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
	
	while (y <= 15)
	{
		x = 0;
		while (x <= 15)
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
			if (bs->ms->map[i][j] == '1')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 16711680);
			else if (bs->ms->map[i][j] == '2')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 11806720);
			else if (bs->ms->map[i][j] == '0')
				print_square(bs, bs->ws->minimap_pos_x, bs->ws->minimap_pos_y, 16777215);
			j++;
			bs->ws->minimap_pos_x += 15;
		}
		bs->ws->minimap_pos_x = 0;
		bs->ws->minimap_pos_y += 15;
		i++;
	}
	bs->ws->minimap_pos_x = 0;
	bs->ws->minimap_pos_y = 0;
}

int		render_next_frame(big_struct *bs)
{
	bs->ws->mlx_img = mlx_new_image(bs->ws->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res);
	bs->ws->img_ptr = mlx_get_data_addr(bs->ws->mlx_img, &bs->ws->bits_per_pixel, &bs->ws->line_length, &bs->ws->endian);
	print_minimap(bs);
	print_square(bs, bs->ws->player_pos_x, bs->ws->player_pos_y, 65280);
	mlx_put_image_to_window(bs->ws->mlx_ptr, bs->ws->win_ptr, bs->ws->mlx_img, 0, 0);
	mlx_destroy_image(bs->ws->mlx_ptr, bs->ws->mlx_img);
	return (0);
}

int	deal_key(int key, big_struct *bs)
{
	if (key == ESC)
		close_window(bs);
	if (key == WKEY)
	{
		render_next_frame(bs);
		bs->ws->player_pos_y = bs->ws->player_pos_y - 4;
	}
	if (key == SKEY)
	{
		render_next_frame(bs);
		bs->ws->player_pos_y = bs->ws->player_pos_y + 4;
	}
	if (key == AKEY)
	{
		render_next_frame(bs);
		bs->ws->player_pos_x = bs->ws->player_pos_x - 4;
	}
	if (key == DKEY)
	{
		render_next_frame(bs);
		bs->ws->player_pos_x = bs->ws->player_pos_x + 4;
	}
	return (0);
}


int window_prog(big_struct *bs)
{
	bs->ws->player_pos_x = bs->ms->spawn_x * 15;
	bs->ws->player_pos_y = bs->ms->spawn_y * 15;
	bs->ws->mlx_ptr = mlx_init();
	bs->ws->win_ptr = mlx_new_window(bs->ws->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res, "Cub3d");
	mlx_hook(bs->ws->win_ptr, 2, 1L<<0, deal_key, bs);
	mlx_loop(bs->ws->mlx_ptr);
	return (0);
}