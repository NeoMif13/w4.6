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

    // ��������� ����������� �������
    int sizeX = X.getSize();
    int sizeY = Y.getSize();
    cout << "������ ������� X: " << sizeX << endl;
    cout << "������ ������� Y: " << sizeY << endl;

    // ��������� �������� ������� �� �������
    int x0 = X.getElement(1);
    int y0 = Y.getElement(0);
    cout << "������� ������� X � �������� 1: " << x0 << endl;
    cout << "������� ������� Y � �������� 0: " << y0 << endl;

    // ������� �������� �������� ������� �� �������
    cout << "������� �������� �������� ������� �� �������:" << endl;

    Vector X0(X);
    Vector Y0(Y);
    X0.setElement(1, 10);
    Y0.setElement(1, 12);
    cout << "X � ��������� (1, 10): " << X0 << endl;
    cout << "Y � ��������� (1, 12): " << Y0 << endl;

    // �������� ���� ��������� ������� X � ��������
    Vector X1(X);
    X1.addScalar(5);
    cout << "X ����� �������� �� ��������: " << X1 << endl;

    // ��������� �� ���� ��������� ������� Y �������
    Vector Y1(Y);
    Y1.subtractScalar(3);
    cout << "Y ����� ��������� �������: " << Y1 << endl;

    // ��������� ���� ��������� ������� X �� ������
    Vector X2(X);
    X2.multiplyByScalar(2);
    cout << "X ����� ��������� �� ������: " << X2 << endl;

    // ������� ���� ��������� ������� Y �� ������
    Vector Y2(Y);
    Y2.divideByScalar(2);
    cout << "Y ����� ������� �� ������: " << Y2 << endl;

    // ��������� ����� ������� X
    double lengthX = X.getLength();
    cout << "����� ������� X: " << lengthX << endl;

    // ������������ �������� �������� X � Y
    Vector X3(X);
    Vector Y3(Y);
    X3.addVector(Y3);
    cout << "X + Y: " << X3 << endl;

    // ������������ ��������� �������� X � Y
    Vector X4(X);
    Vector Y4(Y);
    X4.subtractVector(Y4);
    cout << "X - Y: " << X4 << endl;

    // ������������ ��������� �������� X � Y
    Vector X5(X);
    Vector Y5(Y);
    X5.multiplyByVector(Y5);
    cout << "X * Y: " << X5 << endl;

    // ������������ ������� �������� X � Y
    X.divideByVector(Y);
    cout << "X / Y: " << X << endl;

    int size;
    cout << "������: ";
    cin >> size;

    Vector v(size);

    cout << "������: ";
    cin >> v;

    cout << "�����������: " << v.getSize() << endl;

    cout << "������: " << endl;
    cout << v << endl;


    return 0;
}