#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	executable_file exe(32, 123, 0, false, false, "abc", 123);
	non_executable_file non(32, 123, 0, false, false, "text", true);
	std::cout << (exe > non) << " " << (non > exe) << " " << (exe < non) << " " << (non < exe) << "\n";
	std::cout << "≈сли, в предудущей строке было выведено следующее, то тест на операторы сравнени€ пройден: 1 0 0 1 \n";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "”течка пам€ти обнаружена." << "\n";
	}
	else {
		std::cout << "”течка пам€ти не обнаружена." << "\n";
	}
	int n;
	std::cin >> n;
}