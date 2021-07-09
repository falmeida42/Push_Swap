#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct t_list
{
    int valor;
    struct t_list *proximo;
}t_list;

// Utilidades
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
// Utilidades

// Mecanismos Push Swap
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

void show_list(t_list *primeirono)
{
    t_list *aux;
    
    aux = primeirono;
    printf("-------------PILHA A-------------\n");
    while (aux)
    {
        printf("%d  |  ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}
void show_list_b(t_list *primeironob)
{
    t_list *aux;
    
    aux = primeironob;
    printf("-------------PILHA B-------------\n");
    while (aux)
    {
        printf("%d  |  ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}
// Mecanismos Push Swap

// Algoritmo
void algo_3(t_list **stack_a)
{
    t_list *ax;
    int a;
    int b;
    int c;

    ax = *stack_a;
    a = ax->valor;
    b = ax->proximo->valor;
    c = ax->proximo->proximo->valor;
    if (a > b && b < c && c > a)
        swap_a(*stack_a);
    else if (a > b && b > c && c < a)
    {
        swap_a(*stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (a > b && b < c && c < a)
        rotate_a(stack_a);
    else if (a < b && b > c && c > a)
    {
        swap_a(*stack_a);
        rotate_a(stack_a);
    }
    else
        reverse_rotate_a(stack_a);
}

void algo_5(t_list **stack_a, t_list **stack_b)
{
    while ((*stack_a)->valor != map_val(*stack_a))
    {
        if (map_min(*stack_a) < lst_size(*stack_a) / 2)
            rotate_a(stack_a);
        else
            reverse_rotate_a(stack_a);
    }
}

void select_algo(t_list **stack_a, t_list **stack_b)
{
    int nbr;

    nbr = lst_size(*stack_a) - 1;

    if (nbr <= 3)
        algo_3(stack_a);
    else
        algo_5(stack_a, stack_b);
  
}
// Algoritmo

// Mecanismos de Checagem

bool dup_check(t_list *stack_a)
{
    t_list *aux;
    t_list *aux_prox;

    aux = stack_a;
    while (aux)
    {
        aux_prox = aux->proximo;
        while (aux_prox)
        {
            if (aux->valor == aux_prox->valor)
                return (false);
                aux_prox = aux_prox->proximo;
        }
        aux = aux->proximo;
    }
    return (true);
}

// Mecanismos de Checagem

t_list *fill_stack(int argc, char **argv)
{
    t_list *stack_a;
    
    int    nbr;
    int    i;

    stack_a = NULL;
    i = 1;
    while (i < argc)
    {
        nbr = ft_atoi(argv[i++]);
        ft_lstadd_back(&stack_a, ft_lstnew(nbr));
    }
    if (dup_check(stack_a) == false)
        return (0);
    else
        return (stack_a);
}

int main(int argc, char **argv)
{   
    t_list *stack_a;
    t_list *stack_b;
    
    if (argc == 1)
        return (0);
    stack_a = NULL;
    stack_b = NULL;

    stack_a = fill_stack(argc, argv);
    select_algo(&stack_a, &stack_b);
    show_list(stack_a);
    show_list_b(stack_b);
    return (0);
}