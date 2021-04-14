/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:00:44 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/14 13:55:46 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(big_struct *bs)
{
		mlx_destroy_window(bs->ws->mlx_ptr, bs->ws->win_ptr);
		exit(1);
		return (1);
}

 static int	key_press(int key, big_struct *bs)
{
	if (key == ESC)
		close_window(bs);
	else if (key == LEFTLOOK)
		bs->ks->left = 1;
	else if (key == RIGHTLOOK)
		bs->ks->right = 1;
	else if (key == WKEY)
		bs->ks->w = 1;
	else if (key == SKEY)
		bs->ks->s = 1;
	else if (key == AKEY)
		bs->ks->a = 1;
	else if (key == DKEY)
		bs->ks->d = 1;
	bs->ws->key_press = 1;
	return (0);
}

static int	key_release(int key, big_struct *bs)
{
	if (key == LEFTLOOK)
		bs->ks->left = 0;
	else if (key == RIGHTLOOK)
		bs->ks->right = 0;
	else if (key == WKEY)
		bs->ks->w = 0;
	else if (key == SKEY)
		bs->ks->s = 0;
	else if (key == AKEY)
		bs->ks->a = 0;
	else if (key == DKEY)
		bs->ks->d = 0;
	return (0);
}

int		render_next_frame(big_struct *bs)
{
	if (bs->ws->key_press == 1)
	{

	updatecoord(bs);
	bs->ws->key_press = 0;
	bs->ws->mlx_img = mlx_new_image(bs->ws->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res);
	bs->ws->img_ptr = mlx_get_data_addr(bs->ws->mlx_img, &bs->ws->bits_per_pixel, &bs->ws->line_length, &bs->ws->endian);
	raycasting_loop(bs);
	print_minimap(bs);
	mlx_put_image_to_window(bs->ws->mlx_ptr, bs->ws->win_ptr, bs->ws->mlx_img, 0, 0);
	mlx_destroy_image(bs->ws->mlx_ptr, bs->ws->mlx_img);
	}
	return (0);
}

int window_prog(big_struct *bs)
{
	multiplicator(bs);
	detect_spawn_dir(bs);
	bs->ws->player_pos_x = bs->ms->spawn_x;
	bs->ws->player_pos_y = bs->ms->spawn_y;
	bs->ws->mlx_ptr = mlx_init();
	bs->ws->win_ptr = mlx_new_window(bs->ws->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res, "Cub3d");
	mlx_hook(bs->ws->win_ptr, 2, 1L<<0, key_press, bs);
	mlx_hook(bs->ws->win_ptr, 3, 1L<<1, key_release, bs);
	mlx_loop_hook(bs->ws->mlx_ptr, render_next_frame, bs);
	mlx_loop(bs->ws->mlx_ptr);
	return (0);
}