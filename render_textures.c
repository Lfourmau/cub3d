/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:41:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/06 14:50:16 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_init(big_struct *bs)
{
	bs->ts->n.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->NO, &bs->ts->n.width, &bs->ts->n.height);
	bs->ts->s.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->SO, &bs->ts->s.width, &bs->ts->s.height);
	bs->ts->e.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->EA, &bs->ts->e.width, &bs->ts->e.height);
	bs->ts->w.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->WE, &bs->ts->w.width, &bs->ts->w.height);

	bs->ts->n.buff = mlx_get_data_addr(bs->ts->n.img, &bs->ts->n.bits_per_pixel, &bs->ts->n.line_length, &bs->ts->n.endian);
	bs->ts->s.buff = mlx_get_data_addr(bs->ts->s.img, &bs->ts->s.bits_per_pixel, &bs->ts->s.line_length, &bs->ts->s.endian);
	bs->ts->e.buff = mlx_get_data_addr(bs->ts->e.img, &bs->ts->e.bits_per_pixel, &bs->ts->e.line_length, &bs->ts->e.endian);
	bs->ts->w.buff = mlx_get_data_addr(bs->ts->w.img, &bs->ts->w.bits_per_pixel, &bs->ts->w.line_length, &bs->ts->w.endian);
	
	bs->ts->horiz_ratio = 1/64;
}

void	get_colors(big_struct *bs)
{
	bs->ts->n.r = bs->ts->n.buff[(int)(((bs->rs->mapy * bs->ts->horiz_ratio) * bs->ts->n.line_length) + (((bs->rs->mapx * bs->ts->horiz_ratio) * bs->ts->n.bits_per_pixel)))];
	bs->ts->n.g = bs->ts->n.buff[(int)(((bs->rs->mapy * bs->ts->horiz_ratio) * bs->ts->n.line_length) + (((bs->rs->mapx * bs->ts->horiz_ratio) * bs->ts->n.bits_per_pixel))) * 4 + 1];
	bs->ts->n.b = bs->ts->n.buff[(int)(((bs->rs->mapy * bs->ts->horiz_ratio) * bs->ts->n.line_length) + (((bs->rs->mapx * bs->ts->horiz_ratio) * bs->ts->n.bits_per_pixel))) * 8 + 2];
	bs->ts->colorpixel = 65536 * bs->ts->n.r + 256 * bs->ts->n.g + bs->ts->n.b;
}

// void	render_textures(big_struct *bs)
// {
	
// }