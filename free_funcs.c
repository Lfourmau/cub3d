/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:33:54 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/04 17:55:46 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_splits(char **chain, int i)
{
	while (--i >= 0)
		free(chain[i]);
	free(chain);
}

int		free_struct(parse_struct *ps, map_struct *ms)
{
	printf("Error\nIl manque une information");
	free_splits(ms->map, number_of_split(ms->map));
	free(ps->SO);
	free(ps->NO);
	free(ps->EA);
	free(ps->S);
	free(ps->WE);
	return (1);
}
