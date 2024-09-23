#include <iostream>
#include "Book.h"

int main() {
    setlocale(LC_ALL, "ukr");

    // 1. Створення об'єкта за допомогою конструктора за замовчуванням
    Book defaultBook;
    std::cout << "Назва книги за замовчуванням: " << defaultBook.getTitle() << std::endl;
    std::cout << "Автор книги за замовчуванням: " << defaultBook.getAuthor() << std::endl;
    std::cout << "Рік видання за замовчуванням: " << defaultBook.getYear() << std::endl;

    // 2. Створення об'єкта за допомогою конструктора з параметрами
    Book paramBook("1984", "George Orwell", 1949);
    std::cout << "Назва книги: " << paramBook.getTitle() << std::endl;
    std::cout << "Автор книги: " << paramBook.getAuthor() << std::endl;
    std::cout << "Рік видання: " << paramBook.getYear() << std::endl;

    // 3. Створення об'єкта за допомогою копіюючого конструктора
    Book copyBook(paramBook);
    std::cout << "Назва скопійованої книги: " << copyBook.getTitle() << std::endl;
    std::cout << "Автор скопійованої книги: " << copyBook.getAuthor() << std::endl;
    std::cout << "Рік видання скопійованої книги: " << copyBook.getYear() << std::endl;

    // Завершення програми, автоматичне викликання деструкторів
    return 0;
}
