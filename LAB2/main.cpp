#include <iostream>
#include "Book.h"

int main() {
    setlocale(LC_ALL, "ukr");

    // 1. ��������� ��'���� �� ��������� ������������ �� �������������
    Book defaultBook;
    std::cout << "����� ����� �� �������������: " << defaultBook.getTitle() << std::endl;
    std::cout << "����� ����� �� �������������: " << defaultBook.getAuthor() << std::endl;
    std::cout << "г� ������� �� �������������: " << defaultBook.getYear() << std::endl;

    // 2. ��������� ��'���� �� ��������� ������������ � �����������
    Book paramBook("1984", "George Orwell", 1949);
    std::cout << "����� �����: " << paramBook.getTitle() << std::endl;
    std::cout << "����� �����: " << paramBook.getAuthor() << std::endl;
    std::cout << "г� �������: " << paramBook.getYear() << std::endl;

    // 3. ��������� ��'���� �� ��������� ��������� ������������
    Book copyBook(paramBook);
    std::cout << "����� ���������� �����: " << copyBook.getTitle() << std::endl;
    std::cout << "����� ���������� �����: " << copyBook.getAuthor() << std::endl;
    std::cout << "г� ������� ���������� �����: " << copyBook.getYear() << std::endl;

    // ���������� ��������, ����������� ���������� �����������
    return 0;
}
