#include <stdio.h>
#include <stdlib.h>

void primeFactors(int n, int **factors, int *size) {
    *size = 0;
    *factors = (int *)malloc(sizeof(int) * n); // Allocate memory for factors

    while (n % 2 == 0) {
        (*factors)[(*size)++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            (*factors)[(*size)++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        (*factors)[(*size)++] = n;
    }
}

int main() {
    int n;
    printf("Type a number and press enter: \n");
    scanf("%d", &n);

    int *factors = NULL;
    int size = 0;

    primeFactors(n, &factors, &size);

    printf("%d = ", n);
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            printf(" * ");
        }
        printf("%d", factors[i]);
    }
    printf("\n");

    free(factors);
    return 0;
}