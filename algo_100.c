/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:34:10 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/22 21:01:00 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_index(t_list *stack_a)
{
	t_list *aux;

	aux = stack_a;
	while (aux)
	{
		aux = aux->proximo;
	}
}

static void reset_index(t_list **stack_a)
{
	t_list *aux;

	aux = *stack_a;
	while (aux)
	{
		aux->index = 0;
		aux = aux->proximo;
	}
}

void	cont_index(t_list **stack_a)
{
	t_list *aux;
	t_list *aux_prox;

	aux = *stack_a;
	reset_index(stack_a);
	while (aux)
	{
		aux_prox = *stack_a;
		while (aux_prox)
		{
			if (aux->valor > aux_prox->valor)
				aux->index++;
			aux_prox = aux_prox->proximo;
		}
		aux = aux->proximo;
	}
}

int find_val(t_list *stack_a, int valor)
{
	t_list *aux;
	int i;

	i = 0;
	aux = stack_a;
	while (aux->valor != valor)
	{
		aux = aux->proximo;
		i++;
	}
	return (i);
}

void	decide_b(t_list **stack_a, t_list **stack_b, int chunk, int size)
{
	t_list *aux;
	int i;
	i = size / 5;
	if (!(*stack_a))
		return ;
	aux = *stack_a;
	while (i)
	{
		decisions(stack_a, stack_b, chunk, size);
		i--;
	}
}

void	algo_100(t_list **stack_a, t_list **stack_b)
{
	int chunk;
	int	size; 

	size = lst_size(*stack_a);
	chunk = size / 5;
	while (chunk <= size)
	{
		decide_b(stack_a, stack_b, chunk, size);
		chunk += size / 5;
	}
	while (*stack_b)
	{
		if (find_val(*stack_b, map_max(*stack_b)) < size / 2)
			while (map_max(*stack_b) != (*stack_b)->valor)
				rotate_b(stack_b);
		else
			while (map_max(*stack_b) != (*stack_b)->valor)
				reverse_rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
}