#include "func.h"
#define _CRTDBG_MAP_ALLOC 

int main(){
	setlocale(LC_ALL, "Russian");
	std::cout << "������ ����� �������� ���������� �� �������� ������� � ������ ������, ���� ����� �� ��������� ���� ����� �� �������." << "\n";
	int** data;
	int n;
	std::string str = "test.txt";
	data = read_data_from_file(str);
	get_data_to_screen(data);
	clean_data(data);
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "������ ������ ����������." << "\n";
	}
	else {
		std::cout << "������ ������ �� ����������." << "\n";
	}
	std::cout << "������� ��� ������ ��� ���������� ������ ���������: ";
	std::cin >> n;
}