#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include "competidor.h"

#define ASCENDENTE 1  // de menor a mayor
#define DESCENDENTE 0 // de mayor a menor

// Los tres ordenan por el promedio y devuelven cuantas comparaciones hicieron , ademas aqui es donde se guarda el tipo de ordenamiento
long bubble_sort(Competidor *v, int n, int orden);
long selection_sort(Competidor *v, int n, int orden);
long insertion_sort(Competidor *v, int n, int orden);

#endif