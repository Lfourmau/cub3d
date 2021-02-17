/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:23:19 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/27 10:55:48 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_same_char_strtrim(const char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_str(char const *str, char const *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_same_char_strtrim(set, str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

char		*ft_strtrim(char const *str, char const *set)
{
	char *start;
	char *cpy;

	if (str == 0)
		return (0);
	if (ft_check_str(str, set))
		return (ft_strdup(""));
	while (ft_same_char_strtrim(set, *str))
		str++;
	start = (char *)str;
	while (*str)
		str++;
	str--;
	while (ft_same_char_strtrim(set, *str))
		str--;
	str++;
	cpy = malloc(str - start + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, start, str - start + 1);
	return (cpy);
}
