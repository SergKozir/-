// main.cpp
#include <iostream>
#include "Book.h"

int main() {
    setlocale(LC_ALL, "ukr");
    // Створення об'єкта класу Book
    Book myBook;

    // Задання значень полів
    myBook.setTitle("The Great Gatsby");
    myBook.setAuthor("F. Scott Fitzgerald");
    myBook.setYear(1925);

    // Виведення інформації про книгу
    std::cout << "Назва книги: " << myBook.getTitle() << std::endl;
    std::cout << "Автор книги: " << myBook.getAuthor() << std::endl;
    std::cout << "Рік видання: " << myBook.getYear() << std::endl;

    return 0;
}
