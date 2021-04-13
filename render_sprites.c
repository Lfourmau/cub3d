/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:47:02 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/13 13:00:42 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_infos(big_struct *bs)
{
	bs->ss->sprite_height = bs->ps->vertic_res / bs->ss->raydist_sprite;
	bs->ss->begin_sprite = bs->ps->vertic_res / 2 - bs->ss->sprite_height / 2;
	bs->ss->end_sprite = bs->ps->vertic_res / 2 + bs->ss->sprite_height / 2;
	bs->ss->sprite_onscreen_size = bs->ss->end_sprite - bs->ss->begin_sprite;
}

void	put_sprite(big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int 	color;

	i = 0;
	sprite_infos(bs);
	texture_x = bs->ts->sp.width * (bs->ss->inter_y_sprite - (int)bs->ss->inter_y_sprite);
	if (bs->rs->side == 0)
		texture_x = bs->ts->sp.width * (bs->ss->inter_x_sprite - (int)bs->ss->inter_x_sprite);
	ratio = (float)bs->ts->sp.height / bs->ss->sprite_onscreen_size;
	while (i < bs->ss->sprite_onscreen_size && j < bs->ps->vertic_res)
	{
		color = bs->ts->sp.buff[texture_x + (int)((float)(i) * ratio) * bs->ts->sp.height];
		 if (color != 0)
			my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}