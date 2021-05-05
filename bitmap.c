/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:00:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/05 12:45:56 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_save(char *str)
{
	if (ft_strncmp(str, "--save", 7) != 0)
		return (1);
	return (0);
}

unsigned char	*header_info(t_big_struct *bs, int fd)
{
	int totalsize;

	totalsize = ((bs->ps.vertic_res * bs->ps.horiz_res) * bs->ws.bits_per_pixel) / 8;
	write(fd, "BM", 2);
	write(fd, &totalsize, 4);
	write(fd, "CR", 4);
	
	
   
}

unsigned char	*header_file(t_big_struct *bs, int fd)
{
	
}

void	bmp_image(t_big_struct *bs)
{
	int	fd;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0777);
	header_info(bs, fd);
	header_file(bs, fd);

}
