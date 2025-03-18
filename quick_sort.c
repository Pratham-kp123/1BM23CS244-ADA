#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[low], &array[i]);

    return i;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int data[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    printf("Unsorted Array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d  ", data[i]);
    }
    printf("\n");

    clock_t start_time, end_time;


    start_time = clock();

    quickSort(data, 0, n - 1);


    end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted array in ascending order: \n");
    for (int i = 0; i < n; ++i) {
        printf("%d  ", data[i]);
    }
    printf("\n");


    printf("Time taken to sort the array: %f seconds\n", time_taken);

    return 0;
}
