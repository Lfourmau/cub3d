/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:24:29 by loic              #+#    #+#             */
/*   Updated: 2021/05/01 09:44:00 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float   dist(float xa, float xb, float ya, float yb)
{
    float   res;
    res = sqrtf(powf(xa - xb, 2) + powf(ya - yb, 2));
    return (res);
}

void	clear_spritestruct(big_struct *bs)
{
	bs->ss->sprite_onscreen_size = 0;
	bs->ss->raydist_sprite = 0;
	bs->ss->secondpoint.x = 0;
	bs->ss->secondpoint.y = 0;
	bs->ss->mapx_sprite = 0;
	bs->ss->mapy_sprite = 0;
	bs->ss->center_sprite.x = 0;
	bs->ss->center_sprite.y = 0;
	bs->ss->begin_sprite = 0;
	bs->ss->inter_sprite.x = 0;
	bs->ss->inter_sprite.y = 0;
}