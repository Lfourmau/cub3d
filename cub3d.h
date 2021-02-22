/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:21:18 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/22 13:23:46 by lfourmau         ###   ########lyon.fr   */
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
}				parse_struct;

typedef struct map_struct
{
	char **map;
}			map_struct;

int    	full_parsing(char *map, parse_struct *ps, map_struct *ms);
int 	check_full_numbers(char **splitresult, int i);
void    parsing_struct_init(parse_struct *ps);
int 	number_of_split(char **splitresult);
int		check_identifiers_textures(char *line);
char   **ft_realloc(char **map, char *line);
void    parse_map(char *line, map_struct *ms, int j);
#endif
