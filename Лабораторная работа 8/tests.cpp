#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream in("test1.txt");
	std::ofstream on("test2.txt");
	int n;
	dir d;
	in >> d;
	on << d;
	std::cout << "���� ���������� ������ test1 � test2 ������ ���������, �� ���� �������. ������� ����� ������� ��� ����������� ������ ���������. ";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	std::cin >> n;
}