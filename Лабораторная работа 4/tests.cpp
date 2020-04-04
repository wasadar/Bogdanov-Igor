#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	file test_file;
	test_file.change_index(1);
	test_file.change_size(2);
	test_file.change_x(32);
	test_file.change_name("Test");
	test_file.change_hid(true);
	test_file.change_sys(false);
	if ((test_file.get_index() == 1) && (test_file.get_size() == 2) && (test_file.get_x() == 32)) {
		std::cout << "������ ���� �� ������ �������� � �������� �������� ������ ������� �������." << "\n";
	}
	else {
		std::cout << "������ ���� �� ������ �������� � �������� �������� ������ ��������." << "\n";
	}
	dir test_dir;
	test_dir.add_file(test_file);
	test_dir.print_all();
	std::cout << "���� ����� ���� ���������� �� ����� �������� ���������� � ����� ������ add_file, print_all � get_file_to_screen �������� ���������." << "\n";
	test_dir.del_all();
	test_dir.print_all();
	std::cout << "���� ����� ���� ��������� �� ����� �� ���������� ����� ����� �� ������ del_all � del_file �������� ���������." << "\n";
	test_dir.read_from_file("data.txt");
	test_dir.print_all();
	std::cout << "���� ����� ���� ���������� �� ����� �������� ���������� � ������, �� ������ ������ � ����� � ��������� ����� �� ������ �������� ���������." << "\n";
	test_dir.add_file(test_file);
	test_dir.print_to_file("data.txt");
	test_dir.read_from_file("data.txt");
	test_dir.print_all();
	std::cout << "���� ����� ���� ���������� �� ����� �������� ���������� � ���� ���������� ������ � ����� �����, �� ����� ������ ���������� � ���� �������� ���������." << "\n";
	test_dir.print_all_with_2_or_more_words();
	std::cout << "���� ����� ���� ���������� �� ����� �������� ���������� � ���� ������ � ���������� �� ���� ����, �� ����� ������ ���������� � ������ � ���������� �� ���� ���� �������� �����. " << "\n";
	test_dir.read_from_file("test.txt");
	test_dir.print_all();
	std::cout << "���� ����� ���� ���������� �� ����� �������� ���������� � �������� ����� � ������ �� � ����� ������, �� �������� ������ � ����� � ������ ��������� ����� �� ������ �������� �����." << "\n";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	int t;
	std::cin >> t;
}