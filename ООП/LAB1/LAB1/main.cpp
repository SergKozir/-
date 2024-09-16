// main.cpp
#include <iostream>
#include "Book.h"

int main() {
    setlocale(LC_ALL, "ukr");
    // ��������� ��'���� ����� Book
    Book myBook;

    // ������� ������� ����
    myBook.setTitle("The Great Gatsby");
    myBook.setAuthor("F. Scott Fitzgerald");
    myBook.setYear(1925);

    // ��������� ���������� ��� �����
    std::cout << "����� �����: " << myBook.getTitle() << std::endl;
    std::cout << "����� �����: " << myBook.getAuthor() << std::endl;
    std::cout << "г� �������: " << myBook.getYear() << std::endl;

    return 0;
}
