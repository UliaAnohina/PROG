#include <iostream>
#include <clocale>
#include <chrono>
using namespace std;

int nod(int num1, int num2)
{
    int n = num1 % num2;
    num1 = num2;
    num2 = n;
    if (n > 0)
        return nod(num1, num2);
    else
        return num1;
}

int main() {
	setlocale(LC_ALL, ".1251");
    auto begin = chrono::steady_clock::now();
    int a, b, cnt = 0, NOD; 
    cout << "������� ����� a � b ����� ������ - ";
    cin >> a >> b;
    cout << endl;
    if (a > b) {
       NOD = nod(a, b);
    }
    else { NOD = nod(b, a); }
    cout << "���������� ����� ������� ����� " << (a * b) / NOD << endl;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << endl << "����� ������ ��������� " << elapsed_ms.count() << " �����������" << endl;


    return 0;
}

