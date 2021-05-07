/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 07:13:57 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/07 07:32:48 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isline_break(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_loop(char *buffer, char *tmp, int *read_return, int fd)
{
	while (!ft_isline_break(buffer) && *read_return != 0)
	{
		*read_return = read(fd, tmp, BUFFER_SIZE);
		if (*read_return == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[*read_return] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	return (buffer);
}
