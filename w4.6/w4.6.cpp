#include <iostream>
#include "Vector.h"

using namespace std;

int main()

{
    setlocale(LC_ALL, "RU");
    const int N = 5;
    Vector X(N);
    Vector Y(N);
    Vector Z(N);

    X.fillRandom();
    Y.fillRandom();
    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;

    int a = 3;
    int b = 1;

    for (int i = 0; i < N; i++)
    {
        int xi = X.getElement(i);
        int yi = Y.getElement(i);
        int zi = a * xi - b * yi;
        Z.setElement(i, zi);
    }

    cout << "Z: " << Z << endl;

    // Получение размерности вектора
    int sizeX = X.getSize();
    int sizeY = Y.getSize();
    cout << "Размер вектора X: " << sizeX << endl;
    cout << "Размер вектора Y: " << sizeY << endl;

    // Получение элемента вектора по индексу
    int x0 = X.getElement(1);
    int y0 = Y.getElement(0);
    cout << "Элемент вектора X с индексом 1: " << x0 << endl;
    cout << "Элемент вектора Y с индексом 0: " << y0 << endl;

    // Задание значения элемента вектора по индексу
    cout << "Задание значения элемента вектора по индексу:" << endl;

    Vector X0(X);
    Vector Y0(Y);
    X0.setElement(1, 10);
    Y0.setElement(1, 12);
    cout << "X с элементом (1, 10): " << X0 << endl;
    cout << "Y с элементом (1, 12): " << Y0 << endl;

    // Сложение всех элементов вектора X с скаляром
    Vector X1(X);
    X1.addScalar(5);
    cout << "X после сложения со скаляром: " << X1 << endl;

    // Вычитание из всех элементов вектора Y скаляра
    Vector Y1(Y);
    Y1.subtractScalar(3);
    cout << "Y после вычитания скаляра: " << Y1 << endl;

    // Умножение всех элементов вектора X на скаляр
    Vector X2(X);
    X2.multiplyByScalar(2);
    cout << "X после умножения на скаляр: " << X2 << endl;

    // Деление всех элементов вектора Y на скаляр
    Vector Y2(Y);
    Y2.divideByScalar(2);
    cout << "Y после деления на скаляр: " << Y2 << endl;

    // Получение длины вектора X
    double lengthX = X.getLength();
    cout << "Длина вектора X: " << lengthX << endl;

    // Поэлементное сложение векторов X и Y
    Vector X3(X);
    Vector Y3(Y);
    X3.addVector(Y3);
    cout << "X + Y: " << X3 << endl;

    // Поэлементное вычитание векторов X и Y
    Vector X4(X);
    Vector Y4(Y);
    X4.subtractVector(Y4);
    cout << "X - Y: " << X4 << endl;

    // Поэлементное умножение векторов X и Y
    Vector X5(X);
    Vector Y5(Y);
    X5.multiplyByVector(Y5);
    cout << "X * Y: " << X5 << endl;

    // Поэлементное деление векторов X и Y
    X.divideByVector(Y);
    cout << "X / Y: " << X << endl;

    int size;
    cout << "Размер: ";
    cin >> size;

    Vector v(size);

    cout << "Вектор: ";
    cin >> v;

    cout << "Размерность: " << v.getSize() << endl;

    cout << "Вектор: " << endl;
    cout << v << endl;


    return 0;
}