/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:25:43 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/23 18:07:24 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *stack)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp->proximo != NULL)
	{
		tmp = tmp->proximo;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->valor = content;
	ptr->proximo = NULL;
	return (ptr);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (lst)
	{
		while (*lst)
		{
			nxt = (*lst)->proximo;
			ft_lstdelone(*lst, del);
			(*lst) = nxt;
		}
		lst = NULL;
	}
}

bool	max_list(t_list *stack)
{
	t_list	*aux;
	int		i;

	i = stack->valor;
	aux = stack;
	while (aux->proximo != NULL)
	{
		if (i < aux->valor)
			return (false);
		aux = aux->proximo;
	}
	return (true);
}
