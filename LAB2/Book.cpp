#include "Book.h"

// ����������� �� �������������
Book::Book() : title(""), author(""), year(0) {
    std::cout << "����������� �� ������������� ���������\n";
}

// ����������� � �����������
Book::Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {
    std::cout << "����������� � ����������� ���������\n";
}

// �������� �����������
Book::Book(const Book& other) : title(other.title), author(other.author), year(other.year) {
    std::cout << "�������� ����������� ���������\n";
}

// ����������
Book::~Book() {
    std::cout << "���������� ��������� ��� �����: " << title << "\n";
}

// ������ �������
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
