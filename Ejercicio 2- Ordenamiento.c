//Ejercicio 2: Tiempos y Estadísticas de los Tipos de Ordenamientos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1), j;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    int n = 10000;
    int arr[n];
    int i, j;

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    double start_time, end_time;
    double elapsed_time[100];
    int temp_arr[n];

    printf("Insertion Sort\n");
    for (i = 0; i < 100; i++) {
        for (j = 0; j < n; j++) {
            temp_arr[j] = arr[j];
        }
        start_time = clock();
        insertion(temp_arr, n);
        end_time = clock();
        elapsed_time[i] = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
        printf("Tiempo %d) %lf ms\n", i + 1, elapsed_time[i]);
    }

    double avg_time = 0, min_time = elapsed_time[0], max_time = elapsed_time[0];
    for (i = 0; i < 100; i++) {
        avg_time += elapsed_time[i];
        if (elapsed_time[i] < min_time)
            min_time = elapsed_time[i];
        if (elapsed_time[i] > max_time)
            max_time = elapsed_time[i];
    }
    avg_time /= 100;
    printf ("\n--------------------------------\n");
    
    
    printf("\nEstadísticas Insertion Sort:\n");
    printf("Tiempo promedio: %lf ms\n", avg_time);
    printf("Tiempo mínimo: %lf ms\n", min_time);
    printf("Tiempo máximo: %lf ms\n\n", max_time);

    printf("Quick Sort\n");
    for (i = 0; i < 100; i++) {
        for (j = 0; j < n; j++) {
            temp_arr[j] = arr[j];
        }
        start_time = clock();
        quickSort(temp_arr, 0, n - 1);
        end_time = clock();
        elapsed_time[i] = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
        printf("Tiempo %d) %lf ms\n", i + 1, elapsed_time[i]);
    }

    avg_time = 0, min_time = elapsed_time[0], max_time = elapsed_time[0];
    for (i = 0; i < 100; i++) {
        avg_time += elapsed_time[i];
        if (elapsed_time[i] < min_time)
            min_time = elapsed_time[i];
        if (elapsed_time[i] > max_time)
            max_time = elapsed_time[i];
    }
    avg_time /= 100;
    printf ("\n--------------------------------\n");
    
    
    printf("\nEstadísticas Quick Sort:\n");
    printf("Tiempo promedio: %lf ms\n", avg_time);
    printf("Tiempo mínimo: %lf ms\n", min_time);
    printf("Tiempo máximo: %lf ms\n\n", max_time);

    printf("Bubble Sort\n");
    for (i = 0; i < 100; i++) {
        for (j = 0; j < n; j++) {
            temp_arr[j] = arr[j];
        }
        start_time = clock();
        bubbleSort(temp_arr, n);
        end_time = clock();
        elapsed_time[i] = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
        printf("Tiempo %d) %lf ms\n", i + 1, elapsed_time[i]);
    }

    avg_time = 0, min_time = elapsed_time[0], max_time = elapsed_time[0];
    for (i = 0; i < 100; i++) {
        avg_time += elapsed_time[i];
        if (elapsed_time[i] < min_time)
            min_time = elapsed_time[i];
        if (elapsed_time[i] > max_time)
            max_time = elapsed_time[i];
    }
    avg_time /= 100;
    printf ("\n--------------------------------\n");
    
    printf("\nEstadísticas Bubble Sort:\n");
    printf("Tiempo promedio: %lf ms\n", avg_time);
    printf("Tiempo mínimo: %lf ms\n", min_time);
    printf("Tiempo máximo: %lf ms\n", max_time);

    return 0;
}

