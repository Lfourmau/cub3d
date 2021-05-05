/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:00:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/05 08:36:14 by lfourmau         ###   ########lyon.fr   */
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
    
}

unsigned char	*header_file(t_big_struct *bs, int stride)
{
	
}

void	bmp_image(t_big_struct *bs)
{
	
}
