#include "menu.h"
#define _CRTDBG_MAP_ALLOC 

int main() {
	setlocale(LC_ALL, "Russian");
	executable_file exe(64, 321, 5, true, true, "abc", 123);
	non_executable_file non(32, 123, 0, false, false, "text", true);
	sort_by s1(1);
	sort_by s2(2);
	sort_by s3(3);
	sort_by s4(4);
	sort_by s5(5);
	sort_by s6(6);
	sort_by s7(7);
	sort_by s8(8);
	sort_by s9(9);
	sort_by s10(10);
	sort_by s11(11);
	sort_by s12(12);
	std::cout << "“ест на работу функтора будет пройден если на следующей строке будет выведен такой текст: 1 1 1 0 1 1 0 0 0 1 0 0\n" << s1(exe, non) << " " << s2(exe, non) << " " << s3(exe, non) << " " << s4(exe, non) << " " << s5(exe, non) << " " << s6(exe, non) << " " << s7(exe, non) << " " << s8(exe, non) << " " << s9(exe, non) << " " << s10(exe, non) << " " << s11(exe, non) << " " << s12(exe, non) << "\n";
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "”течка пам€ти обнаружена." << "\n";
	}
	else {
		std::cout << "”течка пам€ти не обнаружена." << "\n";
	}
	int n;
	std::cin >> n;
}