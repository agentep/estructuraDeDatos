#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "competidor.h"

// Llena los datos del competidor y pide memoria para los puntajes
int crear_competidor(Competidor *c, int id, const char *nombre, int n_puntajes)
{
    c->id = id;
    strcpy(c->nombre, nombre);
    c->n_puntajes = n_puntajes;
    c->promedio = 0;

    // malloc pide la memoria para n_puntajes numeros float
    c->puntajes = (float *)malloc(n_puntajes * sizeof(float));

    if (c->puntajes == NULL)
    {
        return 0; // pos no hay memoria
    }
    return 1;
}

// devuelve la memoria de los puntajes y pone el puntero en NULL para que no quede colgando
void liberar_competidor(Competidor *c)
{
    free(c->puntajes);
    c->puntajes = NULL;
}

// Suma todos los puntajes y los divide entre la cantidad
void calcular_promedio(Competidor *c)
{
    float suma = 0;
    int i;

    if (c->n_puntajes == 0)
    {
        c->promedio = 0;
        return;
    }

    for (i = 0; i < c->n_puntajes; i++)
    {
        suma = suma + c->puntajes[i];
    }

    c->promedio = suma / c->n_puntajes;
}

//  intercambia dos competidores usando una variable auxiliar
void intercambiar(Competidor *a, Competidor *b)
{
    Competidor aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

// imprime una fila con los datos del competidor
void imprimir_competidor(const Competidor *c)
{
    int i;

    printf("%-5d %-15s", c->id, c->nombre);
    for (i = 0; i < c->n_puntajes; i++)
    {
        printf(" %7.2f", c->puntajes[i]);
    }
    printf(" | Prom: %.2f\n", c->promedio);
}

// imprime el titulo de la tabla y luego todos los competidores
void imprimir_tabla(const Competidor *v, int n)
{
    int i;

    printf("\n%-5s %-15s %s\n", "ID", "NOMBRE", "PUNTAJES DE LOS PARTICIPANTES");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        imprimir_competidor(&v[i]);
    }
}