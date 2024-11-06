#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


class Boat {
protected:
    string name;
    double maxSpeed;
    double loadCapacity;

public:
    
    Boat(string boatName, double speed, double capacity)
        : name(boatName), maxSpeed(speed), loadCapacity(capacity) {
        if (maxSpeed < 0 || loadCapacity < 0) {
            throw invalid_argument("Некоректна швидкість або вантажопідйомність!");
        }
    }

    
    virtual void showInfo() const = 0; // Віртуальна функція для відображення інформації

    // Сетери
    void setName(string boatName) { name = boatName; }
    void setMaxSpeed(double speed) {
        if (speed < 0) throw invalid_argument("Швидкість не може бути від'ємною!");
        maxSpeed = speed;
    }
    void setLoadCapacity(double capacity) {
        if (capacity < 0) throw invalid_argument("Вантажопідйомність не може бути від'ємною!");
        loadCapacity = capacity;
    }

    // Гетери
    string getName() const { return name; }
    double getMaxSpeed() const { return maxSpeed; }
    double getLoadCapacity() const { return loadCapacity; }

    // Віртуальний деструктор
    virtual ~Boat() {}
};


class Rowboat : public Boat {
private:
    int numberOfOars;     // Кількість весел
    string materialType;  // Тип матеріалу

public:
    Rowboat(string boatName, double speed, double capacity, int oars, string material)
        : Boat(boatName, speed, capacity), numberOfOars(oars), materialType(material) {
        if (numberOfOars <= 0) {
            throw invalid_argument("Кількість весел має бути більше нуля!");
        }
    }

    // Сетери
    void setNumberOfOars(int oars) {
        if (oars <= 0) throw invalid_argument("Кількість весел має бути більше нуля!");
        numberOfOars = oars;
    }

    void setMaterialType(string material) { materialType = material; }

    // Гетери
    int getNumberOfOars() const { return numberOfOars; }
    string getMaterialType() const { return materialType; }

    // Перевизначення методу showInfo
    void showInfo() const override {
        cout << "Весловий човен: " << name << endl;
        cout << "Максимальна швидкість: " << maxSpeed << " км/год" << endl;
        cout << "Вантажопідйомність: " << loadCapacity << " кг" << endl;
        cout << "Кількість весел: " << numberOfOars << endl;
        cout << "Матеріал: " << materialType << endl;
    }
};


class Motorboat : public Boat {
private:
    double enginePower;   // Потужність двигуна
    string fuelType;      // Тип палива

public:
    Motorboat(string boatName, double speed, double capacity, double power, string fuel)
        : Boat(boatName, speed, capacity), enginePower(power), fuelType(fuel) {
        if (enginePower <= 0) {
            throw invalid_argument("Потужність двигуна має бути більше нуля!");
        }
    }

    // Сетери
    void setEnginePower(double power) {
        if (power <= 0) throw invalid_argument("Потужність двигуна має бути більше нуля!");
        enginePower = power;
    }

    void setFuelType(string fuel) { fuelType = fuel; }

    // Гетери
    double getEnginePower() const { return enginePower; }
    string getFuelType() const { return fuelType; }

    // Перевизначення методу showInfo
    void showInfo() const override {
        cout << "Моторний човен: " << name << endl;
        cout << "Максимальна швидкість: " << maxSpeed << " км/год" << endl;
        cout << "Вантажопідйомність: " << loadCapacity << " кг" << endl;
        cout << "Потужність двигуна: " << enginePower << " к.с." << endl;
        cout << "Тип палива: " << fuelType << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    try {
        // Створюємо човни
        Rowboat rowboat("Весловий Човен 1", 15.5, 200, 4, "Дерево");
        Motorboat motorboat("Моторний Човен 1", 80.0, 500, 250, "Бензин");

        // Виведення інформації про човни
        rowboat.showInfo();
        cout << endl;
        motorboat.showInfo();
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
