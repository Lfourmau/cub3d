/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:00:44 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/11 10:37:44 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int deal_key(int key)
{
	printf("%d\n", key);
	return (0);
}

int window_prog(parse_struct *ps, map_struct *ms)
{
	void *mlx_ptr;
	void *win_ptr;

	if (!(mlx_ptr = mlx_init()))
		return (1);
	if (!(win_ptr = mlx_new_window (mlx_ptr, 600, 600, "Cub3d" )))
		return (1);
	mlx_key_hook(win_ptr, deal_key, ms);
	mlx_loop(mlx_ptr);
	return (0);
}