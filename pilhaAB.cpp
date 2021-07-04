#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
{
    int valor;
    struct t_list *proximo;
}t_list;


int		ft_atoi(const char *str)
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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->proximo)
			lst = lst->proximo;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *newno)
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

t_list	*ft_lstnew(int content)
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

// Mecanismos Push Swap
void swap(t_list *primeirono)
{
    int valor;

    if(!primeirono || !primeirono->proximo)
        return ;
    valor = primeirono->valor;
    primeirono->valor = primeirono->proximo->valor;
    primeirono->proximo->valor = valor;
}
void swap_a_b(t_list *primeirono, t_list *primeironob)
{
    swap(primeirono);
    swap(primeironob);
}

void push_b(t_list **primeirono, t_list **primeironob)
{
    no_esquerda(primeironob, (*primeirono)->valor);
    delet_esquerda(primeirono);
}
void push_a(t_list **primeirono, t_list **primeironob)
{
    no_esquerda(primeirono, (*primeironob)->valor);
    delet_esquerda(primeironob);
}

void rotate(t_list **primeirono)
{
    no_direita((*primeirono), (*primeirono)->valor);
    delet_esquerda(primeirono);
}
void rotate_ab(t_list **primeirono, t_list **primeironob)
{
    rotate(primeirono);
    rotate(primeironob);
}

void reverse_rotate(t_list **primeirono)
{
    t_list *aux;

    aux = *primeirono;
    while (aux->proximo != NULL)
        aux = aux->proximo;
    no_esquerda(primeirono, aux->valor);
    delet_direita(*primeirono);
}
void reverse_rotate_ab(t_list **primeirono, t_list **primeironob)
{
    reverse_rotate(primeirono);
    reverse_rotate(primeironob);
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

// Mecanismos de Checagem
void sorted(t_list *primeirono, t_list *primeironob)
{
    t_list *aux;
    t_list *auxb;
    aux = primeirono;
    auxb = primeironob;

    /*
    if (!NULL)
    {
        printf("ERROR");
    }
    */
    while (aux->proximo != NULL)
    {
        if (aux->valor > aux->proximo->valor)
        {
            //printf("Nao ordenado\n");
            return ;
        }
        aux = aux->proximo;
    }
    //printf("Ordenado\n");
}
// Mecanismos de Checagem

// Algoritmo
void algo_3(t_list **stack_a, t_list **stack_b)
{
    
}
void select_algo(t_list **stack_a, t_list **stack_b)
{
    int nbr;

    nbr = lst_size(*stack_a) - 1;

    if (nbr <= 5)
       algo_3(stack_a, stack_b);
 
}
// Algoritmo

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

    sorted(stack_a, stack_b);
    select_algo(&stack_a, &stack_b);
    show_list(stack_a);
    show_list_b(stack_b);
    return (0);
}