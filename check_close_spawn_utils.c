/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_spawn_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:17:14 by loic              #+#    #+#             */
/*   Updated: 2021/03/01 16:28:56 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int isspawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int check_around(char c)
{
	if (c == ' ')
		return (1);
	if (c != '0' && c != '2' && c != '1' && !isspawn(c))
		return (1);
	return (0);
}
