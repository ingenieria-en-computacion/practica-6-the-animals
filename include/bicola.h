#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define CAPACIDAD_BICOLA 100

typedef struct {
    int datos[CAPACIDAD_BICOLA];
    int frente;
    int final;
} Bicola;

Bicola* bicola_crear() {
    Bicola* bicola = malloc(sizeof(Bicola));
    bicola->frente = bicola->final = CAPACIDAD_BICOLA / 2; 
    return bicola;
}

bool bicola_vacia(Bicola* bicola) {
    return bicola->frente == bicola->final;
}

bool bicola_llena(Bicola* bicola) {
    return (bicola->final + 1) % CAPACIDAD_BICOLA == bicola->frente;
}

bool bicola_agregar_frente(Bicola* bicola, int valor) {
    if (bicola_llena(bicola)) return false;
    bicola->datos[--bicola->frente] = valor;
    return true;
}

bool bicola_agregar_final(Bicola* bicola, int valor) {
    if (bicola_llena(bicola)) return false;
    bicola->datos[bicola->final++] = valor;
    bicola->final %= CAPACIDAD_BICOLA;
    return true;
}

bool bicola_eliminar_frente(Bicola* bicola, int* valor) {
    if (bicola_vacia(bicola)) return false;
    *valor = bicola->datos[bicola->frente++];
    bicola->frente %= CAPACIDAD_BICOLA;
    return true;
}

bool bicola_eliminar_final(Bicola* bicola, int* valor) {
    if (bicola_vacia(bicola)) return false;
    *valor = bicola->datos[--bicola->final];
    return true;
}

void bicola_destruir(Bicola* bicola) {
    free(bicola);
}
