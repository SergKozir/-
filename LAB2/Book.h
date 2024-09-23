#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    // Конструкторы
    Book();  // Конструктор по умолчанию
    Book(std::string title, std::string author, int year);  // Конструктор с параметрами
    Book(const Book& other);  // Копирующий конструктор

    // Деструктор
    ~Book();

    // Методы доступа
    void setTitle(const std::string& title);
    std::string getTitle() const;

    void setAuthor(const std::string& author);
    std::string getAuthor() const;

    void setYear(int year);
    int getYear() const;
};

#endif  // Закрываем директиву #ifndef
