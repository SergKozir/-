#include <iostream>
#include "Fraction.h"

// Функція для модифікації масиву дробів
void modifyArray(Fraction arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        arr[i] = arr[i] + arr[i + 1];  // Використовуємо перевантажений оператор +
    }
}

int main() {
    setlocale(LC_ALL, "ukr");

    // Створюємо масив об'єктів Fraction
    const int size = 4;
    Fraction fractions[size] = { Fraction(1, 2), Fraction(2, 3), Fraction(3, 4), Fraction(4, 5) };

    std::cout << "Початковий масив дробів:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << fractions[i] << " ";  // Використовуємо перевантажений оператор <<
    }
    std::cout << "\n";

    // Модифікуємо масив
    modifyArray(fractions, size);

    std::cout << "Масив після зміни:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << fractions[i] << " ";  // Використовуємо перевантажений оператор <<
    }
    std::cout << "\n";

    return 0;
}
