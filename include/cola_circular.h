#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDAD_COLA 100

typedef struct {
    void* datos[CAPACIDAD_COLA];
    int frente;
    int final;
} ColaGenerica;

ColaGenerica* cola_generica_crear() {
    ColaGenerica* cola = malloc(sizeof(ColaGenerica));
    cola->frente = cola->final = 0;
    return cola;
}

bool cola_generica_vacia(ColaGenerica* cola) {
    return cola->frente == cola->final;
}

bool cola_generica_llena(ColaGenerica* cola) {
    return (cola->final + 1) % CAPACIDAD_COLA == cola->frente;
}

bool cola_generica_encolar(ColaGenerica* cola, void* valor) {
    if (cola_generica_llena(cola)) return false;
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % CAPACIDAD_COLA;
    return true;
}

bool cola_generica_desencolar(ColaGenerica* cola, void** valor) {
    if (cola_generica_vacia(cola)) return false;
    *valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % CAPACIDAD_COLA;
    return true;
}

void cola_generica_destruir(ColaGenerica* cola) {
    free(cola);
}
