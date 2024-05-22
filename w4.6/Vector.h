#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Vector
{    // Перегрузка оператора вывода (>>)
    friend istream& operator>>(istream&, Vector&);

    // Перегрузка оператора вывода (<<)
    friend ostream& operator<<(ostream&, const Vector&);

private:
    int* elements;
    int size;

public:
    // Конструкторы
    Vector();
    Vector(int size);
    Vector(const Vector& other);
    Vector(Vector&& other);

    // Деструктор
    ~Vector();

    // Методы
    void setSize(int size);
    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);
    void addScalar(int scalar);
    void subtractScalar(int scalar);
    void multiplyByScalar(int scalar);
    void divideByScalar(int scalar);
    double getLength() const;
    void addVector(const Vector& other);
    void subtractVector(const Vector& other);
    void multiplyByVector(const Vector& other);
    void divideByVector(const Vector& other);
    void fillRandom();

    // Перегрузка оператора ввода (>>)
    istream& operator>>(istream& stream)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Введите элемент " << i << ": ";
            stream >> elements[i];
        }
        return stream;
    }

    // Перегрузка оператора вывода (<<)
    ostream& operator<<(ostream& stream)
    {
        for (int i = 0; i < size; i++)
        {
            stream << elements[i] << " ";
        }
        return stream;
    }
    
    
   
};
