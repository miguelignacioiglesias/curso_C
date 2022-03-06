/*** COLAS CON LISTAS ENLAZADAS ***/
/*
    Una cola es una estructura de tipo FIFO (first-in - First-out)
    Las funciones pricipales de una cola son:
    - Insertar (PUSH)
    - Extraer  (POP)

    - Imprimir

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Declaramos las extructura nodo para la cola.
typedef struct NodoCola
{
    int edad;
    struct NodoCola *sig;
}NodoCola;


void insertar(NodoCola **, NodoCola **, int);  // Inserta nodos al final de la cola.
void imprimir(NodoCola *);


int main(int argc, char *argv[])
{
    int edad;
    int sigue = 1; // condicion de corte del ciclo while

    /* Se ingresa por el fondo y se extrae por el tope */
    NodoCola *tope = NULL;  // puntero al primer elemento ingresado
    NodoCola *fondo = NULL;  // puntero al ultimo elemento ingresado

    while(sigue)
    {
        printf("Ingrese una edad: ");
        scanf("%d", &edad);
        insertar(&tope, &fondo, edad);
        printf("Sigue? 1-si 0-no : ");
        scanf("%d", &sigue);
    }
    imprimir(tope);

    return 0;
}

void insertar(NodoCola **tope, NodoCola **fondo, int edad)
{
    NodoCola *aux = NULL;
    NodoCola *nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    if(nuevo == NULL)
    {
        printf("error al reservar memoria");
        exit(1);
    }
    nuevo->edad = edad;
    nuevo->sig = NULL;

    if(*tope == NULL)  // de ser verdadero, la cola esta vacia.
    {
        printf("la cola esta vacia!\n");
        *tope = nuevo;
        *fondo = nuevo;
    }
    else
    {
        aux = *fondo;
        aux->sig = nuevo;
        *fondo = nuevo;
    }
}


void imprimir(NodoCola *tope) // imprime la cola con recursion.
{
    if(tope != NULL)
    {
        printf("edad %d\n", tope->edad);
        imprimir(tope->sig);
    }
}
