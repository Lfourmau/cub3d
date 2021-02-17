/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 04:09:16 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/27 10:26:10 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *nouveau;

	nouveau = malloc(sizeof(t_list));
	if (nouveau == NULL)
		return (NULL);
	nouveau->content = content;
	nouveau->next = NULL;
	return (nouveau);
}
