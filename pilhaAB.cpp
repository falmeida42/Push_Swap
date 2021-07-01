#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
{
    int valor;
    struct t_list *proximo;
}t_list;


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

void push_a(t_list **primeirono, t_list **primeironob)
{
    no_esquerda(primeironob, (*primeirono)->valor);
    delet_esquerda(primeirono);
}
void push_b(t_list **primeirono, t_list **primeironob)
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
            printf("Nao ordenado\n");
            return ;
        }
        aux = aux->proximo;
    }
    printf("Ordenado\n");
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
    
    sorted(primeirono, primeironob);
    show_list(primeirono);
    show_list_b(primeironob);
    return (0);
}