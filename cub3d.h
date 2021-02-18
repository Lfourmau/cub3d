/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:21:18 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/18 14:54:05 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct parsing_struct
{
	int 	horiz_res;
	int 	vertic_res;	
	int		color_f;
	int		color_c;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
}			parse_struct;

void    full_parsing(char *map, parse_struct *ps);
#endif
