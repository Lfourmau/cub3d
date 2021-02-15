/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/15 15:24:08 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
void	ft_line(void *mlx_ptr, void* win_ptr, int axe, int a, int b, int color)
{
	while (a < b)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, axe, a, color);
		a++;
	}
}
int     main(void)
{
	int i = 0;
	int j = 0;
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 900, 900, "TEEEEEEST");
	mlx_string_put(mlx_ptr, win_ptr, 305, 440, 255, "Bonsoir bonjour bon apres midi");
	while (i < 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0*65536+255*256+0);
		i++;
	}
	i = 0;
	while (i < 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 900-i, i, 0*65536+255*256+0);
		i++;
	}
	i = 0;
	while (i < 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 450, i, 0*65536+255*256+0);
		i++;
	}
	i = 0;
	while (i < 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 450, 0*65536+255*256+0);
		i++;
	}
	i = 0;
	while (i <450)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 450 - i, i, 16711680);
		i++;
	}
	i = 0;
	while (i <450)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 450 + i,  i, 16711680);
		i++;
	}
	i = 0;
	while (i <450)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i,  450 + i, 16711680);
		i++;
	}
	i = 0;
	while (i <450)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 900 - i,  450 + i, 16711680);
		i++;
	}
    mlx_loop(mlx_ptr);
    mlx_loop(mlx_ptr);
}
