#include <iostream>
#include <clocale>
#include <chrono>
using namespace std;

int main() {
    setlocale(LC_ALL, ".1251");
    auto begin = chrono::steady_clock::now();
    int a, b, maxch;
    bool fl = false;
    cout << "������� a � b ����� ������ - ";
    cin >> a >> b;
    maxch = max(a, b);
    while (fl != true) {
        if ((maxch % a == 0) && (maxch % b == 0)) {
            fl = true;
            cout << "���: " << maxch << endl;
        }
        else {
            maxch += 1;
        }
    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << endl << "����� ������ ��������� " << elapsed_ms.count() << " �����������" << endl;
}
