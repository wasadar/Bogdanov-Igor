#include "menu2.h"

int main() {
	setlocale(LC_ALL, "Russian");
	file test_file;
	test_file.change_index(1);
	test_file.change_size(2);
	test_file.change_x(32);
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
	int t;
	std::cin >> t;
}