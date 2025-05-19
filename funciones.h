#define MAX 5

void ingresarProductos(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int *numProductos);
void mostrarProductos(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int numProductos);
void calcularProduccion(int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int numProductos, int tiempoDisponible, int recursosDisponibles);
void editarProducto(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int numProductos);
void eliminarProducto(char nombres[MAX][30], int cantidades[MAX], int tiempos[MAX], int recursos[MAX], int *numProductos);