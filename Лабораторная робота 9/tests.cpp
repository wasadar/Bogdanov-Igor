#include "func.h"
#define _CRTDBG_MAP_ALLOC 

int main(){
	setlocale(LC_ALL, "Russian");
	std::cout << "Сейчас будет выведена информация от тестовом массиве и утечке памяти, если этого не произойдёт тест будет не пройден." << "\n";
	int** data;
	int n;
	std::string str = "test.txt";
	data = read_data_from_file(str);
	get_data_to_screen(data);
	clean_data(data);
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "Утечка памяти обнаружена." << "\n";
	}
	else {
		std::cout << "Утечка памяти не обнаружена." << "\n";
	}
	std::cout << "Введите что угодно для завершения роботы программы: ";
	std::cin >> n;
}