#define _CRTDBG_MAP_ALLOC 
#include "funcclass.h"

int main() {
	setlocale(LC_ALL, "Russian");
	funcclass f;
	int* data;
	std::cout << "���� ������ ������ ����� ������� ������ � ������ �������, �� ������� ���������� � ������ �������� ���������." << "\n";
	int n = 10;
	data = new int[n];
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
	}
	f.sort(data, n, 1);
	f.print_to_screen(data, n);
	f.sort(data, n, -1);
	f.print_to_screen(data, n);
	delete[] data;
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	std::cout << "������� ����� ������� ��� ���������� �����." << "\n";
	std::cin >> n;
}