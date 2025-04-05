#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDAD_COLA 100

typedef struct {
    int datos[CAPACIDAD_COLA];
    int frente;
    int final;
} ColaCircular;

// Crea una nueva cola circular
ColaCircular* cola_crear() {
    ColaCircular* cola = malloc(sizeof(ColaCircular));
    if (cola) {
        cola->frente = cola->final = 0;
    }
    return cola;
}

// Verifica si la cola está vacía
bool cola_vacia(ColaCircular* cola) {
    return cola->frente == cola->final;
}

// Verifica si la cola está llena
bool cola_llena(ColaCircular* cola) {
    return (cola->final + 1) % CAPACIDAD_COLA == cola->frente;
}

// Encola un valor en la cola circular
bool cola_encolar(ColaCircular* cola, int valor) {
    if (cola_llena(cola)) return false;
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % CAPACIDAD_COLA;
    return true;
}

// Desencola un valor de la cola circular
bool cola_desencolar(ColaCircular* cola, int* valor) {
    if (cola_vacia(cola)) return false;
    *valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % CAPACIDAD_COLA;
    return true;
}

// Destruye la cola circular y libera la memoria
void cola_destruir(ColaCircular* cola) {
    free(cola);
}
