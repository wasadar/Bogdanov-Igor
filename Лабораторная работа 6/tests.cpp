#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	x_version* x32 = new x_version;
	x_version* x64 = new x_version;
	x32->change_ver(32);
	x64->change_ver(64);
	system_file test_file_1(x32, 1, 1, true, true, "ABC", false);
	system_file test_file_2(x64, 2, 2, false, false, "BCD", true);
	std::cout << "���� ����� ������� ���� ������ �� ����� ����� �������� ��������� ������������������: 1 1 0 0 0 1 - ";
	std::cout << sort_version(test_file_1, test_file_2) << " " << sort_size(test_file_1, test_file_2) << " " << sort_ind(test_file_1, test_file_2) << " " << sort_opt(test_file_1, test_file_2) << " " << sort_name(test_file_1, test_file_2) << " " << sort_exe(test_file_1,test_file_2);
	std::cin >> n;
}