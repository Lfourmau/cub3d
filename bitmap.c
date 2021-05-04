/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:00:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 12:42:00 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_save(char *str)
{
	if (ft_strncmp(str, "--save", 6) != 0)
		return (1);
	return (0);
}

void	header_bitmap(t_big_struct *bs, int fd)
{
	write(fd, "BM", 2);
	write(fd, "tailletotale", 4);
	write(fd, "champsreserve", 4);
	write(fd, "decalage", 4);

}

int	bitmap(t_big_struct *bs)
{
	int	fd;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0777);
	if (fd < 0)
		return (1);
}
