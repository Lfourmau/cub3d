/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 07:32:14 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:08:25 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*secondlist;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	secondlist = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&secondlist, del);
			return (NULL);
		}
		ft_lstadd_back(&secondlist, tmp);
		lst = lst->next;
	}
	return (secondlist);
}
