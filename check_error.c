/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:50:29 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/19 20:08:41 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_dup(t_list *stack_a)
{
	t_list	*val;
	t_list	*val_prox;

	if (!stack_a)
		return (false);
	val = stack_a;
	while (val->proximo)
	{
		val_prox = val->proximo;
		while (val_prox)
		{
			if (val_prox->valor == val->valor)
				return (false);
			val_prox = val_prox->proximo;
		}
		val = val->proximo;
	}
	return (true);
}

bool	check_char(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-')
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	check_error(int argc, char **argv)
{
	int		i;
	long	j;

	i = 0;
	while (i < argc)
	{
		j = ft_atol(argv[i]);
		if (check_char(argv[i++]) == 0 || j < INT_MIN || j > INT_MAX)
		{
			write(1, "Error\n", 6);
			return (false);
		}
	}
	return (true);
}
