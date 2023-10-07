#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct ZADANIE {
	string name, date;
	int size;
};

int main() {
	setlocale(LC_ALL, ".1251");
	ifstream in("ZADANIE.txt");

	if (!in.is_open()) {
		cout << "������ �������� �����!" << endl;
		return 1;
	}

	vector<ZADANIE> files;

	string name, date;
	int size;

	while (in >> name >> date >> size) {
		files.push_back({ name, date, size });
	}
	in.close();

	for (auto file : files) {
		cout << "�������� �����: " << file.name << endl;
		cout << "���� ��������: " << file.date << endl;
		cout << "������: " << file.size << " ����" << endl;
		cout << endl;
	}
	return 0;
}