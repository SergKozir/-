#include <iostream>
#include "Fraction.h"

// ������� ��� ����������� ������ �����
void modifyArray(Fraction arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        arr[i] = arr[i] + arr[i + 1];  // ������������� �������������� �������� +
    }
}

int main() {
    setlocale(LC_ALL, "ukr");

    // ��������� ����� ��'���� Fraction
    const int size = 4;
    Fraction fractions[size] = { Fraction(1, 2), Fraction(2, 3), Fraction(3, 4), Fraction(4, 5) };

    std::cout << "���������� ����� �����:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << fractions[i] << " ";  // ������������� �������������� �������� <<
    }
    std::cout << "\n";

    // ���������� �����
    modifyArray(fractions, size);

    std::cout << "����� ���� ����:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << fractions[i] << " ";  // ������������� �������������� �������� <<
    }
    std::cout << "\n";

    return 0;
}
