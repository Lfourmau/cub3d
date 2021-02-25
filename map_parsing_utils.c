/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:46:01 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/25 07:29:56 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*addspaces(char *str)
{
	int i;
	char *tmp;

	i = 0;
	tmp = malloc(ft_strlen(str) + 2);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = ' ';
	tmp[i + 1] = 0;
	free (str);
	return (tmp);
}

int		max_len_map(char **map)
{
	size_t maxlen;
	int i;

	maxlen = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > maxlen)
			maxlen = ft_strlen(map[i]);
		i++;
	}
	return (maxlen);
}

void	display_spaces(char **map)
{
	int i;
	int j;
	int maxlen;

	i = 0;
	maxlen = max_len_map(map);
	while (map[i])
	{
		j = maxlen - ft_strlen(map[i]);
		while (j > 0)
		{
			map[i] = addspaces(map[i]);
			j--;
		}
		i++;
	}
}

char	**map_nextline(char **map, char *line, int n)
{
	char	**tmp;

	tmp = ft_calloc(n + 2, sizeof(char*));
	tmp[n] = line;
	while (n--)
		tmp[n] = map[n];
	free(map);
	return (tmp);
}
