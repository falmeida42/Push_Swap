/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:34:10 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/21 19:11:28 by falmeida         ###   ########.fr       */
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
			while ((*stack_a)->index + 1 > chunk)
			{
				rotate_a(stack_a);
			}
			push_b(stack_a, stack_b);
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
		while (map_max(*stack_b) != (*stack_b)->valor)
		{
			rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}