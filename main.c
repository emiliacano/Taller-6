#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX][30];
    int cantidades[MAX], tiempos[MAX], recursos[MAX];
    int numProductos = 0;
    int opcion;
    int tiempoDisponible, recursosDisponibles;

    
    do {
        printf("Ingrese tiempo total disponible: ");
        if (scanf("%d", &tiempoDisponible) != 1 || tiempoDisponible <= 0) {
            printf("Error: Ingrese un número válido mayor que cero.\n");
            while (getchar() != '\n');
            tiempoDisponible = -1;
        }
    } while (tiempoDisponible <= 0);

   
    do {
        printf("Ingrese recursos totales disponibles: ");
        if (scanf("%d", &recursosDisponibles) != 1 || recursosDisponibles <= 0) {
            printf("Error: Ingrese un número válido mayor que cero.\n");
            while (getchar() != '\n');
            recursosDisponibles = -1;
        }
    } while (recursosDisponibles <= 0);

    do {
        printf("\n--- MENÚ ---\n");
        printf("1. Ingresar productos\n");
        printf("2. Mostrar productos\n");
        printf("3. Calcular producción\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarProductos(nombres, cantidades, tiempos, recursos, &numProductos);
                break;
            case 2:
                mostrarProductos(nombres, cantidades, tiempos, recursos, numProductos);
                break;
            case 3:
                calcularProduccion(cantidades, tiempos, recursos, numProductos, tiempoDisponible, recursosDisponibles);
                break;
            case 4:
                editarProducto(nombres, cantidades, tiempos, recursos, numProductos);
                break;
            case 5:
                eliminarProducto(nombres, cantidades, tiempos, recursos, &numProductos);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 6);

    return 0;
}