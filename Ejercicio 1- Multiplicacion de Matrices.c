#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Matriz(int matriz[30][30]) {
	int i,j,k;
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicacion(int matriz1[30][30], int matriz2[30][30], int resultado[30][30]) {
    int i,j,k;
	for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < 30; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int i,j,k;
	int matriz1[30][30];
    int matriz2[30][30];
    int resultado[30][30];

    srand(time(NULL));
    for ( i = 0; i < 30; i++) {
        for ( j = 0; j < 30; j++) {
            matriz1[i][j] = rand() % 10;
            matriz2[i][j] = rand() % 10;
        }
    }

    printf("Matriz 1:\n");
    Matriz(matriz1);

    printf("Matriz 2:\n");
    Matriz(matriz2);

    clock_t inicio = clock(); 

    multiplicacion(matriz1, matriz2, resultado);

    printf("Resultado de la multiplicacion:\n");
    Matriz(resultado);

	clock_t fin = clock(); 

    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC ;
    printf("Tiempo de ejecucion: %f segundos\n", tiempo);

    return 0;
}
