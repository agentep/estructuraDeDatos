#include "ordenamiento.h"

// aqui esta la funcion que compara si estan mal ordenados, si es asi devuelve 1, sino devuelve 0
int mal_ordenados(float a, float b, int orden)
{
    if (orden == ASCENDENTE)
    {
        if (a > b)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        if (a < b)
        {
            return 1;
        }
        return 0;
    }
}

// buble sort, compara cada elemento con el de al lado y si estan mal ordenados los cambia, Se repite hasta que quede ordenado
// personalmente me gusta mas el buble sort
long bubble_sort(Competidor *v, int n, int orden)
{
    long comparaciones = 0;
    int i, j;
    int cambio;

    for (i = 0; i < n - 1; i++)
    {
        cambio = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            comparaciones++;
            if (mal_ordenados(v[j].promedio, v[j + 1].promedio, orden) == 1)
            {
                intercambiar(&v[j], &v[j + 1]);
                cambio = 1;
            }
        }
        // si en una vuelta no cambio nada, ya esta ordenado 
        if (cambio == 0)
        {
            break;
        }
    }

    return comparaciones;
}

// Busca el mejor elemento de la parte que falta por ordenar y lo pone en la primera posicion de esa parte
long selection_sort(Competidor *v, int n, int orden)
{
    long comparaciones = 0;
    int i, j;
    int pos; // posicion del mejor elemento encontrado 

    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            comparaciones++;
            if (mal_ordenados(v[pos].promedio, v[j].promedio, orden) == 1)
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            intercambiar(&v[i], &v[pos]);
        }
    }

    return comparaciones;
}

// Toma cada elemento y lo mete en el lugar que le toca dentro de la parte que ya esta ordenada
long insertion_sort(Competidor *v, int n, int orden)
{
    long comparaciones = 0;
    int i, j;
    Competidor actual;

    for (i = 1; i < n; i++)
    {
        actual = v[i];
        j = i - 1;

        while (j >= 0)
        {
            comparaciones++;
            if (mal_ordenados(v[j].promedio, actual.promedio, orden) == 1)
            {
                v[j + 1] = v[j]; // corre el elemento a la derecha (que pereza)
                j--;
            }
            else
            {
                break;
            }
        }

        v[j + 1] = actual; // procede a poner el elemento en su lugar
    }

    return comparaciones;
}