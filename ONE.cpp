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

    auto begin2 = chrono::steady_clock::now();
    int a, b, cnt = 0, NOD;
    int maxch;
    cout << "������� ����� a � b ����� ������ - ";
    cin >> a >> b;
    cout << endl;
    bool fl = false;
    maxch = max(a, b);
    while (fl != true) {
        if ((a == 0) | (b == 0)) { 
            fl = true;
            cout << "1. ���: " << 0; 
        }
        else {
            if ((maxch % a == 0) || (maxch % b == 0)) {
                fl = true;
                cout << "1. ���: " << maxch;
            }
            else {
                maxch += 1;
            }
        }
    }
    auto end2 = chrono::steady_clock::now();
    auto elapsed_ms2 = chrono::duration_cast<chrono::microseconds>(end2 - begin2);
    cout << endl << "����� ������ ������� ��������� " << elapsed_ms2.count() << " �����������" << endl << endl;

    auto begin1 = chrono::steady_clock::now();
    if ((a == 0) | (b == 0)) {
        cout << "1. ���: " << 0;
    }
    else {
        if (a > b) {
            NOD = nod(a, b);
        }
        else { NOD = nod(b, a); }
        cout << "2. ���: " << (a * b) / NOD;
    }
    auto end1 = chrono::steady_clock::now();
    auto elapsed_ms1 = chrono::duration_cast<chrono::microseconds>(end1 - begin1);
    cout << endl << "����� ������ ������� ��������� " << elapsed_ms1.count() << " �����������" << endl;

    return 0;
}
