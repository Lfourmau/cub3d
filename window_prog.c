/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:00:44 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/15 11:41:17 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(big_struct *bs)
{
		mlx_destroy_window(bs->ms->mlx_ptr, bs->ms->win_ptr);
		exit(1);
		return (1);
}

void            my_mlx_pixel_put(big_struct *bs, int x, int y, int color)
{
    char    *dst;

    dst = bs->ms->img_adress + (y * bs->ms->line_length + x * (bs->ms->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void		print_square(big_struct *bs)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 15)
	{
		while (x < 15)
		{
			my_mlx_pixel_put(bs, bs->ms->x + x, bs->ms->y + y, bs->ps->color_c);
			x++;
		}
		y++;
		x = 0;
	}
}

int	render_next_frame(big_struct *bs)
{
	bs->ms->mlx_img = mlx_new_image(bs->ms->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res);
	bs->ms->img_adress = mlx_get_data_addr(bs->ms->mlx_img, &bs->ms->bits_per_pixel, &bs->ms->line_length, &bs->ms->endian);
	print_square(bs);
	mlx_put_image_to_window(bs->ms->mlx_ptr, bs->ms->win_ptr, bs->ms->mlx_img, 0, 0);
	mlx_destroy_image(bs->ms->mlx_ptr, bs->ms->mlx_img);
	return (0);
}

int deal_key(int key, big_struct *bs)
{
	if (key == ESC)
		close_window(bs);
	if (key == LEFTLOOK)
		return (printf("regarde a gauche\n"));
	if (key == RIGHTLOOK)
		return (printf("regarde a droite\n"));
	if (key == WKEY)
	{
		while (1)
		{
			if (key == 03)
				break;
			render_next_frame(bs);
			bs->ms->y--;
		}
		// return (printf("avance\n"));
	}
	if (key == SKEY)
	{
		while (1)
		{
			if (key == 03)
				break;
			render_next_frame(bs);
			bs->ms->y++;
		}
		// return (printf("recule\n"));
	}
	if (key == AKEY)
	{
		render_next_frame(bs);
		bs->ms->x--;
		//return (printf("gauche\n"));
	}
	if (key == DKEY)
	{
		render_next_frame(bs);
		bs->ms->x++;
		// return (printf("droite\n"));
	}
	return (0);
}

int window_prog(big_struct *bs)
{
	if (!(bs->ms->mlx_ptr = mlx_init()))
		return (1);
	if (!(bs->ms->win_ptr = mlx_new_window (bs->ms->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res, "Cub3d" )))
		return (1);
	mlx_key_hook(bs->ms->win_ptr, deal_key, bs);
	//mlx_hook(bs->ms->win_ptr, 17, 0, close_window, bs);
	mlx_loop_hook(bs->ms->mlx_ptr, render_next_frame, bs);
	mlx_loop(bs->ms->mlx_ptr);
	return (0);
}