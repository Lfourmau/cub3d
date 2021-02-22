/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:03:36 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/22 14:54:03 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(char *line, map_struct *ms, int j)
{
	if (j == 0)
	{
		ms->map = ft_calloc(2, sizeof(char *));
		ms->map[j] = malloc(ft_strlen(line));
		ms->map[0] = line;
	}
	else
	{
		ms->map = ft_realloc(ms->map, line);
//		ms->map[j] = malloc(ft_strlen(line));
//		ms->map[j] = line;
	}
}
