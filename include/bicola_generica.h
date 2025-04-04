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

BicolaGenerica* bicola_generica_crear() {
    BicolaGenerica* bicola = malloc(sizeof(BicolaGenerica));
    bicola->frente = bicola->final = CAPACIDAD_BICOLA / 2; 
    return bicola;
}

bool bicola_generica_vacia(BicolaGenerica* bicola) {
    return bicola->frente == bicola->final;
}

bool bicola_generica_llena(BicolaGenerica* bicola) {
    return (bicola->final + 1) % CAPACIDAD_BICOLA == bicola->frente;
}

bool bicola_generica_agregar_frente(BicolaGenerica* bicola, void* valor) {
    if (bicola_generica_llena(bicola)) return false;
    bicola->datos[--bicola->frente] = valor;
    return true;
}

bool bicola_generica_agregar_final(BicolaGenerica* bicola, void* valor) {
    if (bicola_generica_llena(bicola)) return false;
    bicola->datos[bicola->final++] = valor;
    bicola->final %= CAPACIDAD_BICOLA;
    return true;
}

bool bicola_generica_eliminar_frente(BicolaGenerica* bicola, void** valor) {
    if (bicola_generica_vacia(bicola)) return false;
    *valor = bicola->datos[bicola->frente++];
    bicola->frente %= CAPACIDAD_BICOLA;
    return true;
}

bool bicola_generica_eliminar_final(BicolaGenerica* bicola, void** valor) {
    if (bicola_generica_vacia(bicola)) return false;
    *valor = bicola->datos[--bicola->final];
    return true;
}

void bicola_generica_destruir(BicolaGenerica* bicola) {
    free(bicola);
}
