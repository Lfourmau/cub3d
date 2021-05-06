/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:33:54 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/06 14:23:55 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_splits(char **chain, int i)
{
	while (--i >= 0)
		free(chain[i]);
	free(chain);
}

void	free_textures(t_big_struct *bs)
{
	free(bs->ps.WE);
	free(bs->ps.EA);
	free(bs->ps.NO);
	free(bs->ps.SO);
	free(bs->ps.S);
}

int	free_line(t_big_struct *bs)
{
	free(bs->ps.line);
	return (1);
}

void	free_comma_space_splits(char **comma, char **space)
{
	free_splits(comma, number_of_split(comma));
	free_splits(space, number_of_split(space));
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
