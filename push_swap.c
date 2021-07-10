#include "push_swap.h"

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
    if (sorted(*stack_a) == false)
    {
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
}

void algo_5(t_list **stack_a, t_list **stack_b)
{
    while(lst_size(*stack_a) > 3)
    {
        while ((*stack_a)->valor != map_val(*stack_a))
        {
            if (map_min(*stack_a) < lst_size(*stack_a) / 2)
                rotate_a(stack_a);
            else
                reverse_rotate_a(stack_a);
        }
        push_b(stack_a, stack_b);
    }
    algo_3(stack_a);
    while ((*stack_b) != NULL)
        push_a(stack_a, stack_b);
}

void select_algo(t_list **stack_a, t_list **stack_b)
{
    int nbr;

    nbr = lst_size(*stack_a);

    if (nbr == 2)
        swap_a(*stack_a);
    else if (nbr == 3)
        algo_3(stack_a);
    else if (nbr > 3 && nbr < 101)
        algo_5(stack_a, stack_b);
    else
        printf("algo100");
  
}

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
    if (sorted(stack_a) == false)
        select_algo(&stack_a, &stack_b);
    show_list(stack_a);
    show_list_b(stack_b);
    return (0);
}