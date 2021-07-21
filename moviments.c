/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:12:17 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/21 17:53:30 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->proximo)
			lst = lst->proximo;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = ft_lstlast(*lst);
			ptr->proximo = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->proximo = *lst;
		*lst = new;
	}
}

void	swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;

	if (!(*stack) || !((*stack)->proximo))
		return ;
	node_1 = *stack;
	node_2 = node_1->proximo;
	node_1->proximo = node_2->proximo;
	node_2->proximo = node_1;
	*stack = node_2;
}

void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*top;

	if (!(*stack_src))
		return ;
	top = *stack_src;
	*stack_src = (*stack_src)->proximo;
	top->proximo = NULL;
	ft_lstadd_front(stack_dst, top);
}

void	rotate(t_list **stack)
{
	t_list	*top;

	if (!(*stack) || !((*stack)->proximo))
		return ;
	top = *stack;
	*stack = top->proximo;
	top->proximo = NULL;
	ft_lstadd_back(stack, top);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*bot;
	t_list	*temp;

	if (!(*stack) || !((*stack)->proximo))
		return ;
	temp = *stack;
	bot = *stack;
	bot = ft_lstlast(bot);
	while (temp->proximo->proximo)
		temp = temp->proximo;
	temp->proximo = NULL;
	ft_lstadd_front(stack, bot);
}

/*
void	swap(t_list *primeirono)
{
	int	valor;

	if (!primeirono || !primeirono->proximo)
		return ;
	valor = primeirono->valor;
	primeirono->valor = primeirono->proximo->valor;
	primeirono->proximo->valor = valor;
}

void	push(t_list **primeirono, t_list **primeironob)
{
	if (*primeironob == NULL)
		return ;
	else
		no_esquerda(primeirono, (*primeironob)->valor);
	delet_esquerda(primeironob);
}

void	rotate(t_list **primeirono)
{
	no_direita((*primeirono), (*primeirono)->valor, (*primeirono)->index);
	delet_esquerda(primeirono);
}


void	reverse_rotate(t_list **primeirono)
{
	t_list	*aux;

	aux = *primeirono;
	while (aux->proximo)
		aux = aux->proximo;
	no_esquerda(primeirono, aux->valor);
	delet_direita(*primeirono);
}



void	reverse_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !((*stack)->proximo))
		return ;
	temp = *stack;;
	while (temp->proximo->proximo)
		temp = temp->proximo;
	temp->proximo = NULL;
	no_esquerda(stack, temp->valor);
}
*/
