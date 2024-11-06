#include "Fraction.h"
#include <iostream>

// Реалізація функції для знаходження НСД (алгоритм Евкліда)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Конструктор за замовчуванням
Fraction::Fraction() : m(0), n(1) {}

// Конструктор з параметрами
Fraction::Fraction(int m, int n) : m(m), n(n) {
    if (n == 0) {
        std::cerr << "Помилка: знаменник не може бути нульовим.\n";
        exit(1);
    }
    reduce();  // Скорочуємо дріб при створенні
}

// Функція для скорочення дробу
void Fraction::reduce() {
    int divisor = gcd(m, n);
    m /= divisor;
    n /= divisor;

    if (n < 0) {  // Якщо знаменник від’ємний, переносимо знак до чисельника
        m = -m;
        n = -n;
    }
}

// Перевантаження оператора додавання
Fraction Fraction::operator+(const Fraction& other) const {
    int num = m * other.n + other.m * n;
    int denom = n * other.n;
    return Fraction(num, denom);
}

// Перевантаження оператора віднімання
Fraction Fraction::operator-(const Fraction& other) const {
    int num = m * other.n - other.m * n;
    int denom = n * other.n;
    return Fraction(num, denom);
}

// Перевантаження оператора множення
Fraction Fraction::operator*(const Fraction& other) const {
    int num = m * other.m;
    int denom = n * other.n;
    return Fraction(num, denom);
}

// Перевантаження оператора ділення
Fraction Fraction::operator/(const Fraction& other) const {
    int num = m * other.n;
    int denom = n * other.m;
    if (denom == 0) {
        std::cerr << "Помилка: ділення на нуль.\n";
        exit(1);
    }
    return Fraction(num, denom);
}

// Перевантаження оператора виведення
std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.m << "/" << fraction.n;
    return out;
}
