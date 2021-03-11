/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:00:44 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/11 13:18:13 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(big_struct *bs)
{
		mlx_destroy_window(bs->ms->mlx_ptr, bs->ms->win_ptr);
		exit(1);
		return (1);
}

int deal_key(int key, big_struct *bs)
{
	if (key == ESC)
		close_window(bs);
	if (key == LEFTLOOK)
		return (printf("je regarde a gauche\n"));
	if (key == RIGHTLOOK)
		return (printf("je regarde a droite\n"));
	if (key == WKEY)
		return (printf("J'avance\n"));
	if (key == SKEY)
		return (printf("je recule\n"));
	if (key == AKEY)
		return (printf("Je me deplace a gauche\n"));
	if (key == DKEY)
		return (printf("Je me deplace a droite\n"));
	return (0);
}

int window_prog(big_struct *bs)
{
	if (!(bs->ms->mlx_ptr = mlx_init()))
		return (1);
	if (!(bs->ms->win_ptr = mlx_new_window (bs->ms->mlx_ptr, bs->ps->horiz_res, bs->ps->vertic_res, "Cub3d" )))
		return (1);
	mlx_key_hook(bs->ms->win_ptr, deal_key, bs);
	mlx_hook(bs->ms->win_ptr, 17, 0, close_window, bs);
	mlx_loop(bs->ms->mlx_ptr);
	return (0);
}