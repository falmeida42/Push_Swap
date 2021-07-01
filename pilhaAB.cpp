#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
{
    int valor;
    struct t_list *proximo;
}t_list;


void no_esquerda_a(t_list *primeirono, int valor)
{
    t_list *newno = (t_list *)malloc(sizeof(t_list));
    t_list *old_head = primeirono->proximo;
    
    primeirono->proximo = newno;
    newno->proximo = old_head;
    newno->valor = valor;
}
t_list *no_esquerda_b(t_list *primeironob, int valor)
{
    t_list *newno = (t_list *)malloc(sizeof(t_list));
    newno->valor = valor;
    newno->proximo = primeironob;
}

t_list *delet_esquerda_a(t_list *primeirono)
{
    t_list *newno = primeirono;
    primeirono = primeirono->proximo;
    free(newno);
    
    return (primeirono);
}
t_list *delet_esquerda_b(t_list *primeironob)
{
    t_list *newno = primeironob;
    primeironob = primeironob->proximo;
    free(newno);

    return (primeironob);
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
void swap_a(t_list *primeirono)
{
    int valor;

    if(!primeirono || !primeirono->proximo)
        return ;
    valor = primeirono->valor;
    primeirono->valor = primeirono->proximo->valor;
    primeirono->proximo->valor = valor;
}
void swap_b(t_list *primeirono)
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
    swap_a(primeirono);
    swap_b(primeironob);
}


int main(void)
{   
    t_list *primeirono = (t_list *)malloc(sizeof(t_list));
    t_list *segundono = (t_list *)malloc(sizeof(t_list));
    t_list *terceirono = (t_list *)malloc(sizeof(t_list));
    t_list *quartono = (t_list *)malloc(sizeof(t_list));
    t_list *quintono = (t_list *)malloc(sizeof(t_list));
    
    t_list *primeironob = (t_list *)malloc(sizeof(t_list));
    t_list *segundonob = (t_list *)malloc(sizeof(t_list));
    t_list *terceironob = (t_list *)malloc(sizeof(t_list));
    
    primeirono->valor = 10;
    primeirono->proximo = segundono;
    segundono->valor = 20;
    segundono->proximo = terceirono;
    terceirono->valor = 30;
    terceirono->proximo = quartono;
    quartono->valor = 40;
    quartono->proximo = quintono;
    quintono->valor = 50;
    quintono->proximo = NULL;

    primeironob->valor = 60;
    primeironob->proximo = segundonob;
    segundonob->valor = 70;
    segundonob->proximo = terceironob;
    terceironob->valor = 80;
    terceironob->proximo = NULL;
    
    show_list(primeirono);
    show_list_b(primeironob);
    return (0);
}