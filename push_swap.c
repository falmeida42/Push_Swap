#include "push_swap.h"

bool check_dup(t_list *stack_a)
{

   t_list *val;
   t_list *val_prox;

   val = stack_a;
   while (val)
   {
       val_prox = val->proximo;
       while (val_prox)
       {
           if (val->valor == val_prox->valor)
                return(false);
            val_prox = val_prox->proximo;
       }
       val = val->proximo; 
   }
   return (true);
}


bool check_char(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] == '-')
            i++;
        if (!(argv[i] >= '0' && argv[i] <= '9'))
            return (false);
        i++;
    }
    return (true);
}

bool check_error(int argc, char **argv)
{
    int i;
    long j;

    i = 0;
    while (i < argc)
    {
        j = ft_atol(argv[i]);
        if (check_char(argv[i++]) == 0 || j < INT_MIN || j > INT_MAX)
        {
            write(1, "Error\n", 6);
            return (false);
        }
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

void sort_list(int lista[], int nbr)
{
    int i;
    int j;
    int swap;
    i = 0;
    while (i < nbr)
    {
        j = i + 1;
        while (j < nbr)
        {
            if (lista[i] > lista[j])
            {
                swap = lista[i];
                lista[i] = lista[j];
                lista[j] = swap;
            }
            j++;
        }
        i++;
    }
}
void fill_vetor(t_list *stack_a, int lista[])
{
    t_list *aux;
    int i;
    aux = stack_a;
    i = 0;
    while (aux)
    {
        lista[i] = aux->valor;
        aux = aux->proximo;
        i++;
    }
}

void check_vetor(int lista[], int nbr)
{
    int i;

    i = 0;
    printf("\n");
    while (i < nbr)
    {
        printf("%d ", lista[i]);
        i++;
    }
    printf("\n");
}

bool check_holdfirst(int chunk1, int lista[], t_list *stack_a)
{
    t_list *aux;
    long int hold_first;
    int i;
    int j;

    i = 0;
    aux = stack_a;
    hold_first = 2147483648;
    while (i < chunk1)
    {
        j = 0;
        while (j < chunk1)
        {
            if (lista[j] == aux->valor && lista[j] < hold_first)
            return (true);
            j++;
        }
        aux = aux->proximo;
        i++;
    }
    return (false);
}

int mapear_valor(t_list *stack_a, int valor)
{
    t_list *aux;
    int i;

    i = 0;
    aux = stack_a;
    while (aux)
    {
        if (aux->valor == valor)
            break ;
        aux = aux->proximo;
        i++;
    }
    return (i);
}

int map_holdfirst(int chunk1, int lista[], t_list *stack_a)
{
    t_list *aux;
    int hold_first;
    int i;
    int j;
    int map;

    i = 0;
    aux = stack_a;
    hold_first = 2147483647;
    while (i < chunk1)
    {
        j = 0;
        while (j < chunk1)
        {
            if (lista[j] == aux->valor && lista[j] <= hold_first)
            hold_first = lista[j];
            j++;
        }
        aux = aux->proximo;
        i++;
    }
    map = mapear_valor(stack_a, hold_first);
    return (map);
}

int map_holdsecond(int chunk1, int lista[], t_list *stack_a)
{
    t_list *aux;
    int i;
    int hold_second;
    int map;
    int j;
    int k;

    i = 0;
    aux = stack_a;
    hold_second = aux->valor;
    while (i < chunk1)
    {
        k = 0;
        while (aux)
        {
            if (aux->valor == lista[i] && k > j)
            {
                hold_second = lista[i];
                j = mapear_valor(stack_a, hold_second);
            }            k++;
            aux = aux->proximo;
        }
        aux = stack_a;
        i++;
    }
    map = mapear_valor(stack_a, hold_second);
    return (map);
}

int valor_selecionado(t_list *stack_a, int nbr)
{
    t_list *aux;
    int i;

    aux = stack_a;
    i = 0;
    while (i < nbr)
    {
        aux = aux->proximo;
        i++;
    }
    return (aux->valor);
}

int maior_valor(t_list *stack)
{
    t_list *aux;
    int i;

    i = aux->valor;
    aux = stack;
    while (aux)
    {
        if (aux->valor > i)
            i = aux->valor;
        aux = aux->proximo;
    }
    return (i);
}

int menor_valor(t_list *stack)
{
    t_list *aux;
    int i;

    i = aux->valor;
    aux = stack;
    while (aux)
    {
        if (aux->valor < i)
            i = aux->valor;
        aux = aux->proximo;
    }
    return (i);
}

void go_pb(t_list **stack_a, t_list **stack_b, int valor)
{
    int big;
    int small;

    big = maior_valor(*stack_b);
    small = menor_valor(*stack_b);
    printf("%d\n", big);
    printf("%d\n", small);

    push_b(stack_a, stack_b);
}

void decisions_100(t_list **stack_a, t_list **stack_b, int hf, int hs, int size)
{
    int middle;
    int valor;
    int cmp_hs;
    middle = size / 2;
    
    if (hf == -1)
    {
        valor = valor_selecionado(*stack_a, hs);
        if (hs > middle)
        {
            while ((*stack_a)->valor != valor)
                reverse_rotate_a(stack_a);
        }
        else
        {
            while ((*stack_a)->valor != valor)
                rotate_a(stack_a);
        }
        go_pb(stack_a, stack_b, valor); 
    }
    else
    {
        cmp_hs = size - hs;
        if (cmp_hs < hf)
        {
            valor = valor_selecionado(*stack_a, hs);
            if (hs > middle)
            {
                while ((*stack_a)->valor != valor)
                    reverse_rotate_a(stack_a);
            }
            else
            {
                while ((*stack_a)->valor != valor)
                    rotate_a(stack_a);
            }
            go_pb(stack_a, stack_b, valor);
        }
        else
        {
            valor = valor_selecionado(*stack_a, hf);
            if (hf > middle)
            {
                while ((*stack_a)->valor != valor)
                    reverse_rotate_a(stack_a);
            }
            else
            {
                while ((*stack_a)->valor != valor)
                    rotate_a(stack_a);
            }
            go_pb(stack_a, stack_b, valor);
        }
    }
}

void show_chunk1(int lista[], int chunk1)
{
    int i;

    i = 0;
    while (i < chunk1)
    {
        printf("%d\n", lista[i]);
        i++;
    }
}

void algo_100(t_list **stack_a, t_list **stack_b)
{
    int lista[lst_size(*stack_a)];
    int size;
    int chunk1;
    int hold_first;
    int hold_second;
    int i;
    int j;
    *stack_b = NULL;

    i = 0;
    size = lst_size(*stack_a);
    fill_vetor(*stack_a, lista);
    sort_list(lista, size);
    size = lst_size(*stack_a);
    chunk1 = size / 5;
    j = chunk1;
    while (j)
    {
        if (check_holdfirst(chunk1, lista, *stack_a) == true)
            hold_first = map_holdfirst(chunk1, lista, *stack_a);
        else
            hold_first = -1;
        hold_second = map_holdsecond(chunk1, lista, *stack_a);
        decisions_100(stack_a, stack_b, hold_first, hold_second, size);
        j--;
    }
}

void select_algo(t_list **stack_a, t_list **stack_b)
{
    int nbr;

    nbr = lst_size(*stack_a);

    if (nbr == 2)
        swap_a(*stack_a);
    else if (nbr == 3)
        algo_3(stack_a);
    else if (nbr <= 5)
        algo_5(stack_a, stack_b);
    else
        algo_100(stack_a, stack_b);
  
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
    /*
    if (check_dup(stack_a) == false)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    */
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

    if (check_error(argc - 1, argv + 1) == true)
    {
        stack_a = fill_stack(argc, argv);
        if (sorted(stack_a) == false)
            select_algo(&stack_a, &stack_b);
        show_list(stack_a);
        show_list_b(stack_b);
    }
    return (0);
}