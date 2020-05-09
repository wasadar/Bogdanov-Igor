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
	std::cout << "Если содержимое файлов test1 и test2 теперь совпадают, то тест пройден. Нажмите любую клавишу для завершнения работы программы. ";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "Утечка памяти обнаружена." << "\n";
	}
	else {
		std::cout << "Утечка памяти не обнаружена." << "\n";
	}
	std::cin >> n;
}