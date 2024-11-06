#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int m;  // ���������
    int n;  // ���������

    // �������� ������� ��� ���������� �����
    void reduce();

public:
    Fraction();  // ����������� �� �������������
    Fraction(int m, int n);  // ����������� � �����������

    // �������������� ������������ ���������
    Fraction operator+(const Fraction& other) const;  // ���������
    Fraction operator-(const Fraction& other) const;  // ³�������
    Fraction operator*(const Fraction& other) const;  // ��������
    Fraction operator/(const Fraction& other) const;  // ĳ�����

    // �������������� ��������� ���������
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    // ������� ��� ���������� �� ����������
    int getNumerator() const { return m; }
    int getDenominator() const { return n; }
};

#endif
