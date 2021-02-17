/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 06:23:44 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/29 15:06:37 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tosupp;
	t_list	*tmp;

	if (lst != NULL)
	{
		tosupp = *lst;
		while (tosupp)
		{
			tmp = tosupp->next;
			(*del)(tosupp->content);
			free(tosupp);
			tosupp = tmp;
		}
		*lst = NULL;
	}
}
