#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int *numProductos) {
    int n, i;
    printf("¿Cuántos productos desea ingresar? (máximo %d): ", MAX - *numProductos);
    scanf("%d", &n);
    if (*numProductos + n > MAX) {
        printf("No se pueden ingresar más de %d productos.\n", MAX);
        return;
    }
    for (i = 0; i < n; i++) {
        printf("Nombre del producto %d: ", i + 1);
        scanf("%s", nombres[*numProductos]);

        do {
            printf("Cantidad: ");
            if (scanf("%d", &cantidades[*numProductos]) != 1 || cantidades[*numProductos] <= 0) {
                printf("Error: Ingrese un número válido mayor que cero.\n");
                while (getchar() != '\n');
                cantidades[*numProductos] = -1;
            }
        } while (cantidades[*numProductos] <= 0);

        do {
            printf("Tiempo de fabricación por unidad: ");
            if (scanf("%d", &tiempos[*numProductos]) != 1 || tiempos[*numProductos] <= 0) {
                printf("Error: Ingrese un número válido mayor que cero.\n");
                while (getchar() != '\n');
                tiempos[*numProductos] = -1;
            }
        } while (tiempos[*numProductos] <= 0);

        do {
            printf("Recursos por unidad: ");
            if (scanf("%d", &recursos[*numProductos]) != 1 || recursos[*numProductos] <= 0) {
                printf("Error: Ingrese un número válido mayor que cero.\n");
                while (getchar() != '\n');
                recursos[*numProductos] = -1;
            }
        } while (recursos[*numProductos] <= 0);

        (*numProductos)++;
    }
}

void mostrarProductos(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int numProductos) {
    int i;
    if (numProductos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }
    printf("\n--- LISTA DE PRODUCTOS ---\n");
    for (i = 0; i < numProductos; i++) {
        printf("%d. %s - Cantidad: %d, Tiempo: %d, Recursos: %d\n", i+1, nombres[i], cantidades[i], tiempos[i], recursos[i]);
    }
}

void calcularProduccion(int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int numProductos, int tiempoDisponible, int recursosDisponibles) {
    int tiempoTotal = 0, recursosTotales = 0;
    for (int i = 0; i < numProductos; i++) {
        tiempoTotal += cantidades[i] * tiempos[i];
        recursosTotales += cantidades[i] * recursos[i];
    }
    printf("\nTiempo total requerido: %d\n", tiempoTotal);
    printf("Recursos totales necesarios: %d\n", recursosTotales);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles) {
        printf("La fábrica puede cumplir con la demanda.\n");
    } else {
        printf(" No se puede cumplir con la demanda. Faltan tiempo o recursos.\n");
    }
}

void editarProducto(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int numProductos) {
    char nombreBuscar[30];
    int encontrado = 0;
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("Nuevo nombre: ");
            scanf("%s", nombres[i]);

            do {
                printf("Nueva cantidad: ");
                if (scanf("%d", &cantidades[i]) != 1 || cantidades[i] <= 0) {
                    printf("Error: Ingrese un número válido mayor que cero.\n");
                    while (getchar() != '\n');
                    cantidades[i] = -1;
                }
            } while (cantidades[i] <= 0);

            do {
                printf("Nuevo tiempo por unidad: ");
                if (scanf("%d", &tiempos[i]) != 1 || tiempos[i] <= 0) {
                    printf("Error: Ingrese un número válido mayor que cero.\n");
                    while (getchar() != '\n');
                    tiempos[i] = -1;
                }
            } while (tiempos[i] <= 0);

            do {
                printf("Nuevos recursos por unidad: ");
                if (scanf("%d", &recursos[i]) != 1 || recursos[i] <= 0) {
                    printf("Error: Ingrese un número válido mayor que cero.\n");
                    while (getchar() != '\n');
                    recursos[i] = -1;
                }
            } while (recursos[i] <= 0);

            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int *numProductos) {
    char nombreBuscar[30];
    int i, j, encontrado = 0;
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscar);

    for (i = 0; i < *numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            for (j = i; j < *numProductos - 1; j++) {
                strcpy(nombres[j], nombres[j+1]);
                cantidades[j] = cantidades[j+1];
                tiempos[j] = tiempos[j+1];
                recursos[j] = recursos[j+1];
            }
            (*numProductos)--;
            printf("Producto eliminado correctamente.\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}