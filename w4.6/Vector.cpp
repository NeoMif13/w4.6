#include "Vector.h"

// Внешняя независимая функция перегрузки оператора ввода (>>)
istream& operator>>(istream& stream, Vector& vector)
{
    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << "Введите элемент " << i << ": ";
        int value;
        stream >> value;
        vector.setElement(i, value);
    }
    return stream;
}

// Внешняя независимая функция перегрузки оператора вывода (<<)
ostream& operator<<(ostream& stream, const Vector& vector)
{
    for (int i = 0; i < vector.getSize(); i++)
    {
        stream << vector.getElement(i) << " ";
    }
    return stream;
}

Vector::Vector()
{
    elements = nullptr;
    size = 0;
}

Vector::Vector(int size) 
{
    this->size = size;
    elements = new int[size];
}

Vector::Vector(const Vector& other)
{
    size = other.size;
    elements = new int[size];
    for (int i = 0; i < size; i++)
    {
        elements[i] = other.elements[i];
    }
}

Vector::Vector(Vector&& other) 
{
    elements = other.elements;
    size = other.size;
    other.elements = nullptr;
    other.size = 0;
}


Vector::~Vector()
{
    delete[] elements;
}



// Задать размерность вектора
void Vector::setSize(int size)
{
    delete[] elements;
    this->size = size;
    elements = new int[size];
}

// Получить размерность вектора
int Vector::getSize() const
{
    return size;
}

// Получить элемент вектора по индексу
int Vector::getElement(int index) const
{
    if (index >= 0 && index < size)
    {
        return elements[index];
    }
    else
    {
        cout << "Error: Index out of bounds" << endl;
        return 0;
    }
}

// Задать значение элемента вектора по индексу
void Vector::setElement(int index, int value)
{
    if (index >= 0 && index < size)
    {
        elements[index] = value;
    }
    else {
        cout << "Error: Index out of bounds" << endl;
    }
}

// Сложить все элементы вектора с скаляром
void Vector::addScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        elements[i] += scalar;
    }
}

// Вычесть из всех элементов векторскаляр
void Vector::subtractScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        elements[i] -= scalar;
    }
}

// Умножить все элементы вектора на скаляр
void Vector::multiplyByScalar(int scalar)
{
    for (int i = 0; i < size; i++) {
        elements[i] *= scalar;
    }
}

// Разделить все элементы вектора на скаляр
void Vector::divideByScalar(int scalar)
{
    if (scalar != 0)
    {
        for (int i = 0; i < size; i++)
        {
            elements[i] /= scalar;
        }
    }
    else {
        cout << "Error: Division by zero" << endl;
    }
}

// Получить длину вектора
double Vector::getLength() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += elements[i] * elements[i];
    }
    return sqrt(sum);
}

// Поэлементное сложение с другим вектором
void Vector::addVector(const Vector& other)
{
    if (size != other.size)
    {
        cout << "Error: Vectors have different sizes" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        elements[i] += other.elements[i];
    }
}

// Поэлементное вычитание другого вектора
void Vector::subtractVector(const Vector& other)
{
    if (size != other.size)
    {
        cout << "Error: Vectors have different sizes" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        elements[i] -= other.elements[i];
    }
}

// Поэлементное умножение на другой вектор
void Vector::multiplyByVector(const Vector& other)
{
    if (size != other.size)
    {
        cout << "Error: Vectors have different sizes" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        elements[i] *= other.elements[i];
    }
}

// Поэлементное деление на другой вектор
void Vector::divideByVector(const Vector& other)
{
    if (size != other.size)
    {
        cout << "Error: Vectors have different sizes" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (other.elements[i] != 0)
        {
            elements[i] /= other.elements[i];
        }
        else
        {
            cout << "Error: Division by zero" << endl;
            return;
        }
    }
}

// Заполнение элементов вектора случайными числами
void Vector::fillRandom()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; i++)
    {
        elements[i] = rand();
    }
}