/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:24:29 by loic              #+#    #+#             */
/*   Updated: 2021/05/09 17:14:18 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		put_sprite(bs, i, spritestab[bs->ss.spritenum].\
		begin_sprite, spritestab[bs->ss.spritenum]);
		bs->ss.spritenum--;
	}
}
