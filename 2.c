#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    // 1. Введення розмірів матриці
    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    double A[rows][cols]; // Оголошення матриці дійсних чисел

    // 2. Заповнення матриці випадковими числами від -100 до 100
    printf("\nПочаткова матриця:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Генеруємо дійсне число: (випадкове число) / (макс_рандом) * діапазон + мінімум
            A[i][j] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
            printf("%8.2f ", A[i][j]); // Вивід з точністю 2 знаки
        }
        printf("\n");
    }

    // 3. Пошук стовпця з найбільшою сумою
    double maxSum;
    int maxColIndex = 0;

    for (int j = 0; j < cols; j++) { // Йдемо по стовпцях
        double currentSum = 0;
        for (int i = 0; i < rows; i++) { // Додаємо всі елементи у стовпці
            currentSum += A[i][j];
        }

        // Якщо це перший стовпець або його сума більша за попередню максимальну
        if (j == 0 || currentSum > maxSum) {
            maxSum = currentSum;
            maxColIndex = j;
        }
    }

    printf("\nСтовпець для видалення: %d (Сума: %.2f)\n", maxColIndex, maxSum);

    // 4. Виведення матриці БЕЗ цього стовпця (фактичне вилучення при виводі)
    printf("\nМатриця після вилучення стовпця:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == maxColIndex) continue; // Пропускаємо стовпець, який треба видалити
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}