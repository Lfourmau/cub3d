/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:47:54 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/23 11:18:02 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_grid(big_struct *bs)
{
	int i;

	i = 0;
	bs->tg->horiz = ft_calloc(number_of_split(bs->ms->map) + 1, sizeof(t_line));
	bs->tg->vertic = ft_calloc(max_len_map(bs->ms->map) + 1, sizeof(t_line));
	while (i < number_of_split(bs->ms->map))
	{
		bs->tg->horiz[i].a.x = 0;
		bs->tg->horiz[i].b.x = 1;
		bs->tg->horiz[i].a.y = i;
		bs->tg->horiz[i].b.y = i;
		i++;
	}
	i = 0;
	while (i < max_len_map(bs->ms->map))
	{
		bs->tg->vertic[i].a.x = i;
		bs->tg->vertic[i].b.x = i;
		bs->tg->vertic[i].a.y = 0;
		bs->tg->vertic[i].b.y = 1;
		i++;
	}
}

void	find_horiz_inter(big_struct *bs, int i)
{
	float	dir_x;
	float	dir_y;
	float 	up;
	float 	down;

	dir_x = bs->ws->player_pos_x + cos(bs->ws->p_angle);
	dir_y = bs->ws->player_pos_y - sin(bs->ws->p_angle);
	up = (dir_x * bs->ws->player_pos_y - bs->ws->player_pos_x * dir_y) * (bs->tg->horiz[i].b.x - bs->tg->horiz[i].a.x) - (bs->tg->horiz[i].b.x * bs->tg->horiz[i].a.y - bs->tg->horiz[i].a.x * bs->tg->horiz[i].b.y) * (dir_x - bs->ws->player_pos_x);
	down = (dir_x - bs->ws->player_pos_x) * (bs->tg->horiz[i].b.y - bs->tg->horiz[i].a.y) - (bs->tg->horiz[i].b.x - bs->tg->horiz[i].a.x) * (dir_y - bs->ws->player_pos_y);
	bs->ws->hinter_x = up / down;
	up = (dir_x * bs->ws->player_pos_y - bs->ws->player_pos_x * dir_y) * (bs->tg->horiz[i].b.y - bs->tg->horiz[i].a.y) - (bs->tg->horiz[i].b.x * bs->tg->horiz[i].a.y - bs->tg->horiz[i].a.x * bs->tg->horiz[i].b.y) * (dir_y - bs->ws->player_pos_y);
	bs->ws->hinter_y = up / down;
}

void	check_wall_h(big_struct *bs)
{
	int i;

	i = bs->ws->player_pos_y;
	if (bs->ws->p_angle > 0 && bs->ws->p_angle < M_PI)
	{
		while (i)
		{
		 	find_horiz_inter(bs, i);
		 	if (bs->ms->map[bs->ws->hinter_y - 1][bs->ws->hinter_x] && bs->ms->map[bs->ws->hinter_y][bs->ws->hinter_x] == '1')
		 	{
		 		print_direction(bs, bs->ws->hinter_x * bs->ws->multiplicator, bs->ws->hinter_y * bs->ws->multiplicator, 65280);
				break;
		 	}
			i--;
		}
	}
	else if(bs->ws->p_angle > M_PI && bs->ws->p_angle < 2 * M_PI)
	{
		while (i < number_of_split(bs->ms->map))
		{
		 	find_horiz_inter(bs, i);
		 	if (bs->ms->map[bs->ws->hinter_y + 1][bs->ws->hinter_x] && bs->ms->map[bs->ws->hinter_y][bs->ws->hinter_x] == '1')
		 	{
		 		print_direction(bs, bs->ws->hinter_x * bs->ws->multiplicator, bs->ws->hinter_y * bs->ws->multiplicator, 65280);
				break;
		 	}
			i++;
		}
	}
}

void	find_vertic_inter(big_struct *bs)
{
	float	dir_x;
	float	dir_y;
	float 	up;
	float 	down;
	float 	x;
	float 	y;

	dir_x = bs->ws->player_pos_x + cos(bs->ws->p_angle);
	dir_y = bs->ws->player_pos_y - sin(bs->ws->p_angle);
	up = (dir_x * bs->ws->player_pos_y - bs->ws->player_pos_x * dir_y) * (bs->tg->vertic[i].b.x - bs->tg->vertic[i].a.x) - (bs->tg->horiz->b.x * bs->tg->vertic[i].a.y - bs->tg->vertic[i].a.x * bs->tg->vertic[i].b.y) * (dir_x - bs->ws->player_pos_x);
	down = (dir_x - bs->ws->player_pos_x) * (bs->tg->vertic[i].b.y - bs->tg->vertic[i].a.y) - (bs->tg->vertic[i].b.x - bs->tg->vertic[i].a.x) * (dir_y - bs->ws->player_pos_y);
	x = up / down;
	up = (dir_x * bs->ws->player_pos_y - bs->ws->player_pos_x * dir_y) * (bs->tg->vertic[i].b.y - bs->tg->vertic[i].a.y) - (bs->tg->horiz->b.x * bs->tg->vertic[i].a.y - bs->tg->vertic[i].a.x * bs->tg->vertic[i].b.y) * (dir_y - bs->ws->player_pos_y);
	y = up / down;
}