/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:20:29 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/23 18:13:49 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_ab(t_list **primeirono, t_list **primeironob)
{
	reverse_rotate(primeirono);
	reverse_rotate(primeironob);
	write(1, "rrr\n", 4);
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

long	ft_atol(char *str)
{
	int		i;
	long	num;
	int		sign;

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
