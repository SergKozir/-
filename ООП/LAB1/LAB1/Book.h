// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    // Конструктори
    Book();  // Конструктор за замовчуванням
    Book(std::string title, std::string author, int year);  // Конструктор з параметрами

    // Методи доступу
    void setTitle(const std::string& title);
    std::string getTitle() const;

    void setAuthor(const std::string& author);
    std::string getAuthor() const;

    void setYear(int year);
    int getYear() const;
};

#endif
