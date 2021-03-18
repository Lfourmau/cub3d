/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:00:44 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/18 13:55:41 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(big_struct *bs)
{
		mlx_destroy_window(bs->ws->mlx_ptr, bs->ws->win_ptr);
		exit(1);
		return (1);
}

int		render_next_frame(big_struct *bs)
{
	bs->ws->mlx_img = mlx_new_image(bs->ws->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res);
	bs->ws->img_ptr = mlx_get_data_addr(bs->ws->mlx_img, &bs->ws->bits_per_pixel, &bs->ws->line_length, &bs->ws->endian);
	print_minimap(bs);
	print_square(bs, bs->ws->player_pos_x, bs->ws->player_pos_y, 65280);
	print_square(bs, bs->ws->player_pos_x + cos(bs->ws->p_angle) * bs->ws->multiplicator, bs->ws->player_pos_y + sin(bs->ws->p_angle) * bs->ws->multiplicator, 2971080);
	mlx_put_image_to_window(bs->ws->mlx_ptr, bs->ws->win_ptr, bs->ws->mlx_img, 0, 0);
	mlx_destroy_image(bs->ws->mlx_ptr, bs->ws->mlx_img);
	return (0);
}

int	rotation(int key, big_struct *bs)
{
	if (key == LEFTLOOK)
		bs->ws->p_angle -= M_PI / 8;
	if (key == RIGHTLOOK)
		bs->ws->p_angle += M_PI / 8;
	return (0);
}

int	deal_key(int key, big_struct *bs)
{
	if (key == ESC)
		close_window(bs);
	if (key == LEFTLOOK)
		bs->ws->p_angle -= M_PI / 8;
	if (key == RIGHTLOOK)
		bs->ws->p_angle += M_PI / 8;
	if (key == WKEY)
	{
		// if (bs->ms->map[bs->ws->player_pos_y / bs->ws->multiplicator - 1][bs->ws->player_pos_x / bs->ws->multiplicator ] != '1')
		// {
			bs->ws->player_pos_y += sin(bs->ws->p_angle) * bs->ws->multiplicator;
			bs->ws->player_pos_x += cos(bs->ws->p_angle) * bs->ws->multiplicator;
		// }
		render_next_frame(bs);
	}
	if (key == SKEY)
	{
		// if (bs->ms->map[bs->ws->player_pos_y / bs->ws->multiplicator + 1][bs->ws->player_pos_x / bs->ws->multiplicator] != '1')
		// {
			bs->ws->player_pos_y -= sin(bs->ws->p_angle) * bs->ws->multiplicator;
			bs->ws->player_pos_x -= cos(bs->ws->p_angle) * bs->ws->multiplicator;
		// }
		render_next_frame(bs);
	}
	if (key == AKEY)
	{
		// if (bs->ms->map[bs->ws->player_pos_y / bs->ws->multiplicator][bs->ws->player_pos_x / bs->ws->multiplicator - 1] != '1')
		// {
			bs->ws->player_pos_y -= sin(bs->ws->p_angle + (M_PI / 2)) * bs->ws->multiplicator;
			bs->ws->player_pos_x -= cos(bs->ws->p_angle + (M_PI / 2)) * bs->ws->multiplicator;
		// }
		render_next_frame(bs);
	}
	if (key == DKEY)
	{
		// if (bs->ms->map[bs->ws->player_pos_y / bs->ws->multiplicator][bs->ws->player_pos_x / bs->ws->multiplicator + 1] != '1')
		// {
			bs->ws->player_pos_y += sin(bs->ws->p_angle + (M_PI / 2)) * bs->ws->multiplicator;
			bs->ws->player_pos_x += cos(bs->ws->p_angle + (M_PI / 2)) * bs->ws->multiplicator;
		// }
		render_next_frame(bs);
	}
	return (0);
}


int window_prog(big_struct *bs)
{
	multiplicator(bs);
	detect_spawn_dir(bs);
	bs->ws->player_pos_x = bs->ms->spawn_x * bs->ws->multiplicator;
	bs->ws->player_pos_y = bs->ms->spawn_y * bs->ws->multiplicator;
	bs->ws->mlx_ptr = mlx_init();
	bs->ws->win_ptr = mlx_new_window(bs->ws->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res, "Cub3d");
	mlx_hook(bs->ws->win_ptr, 2, 1L<<0, deal_key, bs);
	mlx_loop_hook(bs->ws->mlx_ptr, render_next_frame, bs);
	mlx_loop(bs->ws->mlx_ptr);
	return (0);
}