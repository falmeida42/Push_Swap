/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:10:31 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/21 17:36:46 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	map_val(t_list *stack)
{
	t_list	*aux;
	int		i;

	aux = stack;
	i = aux->valor;
	while (aux)
	{
		if (aux->valor < i)
			i = aux->valor;
		aux = aux->proximo;
	}
	return (i);
}

int	map_max(t_list *stack)
{
	t_list	*aux;
	int		i;

	aux = stack;
	i = aux->valor;
	while (aux)
	{
		if (aux->valor > i)
			i = aux->valor;
		aux = aux->proximo;
	}
	return (i);
}

int	map_min(t_list *stack)
{
	t_list	*aux;
	int		j;

	aux = stack;
	j = 0;
	while (aux->valor != map_val(stack))
	{
		aux = aux->proximo;
		j++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' || *(str + i) == '\t' || *(str + i) == '\r'
		|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}

bool	sorted(t_list *primeirono)
{
	t_list	*aux;

	aux = primeirono;
	while (aux->proximo != NULL)
	{
		if (aux->valor > aux->proximo->valor)
			return (false);
		aux = aux->proximo;
	}
	return (true);
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
