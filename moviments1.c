/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:00:48 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/21 18:06:24 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **primeirono)
{
	swap(primeirono);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **primeirono)
{
	swap(primeirono);
	write(1, "sb\n", 3);
}

void	swap_a_b(t_list **primeirono, t_list **primeironob)
{
	swap(primeirono);
	swap(primeironob);
	write(1, "ss\n", 3);
}

void	push_a(t_list **primeirono, t_list **primeironob)
{
	push(primeironob, primeirono);
	write(1, "pa\n", 3);
}

void	push_b(t_list **primeirono, t_list **primeironob)
{
	push(primeirono, primeironob);
	write(1, "pb\n", 3);
}
