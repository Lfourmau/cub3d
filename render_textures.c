/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:41:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/05 14:58:18 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_init(big_struct *bs)
{
	bs->ts->n_text = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->NO, &bs->ts->n_width, &bs->ts->n_height);
	bs->ts->s_text = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->SO, &bs->ts->s_width, &bs->ts->s_height);
	bs->ts->e_text = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->EA, &bs->ts->e_width, &bs->ts->e_height);
	bs->ts->w_text = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->WE, &bs->ts->w_width, &bs->ts->w_height);
	bs->ts->n_addr = mlx_get_data_addr(bs->ts->n_text, &bs->ts->n_bits_per_pixel, &bs->ts->n_line_length, &bs->ts->n_endian);
	bs->ts->s_addr = mlx_get_data_addr(bs->ts->s_text, &bs->ts->s_bits_per_pixel, &bs->ts->s_line_length, &bs->ts->s_endian);
	bs->ts->e_addr = mlx_get_data_addr(bs->ts->e_text, &bs->ts->e_bits_per_pixel, &bs->ts->e_line_length, &bs->ts->e_endian);
	bs->ts->w_addr = mlx_get_data_addr(bs->ts->w_text, &bs->ts->w_bits_per_pixel, &bs->ts->w_line_length, &bs->ts->w_endian);
	bs->ts->ratio = (bs->ps->vertic_res / bs->rs->rayshort) / 64;
	bs->ts->n_line_length *= bs->ts->ratio;
	mlx_put_image_to_window(bs->ws->mlx_ptr, bs->ws->win_ptr, bs->ts->n_text, bs->ps->vertic_res / 2, bs->ps->horiz_res / 2);
}