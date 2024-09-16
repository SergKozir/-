#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
};

// Функції для роботи зі структурою
void setTitle(Book& book, const std::string& title) {
    book.title = title;
}

std::string getTitle(const Book& book) {
    return book.title;
}

void setAuthor(Book& book, const std::string& author) {
    book.author = author;
}

std::string getAuthor(const Book& book) {
    return book.author;
}

void setYear(Book& book, int year) {
    book.year = year;
}

int getYear(const Book& book) {
    return book.year;
}

int main() {
    setlocale(LC_ALL, "ukr");
    // Створення об'єкта структури Book
    Book myBook;

    // Задання значень полів
    setTitle(myBook, "The Great Gatsby");
    setAuthor(myBook, "F. Scott Fitzgerald");
    setYear(myBook, 1925);

    // Виведення інформації про книгу
    std::cout << "Назва книги: " << getTitle(myBook) << std::endl;
    std::cout << "Автор книги: " << getAuthor(myBook) << std::endl;
    std::cout << "Рік видання: " << getYear(myBook) << std::endl;

    return 0;
}
