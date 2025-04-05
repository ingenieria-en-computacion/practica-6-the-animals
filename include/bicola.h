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

// Crea una nueva bi-cola
Bicola* bicola_crear() {
    Bicola* bicola = malloc(sizeof(Bicola));
    if (bicola) {
        bicola->frente = CAPACIDAD_BICOLA / 2; 
        bicola->final = bicola->frente; 
    }
    return bicola;
}

// Verifica si la bi-cola está vacía
bool bicola_vacia(Bicola* bicola) {
    return bicola->frente == bicola->final;
}

// Verifica si la bi-cola está llena
bool bicola_llena(Bicola* bicola) {
    return (bicola->final + 1) % CAPACIDAD_BICOLA == bicola->frente;
}

// Agrega un valor al frente de la bi-cola
bool bicola_agregar_frente(Bicola* bicola, int valor) {
    if (bicola_llena(bicola)) return false;
    bicola->datos[--bicola->frente] = valor;
    return true;
}

// Agrega un valor al final de la bi-cola
bool bicola_agregar_final(Bicola* bicola, int valor) {
    if (bicola_llena(bicola)) return false;
    bicola->datos[bicola->final] = valor;
    bicola->final = (bicola->final + 1) % CAPACIDAD_BICOLA;
    return true;
}

// Elimina un valor del frente de la bi-cola
bool bicola_eliminar_frente(Bicola* bicola, int* valor) {
    if (bicola_vacia(bicola)) return false;
    *valor = bicola->datos[bicola->frente++];
    bicola->frente %= CAPACIDAD_BICOLA;
    return true;
}

// Elimina un valor del final de la bi-cola
bool bicola_eliminar_final(Bicola* bicola, int* valor) {
    if (bicola_vacia(bicola)) return false;
    bicola->final = (bicola->final - 1 + CAPACIDAD_BICOLA) % CAPACIDAD_BICOLA; 
    *valor = bicola->datos[bicola->final];
    return true;
}

// Destruye la bi-cola y libera la memoria
void bicola_destruir(Bicola* bicola) {
    free(bicola);
}
}
