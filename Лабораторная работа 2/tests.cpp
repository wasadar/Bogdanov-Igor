#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	file test_file;
	test_file.change_index(1);
	test_file.change_size(2);
	test_file.change_x(32);
	if ((test_file.get_index() == 1) && (test_file.get_size() == 2) && (test_file.get_x() == 32)) {
		std::cout << "������ ���� �� ������ �������� � ��������, � ��� �� �������� ������������ �������� ������ ������� �������." << "\n";
	}
	else {
		std::cout << "������ ���� �� ������ �������� � ��������, � ��� �� �������� ������������ �������� ������ ��������." << "\n";
	}
	dir test_dir;
	test_dir.add_file(test_file);
	test_dir.print_all();
	std::cout << "���� ����� ���� ���������� �� ����� �������� ���������� � ����� ������ add_file, print_all � get_file_to_screen �������� ���������." << "\n";
	test_dir.del_all();
	test_dir.print_all();
	std::cout << "���� ����� ���� ��������� �� ����� �� ���������� ����� ����� �� ������ del_all � del_file �������� ���������." << "\n";
	file second_test_file(1, 2, 3, true, true, "name");
	test_dir.add_file(second_test_file);
	if (test_dir.count_system() == 1) {
		std::cout << "�������� ������ ������ count_system � ������������ � ����������� ��������." << "\n";
	}
	else {
		std::cout << "�������� ������ ������ count_system � ������������ � ����������� ���������." << "\n";
	}
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	int t;
	std::cin >> t;
}