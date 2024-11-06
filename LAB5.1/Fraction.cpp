#include "Fraction.h"
#include <iostream>

// ��������� ������� ��� ����������� ��� (�������� ������)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ����������� �� �������������
Fraction::Fraction() : m(0), n(1) {}

// ����������� � �����������
Fraction::Fraction(int m, int n) : m(m), n(n) {
    if (n == 0) {
        std::cerr << "�������: ��������� �� ���� ���� ��������.\n";
        exit(1);
    }
    reduce();  // ��������� ��� ��� ��������
}

// ������� ��� ���������� �����
void Fraction::reduce() {
    int divisor = gcd(m, n);
    m /= divisor;
    n /= divisor;

    if (n < 0) {  // ���� ��������� �䒺����, ���������� ���� �� ����������
        m = -m;
        n = -n;
    }
}

// �������������� ��������� ���������
Fraction Fraction::operator+(const Fraction& other) const {
    int num = m * other.n + other.m * n;
    int denom = n * other.n;
    return Fraction(num, denom);
}

// �������������� ��������� ��������
Fraction Fraction::operator-(const Fraction& other) const {
    int num = m * other.n - other.m * n;
    int denom = n * other.n;
    return Fraction(num, denom);
}

// �������������� ��������� ��������
Fraction Fraction::operator*(const Fraction& other) const {
    int num = m * other.m;
    int denom = n * other.n;
    return Fraction(num, denom);
}

// �������������� ��������� ������
Fraction Fraction::operator/(const Fraction& other) const {
    int num = m * other.n;
    int denom = n * other.m;
    if (denom == 0) {
        std::cerr << "�������: ������ �� ����.\n";
        exit(1);
    }
    return Fraction(num, denom);
}

// �������������� ��������� ���������
std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.m << "/" << fraction.n;
    return out;
}
