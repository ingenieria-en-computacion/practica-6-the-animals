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

// Crea una nueva cola genérica
ColaGenerica* cola_generica_crear() {
    ColaGenerica* cola = malloc(sizeof(ColaGenerica));
    if (cola) {
        cola->frente = cola->final = 0;
    }
    return cola;
}

// Verifica si la cola está vacía
bool cola_generica_vacia(ColaGenerica* cola) {
    return cola->frente == cola->final;
}

// Verifica si la cola está llena
bool cola_generica_llena(ColaGenerica* cola) {
    return (cola->final + 1) % CAPACIDAD_COLA == cola->frente;
}

// Encola un valor en la cola genérica
bool cola_generica_encolar(ColaGenerica* cola, void* valor) {
    if (cola_generica_llena(cola)) return false;
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % CAPACIDAD_COLA;
    return true;
}

// Desencola un valor de la cola genérica
bool cola_generica_desencolar(ColaGenerica* cola, void** valor) {
    if (cola_generica_vacia(cola)) return false;
    *valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % CAPACIDAD_COLA;
    return true;
}

// Destruye la cola genérica y libera la memoria
void cola_generica_destruir(ColaGenerica* cola) {
    free(cola);
}
