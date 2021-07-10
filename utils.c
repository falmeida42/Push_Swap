/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:10:31 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/10 18:31:18 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     map_val(t_list *stack)
{
    t_list *aux;
    int i;

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

int     map_min(t_list *stack)
{
    t_list *aux;
    int j;

    aux = stack;
    j = 0;
    while (aux->valor != map_val(stack))
    {
        aux = aux->proximo;
        j++;
    }
    return (j);
}

bool    sorted(t_list *primeirono)
{
    t_list *aux;
    aux = primeirono;

    while (aux->proximo != NULL)
    {
        if (aux->valor > aux->proximo->valor)
            return (false);
        aux = aux->proximo;
    }
    return (true);
}

bool    max_list(t_list *stack)
{
    t_list *aux;
    int i;

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

int ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' ||
		*(str + i) == '\t' ||
		*(str + i) == '\r' ||
		*(str + i) == '\v' ||
		*(str + i) == '\f' ||
		*(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}

int lst_size(t_list *stack)
{
    t_list *tmp;
    int i;

    tmp = stack;

    i = 1;
    while (tmp->proximo != NULL)
    {    
        tmp = tmp->proximo;
        i++;
    }
    return (i);
}

t_list  *ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->proximo)
			lst = lst->proximo;
	}
	return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *newno)
{
	t_list	*ptr;
	if (lst)
	{
		if (*lst)
		{
			ptr = ft_lstlast(*lst);
			ptr->proximo = newno;
		}
		else
			*lst = newno;
	}
}

t_list  *ft_lstnew(int content)
{
	t_list	*ptr;
	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->valor = content;
	ptr->proximo = NULL;
	return (ptr);
}

void no_esquerda(t_list **primeirono, int valor)
{
    t_list *newno = (t_list *)malloc(sizeof(t_list));
    
    newno->proximo = *primeirono;
    newno->valor = valor;
    *primeirono = newno;
}
void delet_esquerda(t_list **primeirono)
{
    t_list *newno = *primeirono;
    *primeirono = (*primeirono)->proximo;
    free(newno);

}

void no_direita(t_list *primeirono, int valor)
{
    t_list *aux;
    t_list *newno = (t_list *)malloc(sizeof(t_list));

    aux = primeirono;
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    aux->proximo = newno;
    newno->valor = valor;
    newno->proximo = NULL;

}
void delet_direita(t_list *primeirono)
{
    t_list *aux;

    aux = primeirono;
    while (aux->proximo->proximo != NULL)
    {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
}