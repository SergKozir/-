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
            throw invalid_argument("���������� �������� ��� ����������������!");
        }
    }

    
    virtual void showInfo() const = 0; // ³�������� ������� ��� ����������� ����������

    // ������
    void setName(string boatName) { name = boatName; }
    void setMaxSpeed(double speed) {
        if (speed < 0) throw invalid_argument("�������� �� ���� ���� ��'�����!");
        maxSpeed = speed;
    }
    void setLoadCapacity(double capacity) {
        if (capacity < 0) throw invalid_argument("���������������� �� ���� ���� ��'�����!");
        loadCapacity = capacity;
    }

    // ������
    string getName() const { return name; }
    double getMaxSpeed() const { return maxSpeed; }
    double getLoadCapacity() const { return loadCapacity; }

    // ³��������� ����������
    virtual ~Boat() {}
};


class Rowboat : public Boat {
private:
    int numberOfOars;     // ʳ������ �����
    string materialType;  // ��� ��������

public:
    Rowboat(string boatName, double speed, double capacity, int oars, string material)
        : Boat(boatName, speed, capacity), numberOfOars(oars), materialType(material) {
        if (numberOfOars <= 0) {
            throw invalid_argument("ʳ������ ����� �� ���� ����� ����!");
        }
    }

    // ������
    void setNumberOfOars(int oars) {
        if (oars <= 0) throw invalid_argument("ʳ������ ����� �� ���� ����� ����!");
        numberOfOars = oars;
    }

    void setMaterialType(string material) { materialType = material; }

    // ������
    int getNumberOfOars() const { return numberOfOars; }
    string getMaterialType() const { return materialType; }

    // �������������� ������ showInfo
    void showInfo() const override {
        cout << "�������� �����: " << name << endl;
        cout << "����������� ��������: " << maxSpeed << " ��/���" << endl;
        cout << "����������������: " << loadCapacity << " ��" << endl;
        cout << "ʳ������ �����: " << numberOfOars << endl;
        cout << "�������: " << materialType << endl;
    }
};


class Motorboat : public Boat {
private:
    double enginePower;   // ��������� �������
    string fuelType;      // ��� ������

public:
    Motorboat(string boatName, double speed, double capacity, double power, string fuel)
        : Boat(boatName, speed, capacity), enginePower(power), fuelType(fuel) {
        if (enginePower <= 0) {
            throw invalid_argument("��������� ������� �� ���� ����� ����!");
        }
    }

    // ������
    void setEnginePower(double power) {
        if (power <= 0) throw invalid_argument("��������� ������� �� ���� ����� ����!");
        enginePower = power;
    }

    void setFuelType(string fuel) { fuelType = fuel; }

    // ������
    double getEnginePower() const { return enginePower; }
    string getFuelType() const { return fuelType; }

    // �������������� ������ showInfo
    void showInfo() const override {
        cout << "�������� �����: " << name << endl;
        cout << "����������� ��������: " << maxSpeed << " ��/���" << endl;
        cout << "����������������: " << loadCapacity << " ��" << endl;
        cout << "��������� �������: " << enginePower << " �.�." << endl;
        cout << "��� ������: " << fuelType << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    try {
        // ��������� �����
        Rowboat rowboat("�������� ����� 1", 15.5, 200, 4, "������");
        Motorboat motorboat("�������� ����� 1", 80.0, 500, 250, "������");

        // ��������� ���������� ��� �����
        rowboat.showInfo();
        cout << endl;
        motorboat.showInfo();
    }
    catch (const exception& e) {
        cerr << "�������: " << e.what() << endl;
    }

    return 0;
}
