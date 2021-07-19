/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:12:17 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/19 21:26:29 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	no_direita((*primeirono), (*primeirono)->valor);
	delet_esquerda(primeirono);
}

void	reverse_rotate(t_list **primeirono)
{
	t_list	*aux;

	aux = *primeirono;
	while (aux->proximo != NULL)
		aux = aux->proximo;
	no_esquerda(primeirono, aux->valor);
	delet_direita(*primeirono);
}
