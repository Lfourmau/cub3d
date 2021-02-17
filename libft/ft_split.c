/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:21:18 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/01 16:28:47 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctw(const char *str, char sep)
{
	int		i;
	char	*strcount;

	strcount = (char *)str;
	i = 0;
	while (*strcount)
	{
		while (*strcount && *strcount == sep)
			strcount++;
		while (*strcount && *strcount != sep)
			strcount++;
		i++;
	}
	return (i);
}

static char	**ft_free_chains(char **chains, int i)
{
	while (--i >= 0)
		free(chains[i]);
	free(chains);
	return (NULL);
}

char		**ft_split(char const *str, char sep)
{
	char	**chains;
	char	*start;
	int		i;

	i = 0;
	if (!str || !(chains = malloc(sizeof(char *) * (ft_ctw(str, sep) + 1))))
		return (NULL);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		start = (char *)str;
		while (*str && *str != sep)
			str++;
		if (start != str)
		{
			if (!(chains[i] = malloc(sizeof(char) * (str - start + 1))))
				return (ft_free_chains(chains, i));
			ft_strlcpy(chains[i], start, str - start + 1);
			i++;
		}
	}
	chains[i] = 0;
	return (chains);
}
