/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/15 11:13:48 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int     main(void)
{
	int i = 0;
	int j = 0;
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 900, 900, "TEEEEEEST");
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0*65536+255*256+0, "Bonsoir bonjour bon apres midi");
	while (i < 60)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 160 + i, 160 + j, 255*65536+0*256+0);
		i++;
		j+=2;
	}
	i = 0;
	j = 0;
	while (i < 60)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 600 + i, 160 + j, 255*65536+0*256+0);
		i++;
		j+=2;
	}
	i = 0;
	j = 0;
	while (i < 400)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 170 + i, 170, 255*65536+0*256+0);
		i++;
	}
	i = 0;
	j = 0;
	while (i < 400)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 230 + i, 275, 255*65536+0*256+0);
		i++;
	}
    mlx_loop(mlx_ptr);
}
