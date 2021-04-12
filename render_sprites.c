/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:47:02 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/12 14:47:12 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite(big_struct *bs, int x, int j)
{
	int		texture_x;
	float	ratio;
	int		i;
	int 	color;
	
	i = 0;
	if (bs->rs->begin_wall < 0)
		i = 0 - bs->rs->begin_wall;
	texture_x = bs->ts->sp.width * (bs->ss->inter_y_sprite - (int)bs->ss->inter_y_sprite);
	if (bs->rs->side == 0)
		texture_x = bs->ts->sp.width * (bs->ss->inter_x_sprite - (int)bs->ss->inter_x_sprite);
	ratio = (float)bs->ts->sp.height / bs->rs->wall_onscreen_size;
	while (i < bs->rs->wall_onscreen_size && j < bs->ps->vertic_res)
	{
		color = bs->ts->sp.buff[texture_x + (int)((float)(i) * ratio) * bs->ts->sp.height];
		if (color != 0)
			my_mlx_pixel_put(bs, x, j, color);
		j++;
		i++;
	}
}