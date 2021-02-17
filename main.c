/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/17 08:21:13 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
//geometrie
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

//coloriage

	i = 0;
	while (i <450)
	{
		j = 0;
		while (j < 900)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j,  i, 30975);
			j++;
		}
		i++;
	}
	i = 0;
	while (i <450)
	{
		j = 0;
		while (j < 900)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j,  450 + i, 5266000);
			j++;
		}
		i++;
	}
	i = 0;
	while (i <100)
	{
		j = 800;
		while (j < 900)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j,  i, 13158450);
			j++;
		}
		i++;
	}
	i = 95;
	while (i < 200)
	{
		j = 400;
		while (j < 700)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j,  i, 16777215);
			j++;
		}
		i++;
	}
	i = 95;
	while (i < 250)
	{
		j = 75;
		while (j < 250)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j,  i, 16777215);
			j++;
		}
		i++;
	}

    mlx_loop(mlx_ptr);
    mlx_loop(mlx_ptr);
}
