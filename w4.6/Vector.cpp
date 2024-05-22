#include "Vector.h"

// ������� ����������� ������� ���������� ��������� ����� (>>)
istream& operator>>(istream& stream, Vector& vector)
{
    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << "������� ������� " << i << ": ";
        int value;
        stream >> value;
        vector.setElement(i, value);
    }
    return stream;
}

// ������� ����������� ������� ���������� ��������� ������ (<<)
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



// ������ ����������� �������
void Vector::setSize(int size)
{
    delete[] elements;
    this->size = size;
    elements = new int[size];
}

// �������� ����������� �������
int Vector::getSize() const
{
    return size;
}

// �������� ������� ������� �� �������
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

// ������ �������� �������� ������� �� �������
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

// ������� ��� �������� ������� � ��������
void Vector::addScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        elements[i] += scalar;
    }
}

// ������� �� ���� ��������� ������������
void Vector::subtractScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        elements[i] -= scalar;
    }
}

// �������� ��� �������� ������� �� ������
void Vector::multiplyByScalar(int scalar)
{
    for (int i = 0; i < size; i++) {
        elements[i] *= scalar;
    }
}

// ��������� ��� �������� ������� �� ������
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

// �������� ����� �������
double Vector::getLength() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += elements[i] * elements[i];
    }
    return sqrt(sum);
}

// ������������ �������� � ������ ��������
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

// ������������ ��������� ������� �������
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

// ������������ ��������� �� ������ ������
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

// ������������ ������� �� ������ ������
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

// ���������� ��������� ������� ���������� �������
void Vector::fillRandom()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; i++)
    {
        elements[i] = rand();
    }
}