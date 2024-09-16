#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
};

// ������� ��� ������ � ����������
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
    // ��������� ��'���� ��������� Book
    Book myBook;

    // ������� ������� ����
    setTitle(myBook, "The Great Gatsby");
    setAuthor(myBook, "F. Scott Fitzgerald");
    setYear(myBook, 1925);

    // ��������� ���������� ��� �����
    std::cout << "����� �����: " << getTitle(myBook) << std::endl;
    std::cout << "����� �����: " << getAuthor(myBook) << std::endl;
    std::cout << "г� �������: " << getYear(myBook) << std::endl;

    return 0;
}
