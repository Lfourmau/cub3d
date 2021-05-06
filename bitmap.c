/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:00:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/06 11:01:56 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_save(char *str)
{
	if (ft_strncmp(str, "--save", 7) != 0)
		return (1);
	return (0);
}

static void	ft_bmp_header(t_big_struct *bs, int fd, int tmp)
{
	write(fd, "BM", 2);
	tmp = 54 + 24 * bs->ps.horiz_res * bs->ps.vertic_res;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	tmp = bs->ps.horiz_res;
	write(fd, &tmp, 4);
	tmp = bs->ps.vertic_res;
	write(fd, &tmp, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &bs->ws.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int	bmp_image(t_big_struct *bs)
{
	int	fd;
	int	x;
	int	y;

	fd = open("img.bmp", O_CREAT | O_RDWR, 0777);
	render_next_frame(bs);
	if (fd == -1)
	{
		printf("Error\nCan't create save file\n");
		exit(EXIT_SUCCESS);
	}
	ft_bmp_header(bs, fd, 0);
	y = bs->ps.vertic_res - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < bs->ps.horiz_res)
		{
			write(fd, &bs->ws.img_ptr[bs->ws.line_length * y + x * 4], 4);
			 x++;
		}
		y--;
	}
	close(fd);
	return (0);
}