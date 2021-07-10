#include "push_swap.h"

void show_list(t_list *primeirono)
{
    t_list *aux;
    
    aux = primeirono;
    printf("-------------PILHA-------------\n");
    while (aux)
    {
        printf("%d  |  ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}
