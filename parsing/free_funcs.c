/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:33:54 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 11:14:01 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_splits(char **chain, int i)
{
	while (--i >= 0)
		free(chain[i]);
	free(chain);
}

int	free_struct(t_big_struct *bs, char *line)
{
	printf("Error\nIl manque une information");
	free_splits(bs->ms.map, number_of_split(bs->ms.map));
	free(bs->ps.SO);
	free(bs->ps.NO);
	free(bs->ps.EA);
	free(bs->ps.S);
	free(bs->ps.WE);
	free(line);
	return (1);
}
