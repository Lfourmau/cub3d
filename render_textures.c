/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:41:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/08 15:20:06 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	xpm_init(big_struct *bs)
{
	bs->ts->n.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->NO, &bs->ts->n.width, &bs->ts->n.height);
	// bs->ts->s.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->SO, &bs->ts->s.width, &bs->ts->s.height);
	// bs->ts->e.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->EA, &bs->ts->e.width, &bs->ts->e.height);
	// bs->ts->w.img = mlx_xpm_file_to_image(bs->ws->mlx_ptr, bs->ps->WE, &bs->ts->w.width, &bs->ts->w.height);

	bs->ts->n.buff = mlx_get_data_addr(bs->ts->n.img, &bs->ts->n.bits_per_pixel, &bs->ts->n.line_length, &bs->ts->n.endian);
	// bs->ts->s.buff = mlx_get_data_addr(bs->ts->s.img, &bs->ts->s.bits_per_pixel, &bs->ts->s.line_length, &bs->ts->s.endian);
	// bs->ts->e.buff = mlx_get_data_addr(bs->ts->e.img, &bs->ts->e.bits_per_pixel, &bs->ts->e.line_length, &bs->ts->e.endian);
	// bs->ts->w.buff = mlx_get_data_addr(bs->ts->w.img, &bs->ts->w.bits_per_pixel, &bs->ts->w.line_length, &bs->ts->w.endian);
}




void	put_wall_texture(big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int 	color;

	i = 0;
	texture_x = bs->ts->n.width * (bs->rs->inter_y - (int)bs->rs->inter_y);
	if (bs->rs->side == 0)
		texture_x = bs->ts->n.width * (bs->rs->inter_x - (int)bs->rs->inter_x);
	ratio = (float)bs->ts->n.height / bs->rs->wall_onscreen_size;
	while (i < bs->rs->wall_onscreen_size)
	{
		color = bs->ts->n.buff[texture_x + (int)((float)(i) * ratio) * 64];
		my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}
























// void	get_colors(big_struct *bs, int x, int j)
// {
// 	int y;
// 	int xtext;
// 	int posx;
// 	float y_ratio;

// 	y = 0;
// 	y_ratio = (bs->ps->vertic_res / bs->rs->rayshort) / bs->ts->n.height;
// 	while (y < bs->ts->n.height * y_ratio && j + y < bs->ps->vertic_res)
// 	{
// 		posx = 0;
// 		xtext = 0;
// 		while (posx <  bs->ts->n.width)
// 		{
// 			bs->ts->n.t = bs->ts->n.buff[(int)((bs->ts->n.line_length) + xtext + 3)];
// 			bs->ts->n.r = bs->ts->n.buff[(int)((y_ratio * bs->ts->n.line_length) + xtext + 2)];
// 			bs->ts->n.g = bs->ts->n.buff[(int)((y_ratio * bs->ts->n.line_length) + xtext + 1)];
// 			bs->ts->n.b = bs->ts->n.buff[(int)((y_ratio * bs->ts->n.line_length) + xtext)];
			
// 			bs->ts->colorpixel = trgb(bs->ts->n.t, bs->ts->n.r, bs->ts->n.g, bs->ts->n.b);
// 			my_mlx_pixel_put(bs, x, j + y, bs->ts->colorpixel);
// 			posx++;
// 			xtext += 4;
// 		}
// 		y++;
// 	}
// }