#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int n, m, i, j;
    printf("Введіть кількість рядків (n): ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців (m): ");
    scanf("%d", &m);
    double A[n][m];
    srand(time(NULL));
    printf("\nПочаткова матриця:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            // Генеруємо дійсні числа від -100 до 100
            A[i][j] = (rand() % 20001 - 10000) / 100.0;
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }
    double maxSum;
    int maxIdx = 0;
    for (j = 0; j < m; j++) {
        double currentSum = 0;
        for (i = 0; i < n; i++) {
            currentSum += A[i][j];
        }
        printf("Сума стовпця %d: %.2f\n", j, currentSum);
        if (j == 0 || currentSum > maxSum) {
            maxSum = currentSum;
            maxIdx = j;
        }
    }
    printf("\nВилучаємо стовпець №%d (сума: %.2f)\n", maxIdx, maxSum);
    for (i = 0; i < n; i++) {
        for (j = maxIdx; j < m - 1; j++) {
            A[i][j] = A[i][j + 1];
        }
    }
    printf("\nМатриця після вилучення стовпця:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}