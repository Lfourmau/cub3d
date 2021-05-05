/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:24:29 by loic              #+#    #+#             */
/*   Updated: 2021/05/05 09:14:45 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dist(float xa, float xb, float ya, float yb)
{
	float	res;

	res = sqrtf(powf(xa - xb, 2) + powf(ya - yb, 2));
	return (res);
}

void	put_all_sprites(t_big_struct *bs, int i, t_sprites_struct *spritestab)
{
	while (bs->ss.spritenum > 0)
	{
		put_sprite(bs, i, spritestab[bs->ss.spritenum].begin_sprite, spritestab[bs->ss.spritenum]);
		bs->ss.spritenum--;
	}
}
