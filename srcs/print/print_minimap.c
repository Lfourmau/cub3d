/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:06:35 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:14:15 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_good_square(t_big_struct *bs, int i, int j)
{
	if (bs->ms.map[i][j] != '1' && bs->ms.map[i][j] != ' ')
		print_square(bs, bs->ws.minimap_pos.x, bs->ws.minimap_pos.y, 15327486);
	if (bs->ms.map[i][j] == '1')
		print_square(bs, bs->ws.minimap_pos.x, bs->ws.minimap_pos.y, 5405748);
	else if (bs->ms.map[i][j] == '2')
		print_square(bs, bs->ws.minimap_pos.x, bs->ws.minimap_pos.y, 10446148);
	else if (bs->ms.map[i][j] == '0')
		print_square(bs, bs->ws.minimap_pos.x, bs->ws.minimap_pos.y, 15327486);
	else if (bs->ms.map[i][j] == '3')
		print_square(bs, bs->ws.minimap_pos.x, bs->ws.minimap_pos.y, \
		15327486 /2 );
}

void	print_full_minimap(t_big_struct *bs)
{
	print_minimap(bs);
	print_minisquare(bs, bs->ws.player_pos.x * bs->ws.mltp, \
	bs->ws.player_pos.y * bs->ws.mltp, 65280);
	print_minisquare(bs, (bs->ws.player_pos.x + cos(bs->ws.p_angle)) \
	* bs->ws.mltp, (bs->ws.player_pos.y - sin(bs->ws.p_angle)) * \
	bs->ws.mltp, 16720777);
}
