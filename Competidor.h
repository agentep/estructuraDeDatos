#ifndef COMPETIDOR_H
#define COMPETIDOR_H

#define MAX_NOMBRE 32

// Estructura donde se guardan los datos de cada competidor(mirame mama, soy un comentario de una sola linea)
typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    float *puntajes; // arreglo dinamico de puntajes
    int n_puntajes;  // cuantos puntajes hay
    float promedio;
} Competidor;

// pide memoria para los puntajes, devuelve 1 si pudo y 0 si no
int crear_competidor(Competidor *c, int id, const char *nombre, int n_puntajes);

// libera la memoria de los puntajes
void liberar_competidor(Competidor *c);

// calcula el promedio y lo guarda en el competidor
void calcular_promedio(Competidor *c);

// cambia de lugar dos competidores
void intercambiar(Competidor *a, Competidor *b);

// muestra un competidor
void imprimir_competidor(const Competidor *c);

// muestra la tabla de todos los competidores
void imprimir_tabla(const Competidor *v, int n);

#endif