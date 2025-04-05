#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDAD_BICOLA 100

typedef struct {
    void* datos[CAPACIDAD_BICOLA];
    int frente;
    int final;
} BicolaGenerica;

// Crea una nueva bi-cola genérica
BicolaGenerica* bicola_generica_crear() {
    BicolaGenerica* bicola = malloc(sizeof(BicolaGenerica));
    if (bicola) {
        bicola->frente = CAPACIDAD_BICOLA / 2; 
        bicola->final = bicola->frente;
    }
    return bicola;
}

// Verifica si la bi-cola está vacía
bool bicola_generica_vacia(BicolaGenerica* bicola) {
    return bicola->frente == bicola->final;
}

// Verifica si la bi-cola está llena
bool bicola_generica_llena(BicolaGenerica* bicola) {
    return (bicola->final + 1) % CAPACIDAD_BICOLA == bicola->frente;
}

// Agrega un valor al frente de la bi-cola
bool bicola_generica_agregar_frente(BicolaGenerica* bicola, void* valor) {
    if (bicola_generica_llena(bicola)) return false;
    bicola->datos[--bicola->frente] = valor;
    return true;
}

// Agrega un valor al final de la bi-cola
bool bicola_generica_agregar_final(BicolaGenerica* bicola, void* valor) {
    if (bicola_generica_llena(bicola)) return false;
    bicola->datos[bicola->final] = valor;
    bicola->final = (bicola->final + 1) % CAPACIDAD_BICOLA;
    return true;
}

// Elimina un valor del frente de la bi-cola
bool bicola_generica_eliminar_frente(BicolaGenerica* bicola, void** valor) {
    if (bicola_generica_vacia(bicola)) return false;
    *valor = bicola->datos[bicola->frente++];
    bicola->frente %= CAPACIDAD_BICOLA;
    return true;
}

// Elimina un valor del final de la bi-cola
bool bicola_generica_eliminar_final(BicolaGenerica* bicola, void** valor) {
    if (bicola_generica_vacia(bicola)) return false;
    bicola->final = (bicola->final - 1 + CAPACIDAD_BICOLA) % CAPACIDAD_BICOLA; 
    *valor = bicola->datos[bicola->final];
    return true;
}

// Destruye la bi-cola genérica y libera la memoria
void bicola_generica_destruir(BicolaGenerica* bicola) {
    free(bicola);
}
