// Book.cpp
#include "Book.h"

// Конструктор за замовчуванням
Book::Book() : title(""), author(""), year(0) {}

// Конструктор з параметрами
Book::Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}

// Методи доступу до полів
void Book::setTitle(const std::string& t) {
    title = t;
}

std::string Book::getTitle() const {
    return title;
}

void Book::setAuthor(const std::string& a) {
    author = a;
}

std::string Book::getAuthor() const {
    return author;
}

void Book::setYear(int y) {
    year = y;
}

int Book::getYear() const {
    return year;
}
