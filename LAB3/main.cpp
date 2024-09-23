#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Клас "Адреса", який представляє адресу проживання людини
class Address {
public:
    string city;
    string street;
    int houseNumber;

    Address(string city, string street, int houseNumber)
        : city(city), street(street), houseNumber(houseNumber) {}

    // Метод для виведення адреси
    string getAddress() const {
        return street + ", " + to_string(houseNumber) + ", " + city;
    }
};

// Базовий клас "Людина"
class Person {
public:
    string name;
    int age;
    Address address;  // Композиція з класом "Адреса"

    Person(string name, int age, Address address)
        : name(name), age(age), address(address) {}

    // Метод для виведення інформації про людину
    virtual void displayInfo() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Адреса: " << address.getAddress() << endl;
    }
};

// Похідний клас "Студент" від класу "Людина"
class Student : public Person {
public:
    string studentID;
    int course;

    Student(string name, int age, Address address, string studentID, int course)
        : Person(name, age, address), studentID(studentID), course(course) {}

    // Перевизначення методу для виведення інформації про студента
    void displayInfo() const override {
        Person::displayInfo();  // Виклик методу базового класу
        cout << "Студентський квиток: " << studentID << ", Курс: " << course << endl;
    }
};

// Клас "Університет", що містить список студентів (агрегація)
class University {
private:
    string universityName;
    vector<Student> students;  // Список студентів

public:
    University(string universityName)
        : universityName(universityName) {}

    // Метод для додавання студента
    void addStudent(const Student& student) {
        students.push_back(student);
        cout << "Студента " << student.name << " додано до університету " << universityName << "." << endl;
    }

    // Метод для видалення студента за номером студентського квитка
    void removeStudent(const string& studentID) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->studentID == studentID) {
                cout << "Студента " << it->name << " видалено з університету " << universityName << "." << endl;
                students.erase(it);
                return;
            }
        }
        cout << "Студента з номером квитка " << studentID << " не знайдено." << endl;
    }

    // Метод для виведення списку студентів
    void listStudents() const {
        if (students.empty()) {
            cout << "Немає студентів у списку." << endl;
        }
        else {
            cout << "Список студентів університету " << universityName << ":" << endl;
            for (const auto& student : students) {
                student.displayInfo();
            }
        }
    }
};

// Демонстраційна функція main()
int main() {
    setlocale(LC_ALL, "ukr");
    // Створення об'єктів класу "Адреса"
    Address address1("Київ", "Вулиця Шевченка", 12);
    Address address2("Львів", "Проспект Свободи", 45);

    // Створення об'єктів класу "Студент"
    Student student1("Іван Іваненко", 20, address1, "STU12345", 2);
    Student student2("Марія Петрівна", 21, address2, "STU67890", 3);

    // Створення об'єкта класу "Університет"
    University university("Центрально Національний Тезнічний Університет");

    // Додавання студентів до університету
    university.addStudent(student1);
    university.addStudent(student2);

    // Виведення списку студентів
    university.listStudents();

    // Виклик методів базового та похідного класу
    cout << "\nІнформація про студента (базовий клас та похідний клас):" << endl;
    student1.displayInfo();
    student2.displayInfo();

    // Видалення студента
    university.removeStudent("STU12345");

    // Виведення списку студентів після видалення
    university.listStudents();

    return 0;
}
