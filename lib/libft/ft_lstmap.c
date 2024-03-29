/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:18:35 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/01 12:10:07 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	if (del != NULL)
		(*del)(lst->content);
	lst = lst->next;
	current = new;
	while (lst != NULL)
	{
		current->next = ft_lstnew(f(lst->content));
		current = current->next;
		if (current == NULL)
			ft_lstclear(&new, del);
		if (current == NULL)
			return (NULL);
		if (del != NULL)
			(*del)(lst->content);
		lst = lst->next;
	}
	return (new);
}
