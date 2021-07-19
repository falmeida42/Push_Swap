/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:19:56 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/19 21:26:57 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **primeirono)
{
	rotate(primeirono);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **primeirono)
{
	rotate(primeirono);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **primeirono, t_list **primeironob)
{
	rotate(primeirono);
	rotate(primeironob);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_list **primeirono)
{
	reverse_rotate(primeirono);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **primeirono)
{
	reverse_rotate(primeirono);
	write(1, "rrb\n", 4);
}
