#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	executable_file exe(32, 123, 0, false, false, "abc", 123);
	non_executable_file non(32, 123, 0, false, false, "text", true);
	count_32 c1;
	count_64 c2;
	c1(exe);
	c2(exe);
	c1(non);
	c2(non);
	std::cout << "“ест на работу функторов будет пройден если на следующей строке будет выведен такой текст: 2 0\n" << c1.count << " " << c2.count << "\n";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "”течка пам€ти обнаружена." << "\n";
	}
	else {
		std::cout << "”течка пам€ти не обнаружена." << "\n";
	}
	int n;
	std::cin >> n;
}