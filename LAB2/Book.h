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
    // ������������
    Book();  // ����������� �� ���������
    Book(std::string title, std::string author, int year);  // ����������� � �����������
    Book(const Book& other);  // ���������� �����������

    // ����������
    ~Book();

    // ������ �������
    void setTitle(const std::string& title);
    std::string getTitle() const;

    void setAuthor(const std::string& author);
    std::string getAuthor() const;

    void setYear(int year);
    int getYear() const;
};

#endif  // ��������� ��������� #ifndef
