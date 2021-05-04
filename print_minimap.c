/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:06:35 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 11:17:32 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_full_minimap(t_big_struct *bs)
{
	print_minimap(bs);
	print_minisquare(bs, bs->ws.player_pos.x * bs->ws.mltp, \
	bs->ws.player_pos.y * bs->ws.mltp, 65280);
	print_minisquare(bs, (bs->ws.player_pos.x + cos(bs->ws.p_angle)) * bs->ws.mltp, (bs->ws.player_pos.y - sin(bs->ws.p_angle)) * bs->ws.mltp, 16720777);
}