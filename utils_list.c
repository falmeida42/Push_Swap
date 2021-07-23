/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:23:12 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/23 18:10:34 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_esquerda(t_list **primeirono, int valor)
{
	t_list	*newno;

	newno = (t_list *)malloc(sizeof(t_list));
	newno->proximo = *primeirono;
	newno->valor = valor;
	*primeirono = newno;
}

void	delet_esquerda(t_list **primeirono)
{
	t_list	*newno;

	newno = *primeirono;
	*primeirono = (*primeirono)->proximo;
	free(newno);
}

void	no_direita(t_list *primeirono, int valor, int index)
{
	t_list	*aux;
	t_list	*newno;

	newno = (t_list *)malloc(sizeof(t_list));
	aux = primeirono;
	while (aux->proximo != NULL)
	{
		aux = aux->proximo;
	}
	aux->proximo = newno;
	newno->valor = valor;
	newno->index = index;
	newno->proximo = NULL;
}

void	delet_direita(t_list *primeirono)
{
	t_list	*aux;

	aux = primeirono;
	while (aux->proximo->proximo != NULL)
	{
		aux = aux->proximo;
	}
	free(aux->proximo);
	aux->proximo = NULL;
}

void	reset_index(t_list **stack_a)
{
	t_list	*aux;

	aux = *stack_a;
	while (aux)
	{
		aux->index = 0;
		aux = aux->proximo;
	}
}
