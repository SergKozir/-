#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ���� "������", ���� ����������� ������ ���������� ������
class Address {
public:
    string city;
    string street;
    int houseNumber;

    Address(string city, string street, int houseNumber)
        : city(city), street(street), houseNumber(houseNumber) {}

    // ����� ��� ��������� ������
    string getAddress() const {
        return street + ", " + to_string(houseNumber) + ", " + city;
    }
};

// ������� ���� "������"
class Person {
public:
    string name;
    int age;
    Address address;  // ���������� � ������ "������"

    Person(string name, int age, Address address)
        : name(name), age(age), address(address) {}

    // ����� ��� ��������� ���������� ��� ������
    virtual void displayInfo() const {
        cout << "��'�: " << name << ", ³�: " << age << ", ������: " << address.getAddress() << endl;
    }
};

// �������� ���� "�������" �� ����� "������"
class Student : public Person {
public:
    string studentID;
    int course;

    Student(string name, int age, Address address, string studentID, int course)
        : Person(name, age, address), studentID(studentID), course(course) {}

    // �������������� ������ ��� ��������� ���������� ��� ��������
    void displayInfo() const override {
        Person::displayInfo();  // ������ ������ �������� �����
        cout << "������������ ������: " << studentID << ", ����: " << course << endl;
    }
};

// ���� "����������", �� ������ ������ �������� (���������)
class University {
private:
    string universityName;
    vector<Student> students;  // ������ ��������

public:
    University(string universityName)
        : universityName(universityName) {}

    // ����� ��� ��������� ��������
    void addStudent(const Student& student) {
        students.push_back(student);
        cout << "�������� " << student.name << " ������ �� ����������� " << universityName << "." << endl;
    }

    // ����� ��� ��������� �������� �� ������� ������������� ������
    void removeStudent(const string& studentID) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->studentID == studentID) {
                cout << "�������� " << it->name << " �������� � ����������� " << universityName << "." << endl;
                students.erase(it);
                return;
            }
        }
        cout << "�������� � ������� ������ " << studentID << " �� ��������." << endl;
    }

    // ����� ��� ��������� ������ ��������
    void listStudents() const {
        if (students.empty()) {
            cout << "���� �������� � ������." << endl;
        }
        else {
            cout << "������ �������� ����������� " << universityName << ":" << endl;
            for (const auto& student : students) {
                student.displayInfo();
            }
        }
    }
};

// �������������� ������� main()
int main() {
    setlocale(LC_ALL, "ukr");
    // ��������� ��'���� ����� "������"
    Address address1("���", "������ ��������", 12);
    Address address2("����", "�������� �������", 45);

    // ��������� ��'���� ����� "�������"
    Student student1("���� ��������", 20, address1, "STU12345", 2);
    Student student2("���� �������", 21, address2, "STU67890", 3);

    // ��������� ��'���� ����� "����������"
    University university("���������� ������������ �������� ����������");

    // ��������� �������� �� �����������
    university.addStudent(student1);
    university.addStudent(student2);

    // ��������� ������ ��������
    university.listStudents();

    // ������ ������ �������� �� ��������� �����
    cout << "\n���������� ��� �������� (������� ���� �� �������� ����):" << endl;
    student1.displayInfo();
    student2.displayInfo();

    // ��������� ��������
    university.removeStudent("STU12345");

    // ��������� ������ �������� ���� ���������
    university.listStudents();

    return 0;
}
