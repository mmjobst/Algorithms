#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortedArray(int size, int** originalArray);
void swap(int* a, int* b);
void randomList(int size, int* originalArray, int* randomArray);
void inversions(int size, int* array);

void sortedArray(int size, int** originalArray) {
    *originalArray = (int*)malloc(size * sizeof(int));
    printf("The sorted list is: ");
    for (int i = 0; i < size; i++) {
        (*originalArray)[i] = i + 1;
        printf("%d ", (*originalArray)[i]);
    }
}

void swap(int* a, int* b) {
    int temporary = *a;
    *a = *b;
    *b = temporary;
}

void randomList(int size, int* originalArray, int* randomArray) {
    randomArray = (int*)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = i + rand() / (RAND_MAX / (size - i) + 1);
        swap(&originalArray[i], &originalArray[j]);
        randomArray[i] = originalArray[i];
        printf("%d ", randomArray[i]);
    }
    free(randomArray);
}

void inversions(int size, int* array) {
    int numberOfInversions = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (array[i] > array[j] && i < j) {
                count++;
            }
        }
        printf("%i ", count);
        numberOfInversions += count;
    }
    printf("\nThe number of inversions are: %d", numberOfInversions);
}

int main() {
    int size;
    int* originalArray;
    int* randomArray;
    printf("Enter the length of the array: ");
    scanf("%i", &size);
    sortedArray(size, &originalArray);
    printf("\nThe random list is: ");
    randomList(size, originalArray, randomArray);
    printf("\nList of inversions: ");
    inversions(size, originalArray);
    free(originalArray);
    free(randomArray);
    return 0;
}
