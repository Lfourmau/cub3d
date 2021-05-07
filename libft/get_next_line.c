/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:06:55 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/07 07:32:58 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == 0)
		return (0);
	while (src[i] && i < size - 1)
	{
		if (size > 0)
		{
			dest[i] = src[i];
		}
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (dest);
}

static char	*after_lb(char *str)
{
	char				*chain;
	unsigned int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	chain = ft_substr(str, i + 1, (ft_strlen(str) - i));
	free(str);
	return (chain);
}

static char	*before_lb(char *str)
{
	int		i;
	char	*chain;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	chain = malloc(sizeof(char) * (i + 1));
	if (!chain)
		return (NULL);
	return (ft_strlcpy_gnl(chain, str, i + 1));
}

int	get_next_line(int fd, char **line)
{
	char			*tmp;
	static char		*buffer;
	int				read_return;

	read_return = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (-1);
	buffer = gnl_loop(buffer, tmp, &read_return, fd);
	if (buffer == NULL)
		return (-1);
	free(tmp);
	*line = before_lb(buffer);
	buffer = after_lb(buffer);
	if (read_return == 0)
		return (0);
	return (1);
}
