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
	test_dir.read_from_file("data.txt");
	test_dir.print_all();
	std::cout << "Если перед этим сообщением на экран вывелась информация о файлах, то методы чтения с файла и получение файла из строки работают правильно." << "\n";
	test_dir.add_file(test_file);
	test_dir.print_to_file("data.txt");
	test_dir.read_from_file("data.txt");
	test_dir.print_all();
	std::cout << "Если перед этим сообщением на экран вывелась информация о всех предыдущих файлах и одном новом, то метод записи информации в файл работает правильно." << "\n";
	test_dir.print_all_with_2_or_more_words();
	std::cout << "Если перед этим сообщением на экран вывелась информация о двух файлах с названиями из двух слов, то метод выводы информации о файлах с названиями из двух слов работает верно. " << "\n";
	test_dir.read_from_file("test.txt");
	test_dir.print_all();
	std::cout << "Если перед этим сообщением на экран вывелась информация о тестовом файле и больше ни о каких других, то проверка данных о файле в методе получения файла из строки работает верно." << "\n";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "Утечка памяти обнаружена." << "\n";
	}
	else {
		std::cout << "Утечка памяти не обнаружена." << "\n";
	}
	int t;
	std::cin >> t;
}