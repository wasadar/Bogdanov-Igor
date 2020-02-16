#include "menu2.h"

int main() {
	setlocale(LC_ALL, "Russian");
	file test_file;
	test_file.change_index(1);
	test_file.change_size(2);
	test_file.change_x(32);
	if ((test_file.get_index() == 1) && (test_file.get_size() == 2) && (test_file.get_x() == 32)) {
		std::cout << "Первый тест на работу геттеров и сеттеров базового класса пройден успешно." << "\n";
	}
	else {
		std::cout << "Первый тест на работу геттеров и сеттеров базового класса провален." << "\n";
	}
	dir test_dir;
	test_dir.add_file(test_file);
	test_dir.print_all();
	std::cout << "Если перед этим сообщением на экран вывелась информация о файле методы add_file, print_all и get_file_to_screen работают корректно." << "\n";
	test_dir.del_all();
	test_dir.print_all();
	std::cout << "Если перед этим сообщение на экран не выводились новые числа то методы del_all и del_file работают корректно." << "\n";
	int t;
	std::cin >> t;
}