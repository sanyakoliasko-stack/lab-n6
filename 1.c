#include <stdio.h>
int main() {
    int n, m, i, j;
    // Введення розмірності матриці
    printf("Введіть кількість рядків (n): ");
    scanf("%d", &n);
    printf("Введіть кількість стовпців (m): ");
    scanf("%d", &m);
    int A[n][m];
    printf("Введіть елементи матриці %dx%d:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    int max = A[0][0];
    int min = A[0][0];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
            }
            if (A[i][j] < min) {
                min = A[i][j];
            }
        }
    }
    double avg = (max + min) / 2.0;
    printf("\nМаксимальний елемент: %d\n", max);
    printf("Мінімальний елемент: %d\n", min);
    printf("Середнє арифметичне (max+min)/2: %.2f\n", avg);
    return 0;
}