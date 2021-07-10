/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:00:48 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/10 18:16:12 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list *primeirono)
{
    int valor;

    if(!primeirono || !primeirono->proximo)
        return ;
    valor = primeirono->valor;
    primeirono->valor = primeirono->proximo->valor;
    primeirono->proximo->valor = valor;
    write(1, "sa\n", 3);
}
void swap_b(t_list *primeirono)
{
    int valor;

    if(!primeirono || !primeirono->proximo)
        return ;
    valor = primeirono->valor;
    primeirono->valor = primeirono->proximo->valor;
    primeirono->proximo->valor = valor;
    write(1, "sa\n", 3);
}
void swap_a_b(t_list *primeirono, t_list *primeironob)
{
    swap_a(primeirono);
    swap_b(primeironob);
    write(1, "ss\n", 3);
}

void push_a(t_list **primeirono, t_list **primeironob)
{
    if (*primeironob == NULL)
        return ;
    else
        no_esquerda(primeirono, (*primeironob)->valor);
        delet_esquerda(primeironob);
        write(1, "pa\n", 3);
}
void push_b(t_list **primeirono, t_list **primeironob)
{
    if (primeirono == NULL)
        return;
    no_esquerda(primeironob, (*primeirono)->valor);
    delet_esquerda(primeirono);
    write(1, "pb\n", 3);
}

void rotate_a(t_list **primeirono)
{
    no_direita((*primeirono), (*primeirono)->valor);
    delet_esquerda(primeirono);
    
    write(1, "ra\n", 3);
}
void rotate_b(t_list **primeirono)
{
    no_direita((*primeirono), (*primeirono)->valor);
    delet_esquerda(primeirono);
    write(1, "rb\n", 3);
}
void rotate_ab(t_list **primeirono, t_list **primeironob)
{
    rotate_a(primeirono);
    rotate_b(primeironob);
    write(1, "rr\n", 3);
}

void reverse_rotate_a(t_list **primeirono)
{
    t_list *aux;

    aux = *primeirono;
    while (aux->proximo != NULL)
        aux = aux->proximo;
    no_esquerda(primeirono, aux->valor);
    delet_direita(*primeirono);
    write(1, "rra\n", 4);
}
void reverse_rotate_b(t_list **primeirono)
{
    t_list *aux;

    aux = *primeirono;
    while (aux->proximo != NULL)
        aux = aux->proximo;
    no_esquerda(primeirono, aux->valor);
    delet_direita(*primeirono);
    write(1, "rrb\n", 4);
}
void reverse_rotate_ab(t_list **primeirono, t_list **primeironob)
{
    reverse_rotate_a(primeirono);
    reverse_rotate_b(primeironob);
    write(1, "rrr\n", 4);
}