#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int m;  // Чисельник
    int n;  // Знаменник

    // Допоміжна функція для скорочення дробу
    void reduce();

public:
    Fraction();  // Конструктор за замовчуванням
    Fraction(int m, int n);  // Конструктор з параметрами

    // Перевантаження арифметичних операторів
    Fraction operator+(const Fraction& other) const;  // Додавання
    Fraction operator-(const Fraction& other) const;  // Віднімання
    Fraction operator*(const Fraction& other) const;  // Множення
    Fraction operator/(const Fraction& other) const;  // Ділення

    // Перевантаження оператора виведення
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    // Геттери для чисельника та знаменника
    int getNumerator() const { return m; }
    int getDenominator() const { return n; }
};

#endif
