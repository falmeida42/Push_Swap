/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:37:56 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/10 18:46:06 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct t_list
{
    int valor;
    struct t_list *proximo;
}t_list;

//APAGAAAAAAAAAAR
void show_list(t_list *primeirono);
void show_list_b(t_list *primeirono);
//APAGAAAAAAAAAAR

void    swap_a(t_list *primeirono);
void    swap_b(t_list *primeirono);
void    swap_a_b(t_list *primeirono, t_list *primeironob);
void    push_a(t_list **primeirono, t_list **primeironob);
void    push_b(t_list **primeirono, t_list **primeironob);
void    rotate_a(t_list **primeirono);
void    rotate_b(t_list **primeirono);
void    rotate_ab(t_list **primeirono, t_list **primeironob);
void    reverse_rotate_a(t_list **primeirono);
void    reverse_rotate_b(t_list **primeirono);
void    reverse_rotate_ab(t_list **primeirono, t_list **primeironob);

void    ft_lstadd_back(t_list **lst, t_list *newno);
void    no_esquerda(t_list **primeirono, int valor);
void    delet_esquerda(t_list **primeirono);
void    no_direita(t_list *primeirono, int valor);
void    delet_direita(t_list *primeirono);

long ft_atol(char *str);
int ft_atoi(const char *str);
int map_val(t_list *stack);
int map_min(t_list *stack);
int lst_size(t_list *stack);

bool    sorted(t_list *primeirono);
bool    max_list(t_list *stack);

t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(int content);

#endif