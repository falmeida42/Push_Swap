#include "push_swap.h"

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

void show_list_b(t_list *primeirono)
{
    t_list *aux;
    
    aux = primeirono;
    printf("-------------PILHA B-------------\n");
    while (aux)
    {
        printf("%d  |  ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}