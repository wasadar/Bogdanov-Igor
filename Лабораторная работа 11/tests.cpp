#define _CRTDBG_MAP_ALLOC 
#include "funcclass.h"

int main() {
	setlocale(LC_ALL, "Russian");
	funcclass<int> f;
	std::cout << "���� ������ ������ ����� ������� ������ � ������ �������, �� ������� ���������� � ������ �������� ���������." << "\n";
	int n = 10;
	f.data = new int*[n];
	f.len = n;
	for (int i = 0; i < f.len; i++) {
		f.data[i] = new int(i + 1);
	}
	f.sort(1);
	f.print_to_screen();
	f.sort(-1);
	f.print_to_screen();
	for (int i = 0; i < n; i++) {
		delete[] f.data[i];
	}
	delete[] f.data;
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	std::cout << "������� ����� ������� ��� ���������� �����." << "\n";
	std::cin >> n;
}