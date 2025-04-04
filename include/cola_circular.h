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

ColaCircular* cola_crear() {
    ColaCircular* cola = malloc(sizeof(ColaCircular));
    cola->frente = cola->final = 0;
    return cola;
}

bool cola_vacia(ColaCircular* cola) {
    return cola->frente == cola->final;
}

bool cola_llena(ColaCircular* cola) {
    return (cola->final + 1) % CAPACIDAD_COLA == cola->frente;
}

bool cola_encolar(ColaCircular* cola, int valor) {
    if (cola_llena(cola)) return false;
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % CAPACIDAD_COLA;
    return true;
}

bool cola_desencolar(ColaCircular* cola, int* valor) {
    if (cola_vacia(cola)) return false;
    *valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % CAPACIDAD_COLA;
    return true;
}

void cola_destruir(ColaCircular* cola) {
    free(cola);
}

void cola_generica_destruir(ColaGenerica* cola) {
    free(cola);
}
