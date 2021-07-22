/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:05:46 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/22 21:01:00 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_holdfirst(t_list **stack_a, int chunk)
{
  t_list *aux;
  int i;

  i = 0;
  aux = *stack_a;
  while (aux->index > chunk)
  {
    aux = aux->proximo;
    i++;
  }
  return (i);
}

int find_holdsecond(t_list **stack_a, int chunk, int size)
{
  t_list *aux;
  int i;
  int j;

  j = 0;
  i = 0;
  aux = *stack_a;
  while (aux)
  {
    if (aux->index < chunk)
      j = i;
    aux = aux->proximo;
    i++;
  }
  j = size - j;
  return (j);
}

void  go_tob(t_list **stack_a, t_list **stack_b, int size)
{
  int max;
 
  if (*stack_b)
  {
    max = map_max(*stack_b);
    if ((*stack_a)->valor > max)
    {
      //printf("max posix: %d size/2: %d", find_val(*stack_b, max), size / 2);
      if (find_val(*stack_b, max) < size / 2)
      {
        while ((*stack_b)->valor < max)
          rotate_b(stack_b);
      }
      else
      {
         while ((*stack_b)->valor < max)
          reverse_rotate_b(stack_b);
      }
      push_b(stack_a, stack_b);
    }
    else
      push_b(stack_a, stack_b);
  }
  else
      push_b(stack_a, stack_b);

}

void  decisions(t_list **stack_a, t_list **stack_b, int chunk, int size)
{
  int hold_first;
  int hold_second;

  hold_first = find_holdfirst(stack_a, chunk);
  hold_second = find_holdsecond(stack_a, chunk, size);

  //printf("hold first: %d hold second: %d\n", hold_first, hold_second);
  if (hold_first < hold_second)
  {
    while ((*stack_a)->index + 1 > chunk)
      rotate_a(stack_a);
  }
  else
  {
    while ((*stack_a)->index + 1 > chunk)
      reverse_rotate_a(stack_a);
  }
	push_b(stack_a, stack_b);
}