#include "Book.h"

// Конструктор за замовчуванням
Book::Book() : title(""), author(""), year(0) {
    std::cout << "Конструктор за замовчуванням викликано\n";
}

// Конструктор з параметрами
Book::Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {
    std::cout << "Конструктор з параметрами викликано\n";
}

// Копіюючий конструктор
Book::Book(const Book& other) : title(other.title), author(other.author), year(other.year) {
    std::cout << "Копіюючий конструктор викликано\n";
}

// Деструктор
Book::~Book() {
    std::cout << "Деструктор викликано для книги: " << title << "\n";
}

// Методи доступу
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
