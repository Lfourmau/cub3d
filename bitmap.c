/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:00:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/06 09:10:19 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_save(char *str)
{
	if (ft_strncmp(str, "--save", 7) != 0)
		return (1);
	return (0);
}

unsigned char	*header_info(t_big_struct *bs)
{
	unsigned char	*header_info;

	header_info = ft_calloc(40, sizeof(unsigned char));
	header_info[0] = (unsigned char)(40);
	header_info[4] = (unsigned char)(bs->ps.horiz_res);
	header_info[5] = (unsigned char)(bs->ps.horiz_res >> 8);
	header_info[6] = (unsigned char)(bs->ps.horiz_res >> 16);
	header_info[7] = (unsigned char)(bs->ps.horiz_res >> 24);
	header_info[8] = (unsigned char)(bs->ps.vertic_res);
	header_info[9] = (unsigned char)(bs->ps.vertic_res >> 8);
	header_info[10] = (unsigned char)(bs->ps.vertic_res >> 16);
	header_info[11] = (unsigned char)(bs->ps.vertic_res >> 24);
	header_info[12] = (unsigned char)(1);
	header_info[14] = (unsigned char)(3 * 8);
	return (header_info);
}

unsigned char	*header_file(t_big_struct *bs, int stride)
{
	int						filesize;
	static unsigned char	*header_file;

	filesize = 14 + 40 + (stride * bs->ps.vertic_res);
	header_file = ft_calloc(14, sizeof(unsigned char));
	header_file[0] = (unsigned char)('B');
	header_file[1] = (unsigned char)('M');
	header_file[2] = (unsigned char)(filesize);
	header_file[3] = (unsigned char)(filesize >> 8);
	header_file[4] = (unsigned char)(filesize >> 16);
	header_file[5] = (unsigned char)(filesize >> 24);
	header_file[10] = (unsigned char)(14 + 40);
	return (header_file);
}

void	bmp_image(t_big_struct *bs)
{
	int				widthinbytes;
	unsigned char	*padding;
	int				paddingsize;
	int				stride;
	FILE			*imagefile;
	unsigned char	*headerfile;
	unsigned char	*headerinfo;
	int i;

	widthinbytes = bs->ps.horiz_res * bs->ws.bits_per_pixel;
	padding = ft_calloc(3, sizeof(unsigned char));
	paddingsize = (4 - (widthinbytes) % 4) % 4;
	stride = widthinbytes + paddingsize;
	imagefile = fopen("screen.bmp", "wb");
	headerfile = header_file(bs, stride);
	fwrite(headerfile, 1, 14, imagefile);
	headerinfo = header_info(bs);
	fwrite(headerinfo, 1, 40, imagefile);
	i = -1;
	while (++i < bs->ps.horiz_res)
	{
		fwrite(bs->ws.mlx_img + (i * widthinbytes), bs->ws.bits_per_pixel, bs->ps.horiz_res, imagefile);
		fwrite(padding, 1, paddingsize, imagefile);
	}
	fclose(imagefile);
}
