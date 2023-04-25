#include <stdio.h>
#include <stdlib.h>

void inputArray(int *arr, int sizeOfArr);
void printArray(int *arr, int sizeOfArr);
void swapArray(int *sourceArr, int *destArr, int size);

#define MAX_SIZE 100


void inputArray(int *arr, int sizeOfArr)
{
    int *arrEnd = (arr + (sizeOfArr - 1));
    while(arr <= arrEnd)
        scanf("%d", arr++);
}


void printArray(int *arr, int sizeOfArr)
{
    int *arrEnd = (arr + (sizeOfArr - 1));
    while(arr <= arrEnd)
        printf("%d, ", *(arr++));
}


void swapArray(int * sourceArr, int * destArr, int sizeOfArr)
{
    int * sourceArrEnd = (sourceArr + (sizeOfArr - 1));
    int * destArrEnd   = (destArr + (sizeOfArr - 1));

    while(sourceArr <= sourceArrEnd && destArr <= destArrEnd)
    {
        *sourceArr ^= *destArr;
        *destArr   ^= *sourceArr;
        *sourceArr ^= *destArr;

        sourceArr++;
        destArr++;
    }
}

int main()
{
    int sourceArr[MAX_SIZE];
    int destArr[MAX_SIZE];
    int sizeOfArr;

    printf("Enter size of array: ");
    scanf("%d", &sizeOfArr);

    printf("Enter %d elements in source array: ", sizeOfArr);
    inputArray(sourceArr, sizeOfArr);

    printf("Enter %d elements in destination array: ", sizeOfArr);
    inputArray(destArr, sizeOfArr);


    printf("\n\nSource array before swapping: ");
    printArray(sourceArr, sizeOfArr);

    printf("\nDestination array before swapping: ");
    printArray(destArr, sizeOfArr);

    swapArray(sourceArr, destArr, sizeOfArr);

    printf("\n\nSource array after swapping: ");
    printArray(sourceArr, sizeOfArr);

    printf("\nDestination array after swapping: ");
    printArray(destArr, sizeOfArr);

    return 0;
}



