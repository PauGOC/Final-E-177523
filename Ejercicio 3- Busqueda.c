//Ejercicio 3: Búsqueda Secuencial y Binaria
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANO 50000
#define EJECUCIONES 100
#define REPETICIONES 1000

void generarArregloOrdenado(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
}

int busquedaSecuencial(int arr[], int n, int clave) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == clave) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int arr[], int izquierda, int derecha, int clave) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == clave) {
            return medio;
        }
        if (arr[medio] < clave) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

void imprimirEstadisticas(double tiempos[], int n) {
    double total = 0.0, min = tiempos[0], max = tiempos[0];
    int i;
    
    printf("Todos los tiempos de ejecución:\n");
    for (i = 0; i < n; i++) {
        printf("Tiempo %d) %f\n ", i+1,tiempos[i]);
        total += tiempos[i];
        if (tiempos[i] < min) min = tiempos[i];
        if (tiempos[i] > max) max = tiempos[i];
    }
    printf("\n\n");
    printf("Tiempo Promedio: %f ms\n", total / n);
    printf("Tiempo Minimo: %f ms\n", min);
    printf("Tiempo Maximo: %f ms\n", max);
}

int main() {
    int arr[TAMANO];
    int i, j;
    
    double tiemposSecuencial[EJECUCIONES], tiemposBinario[EJECUCIONES];
    clock_t inicio, fin;

    srand(time(NULL));
    generarArregloOrdenado(arr, TAMANO);

    printf("Busqueda Secuencial:\n");
    
    for (i = 0; i < EJECUCIONES; i++) {
        int clave = rand() % TAMANO;
        inicio = clock();
        
        for (j = 0; j < REPETICIONES; j++) {
            busquedaSecuencial(arr, TAMANO, clave);
        }
        
        fin = clock();
        tiemposSecuencial[i] = ((double)(fin - inicio)) / CLOCKS_PER_SEC / REPETICIONES * 1000;
    }
    
    imprimirEstadisticas(tiemposSecuencial, EJECUCIONES);

    printf("\nBusqueda Binaria:\n");
    
    for (i = 0; i < EJECUCIONES; i++) {
        int clave = rand() % TAMANO;
        inicio = clock();
        
        for (j = 0; j < REPETICIONES; j++) {
            busquedaBinaria(arr, 0, TAMANO - 1, clave);
        }
        
        fin = clock();
        tiemposBinario[i] = ((double)(fin - inicio)) / CLOCKS_PER_SEC / REPETICIONES * 1000;
    }
    
    imprimirEstadisticas(tiemposBinario, EJECUCIONES);

    return 0;
}

