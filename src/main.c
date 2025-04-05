#include <stdio.h>
#include "cola_circular.h"
#include "bicola.h"

int main() {
    ColaCircular cola;
    cola_crear(&cola);
    printf("Prueba de Cola Circular (Arreglo):\n");
    printf("Creando cola circular...\n");
    
    // Encolar elementos
    printf("Encolando elementos: 1 y 2\n");
    cola_encolar(&cola, 1);
    cola_encolar(&cola, 2);
    
    // Desencolar y mostrar
    printf("Elemento desencolado: %d\n", cola_desencolar(&cola));

    Bicola bi;
    bicola_crear(&bi);
    printf("\nPrueba de Bicola (Arreglo):\n");
    printf("Creando bicola...\n");
    
    // Agregar elementos a la bicola
    printf("Agregando al frente: 10\n");
    bicola_agregar_frente(&bi, 10);
    printf("Agregando al final: 20\n");
    bicola_agregar_final(&bi, 20);
    
    // Eliminar y mostrar
    printf("Elemento eliminado del frente: %d\n", bicola_eliminar_frente(&bi));
    
    return 0;
}
