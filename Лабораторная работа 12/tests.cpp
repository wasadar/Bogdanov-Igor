#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	executable_file exe(32, 123, 0, false, false, "abc", 123);
	non_executable_file non(32, 123, 0, false, false, "text", true);
	std::cout << (exe > non) << " " << (non > exe) << " " << (exe < non) << " " << (non < exe) << "\n";
	std::cout << "����, � ���������� ������ ���� �������� ���������, �� ���� �� ��������� ��������� �������: 1 0 0 1 \n";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	int n;
	std::cin >> n;
}