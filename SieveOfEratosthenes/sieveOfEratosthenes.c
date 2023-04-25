#include <stdio.h>
#include <stdlib.h>

void sieveOfEratosthenes(int inputNumber);


void sieveOfEratosthenes(int inputNumber) {
    int i, j;
    int primes[inputNumber + 1];

    // populating the array with natural numbers
    for (i = 2; i <= inputNumber; i++) {
        primes[i] = i;
    }

    i = 2;

    // performing sieve of eratosthenes algorithm
    while ((i * i) <= inputNumber) {
        if (primes[i] != 0) {
            for (j = 2; j <= inputNumber; j++) {
                if (primes[i] * j > inputNumber) {
                    break;
                } else {
                    primes[primes[i] * j] = 0;
                }
            }
        }
        i++;
    }

    // printing the prime numbers
    printf("Prime numbers between 2 and %d are: ", inputNumber);
    for (i = 2; i <= inputNumber; i++) {
        if (primes[i] != 0) {
            printf("%d ", primes[i]);
        }
    }
}

int main() {
    int inputNumber;

    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    sieveOfEratosthenes(inputNumber);

    return 0;
}
