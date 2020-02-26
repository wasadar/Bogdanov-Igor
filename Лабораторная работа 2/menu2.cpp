#include "menu2.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    int n = 0, temp_i;
    dir directory;
    file temp_file;
    temp_file.change_size(1234);
    temp_file.change_x(32);
    temp_file.change_sys(true);
    temp_file.change_hid(true);
    temp_file.change_name("sys\0");
    directory.add_file(temp_file);
    temp_file.change_size(521);
    temp_file.change_x(64);
    temp_file.change_hid(false);
    temp_file.change_sys(true);
    temp_file.change_name("qwerty\0");
    directory.add_file(temp_file);
    temp_file.change_size(289);
    temp_file.change_x(64);
    temp_file.change_hid(true);
    temp_file.change_sys(false);
    temp_file.change_name("hello\0");
    directory.add_file(temp_file);
    temp_file.change_size(10000);
    temp_file.change_x(32);
    temp_file.change_hid(false);
    temp_file.change_sys(false);
    temp_file.change_name("water\0");
    directory.add_file(temp_file);
    while (n != 4) {
        std::cout << "Выберите желаемую опцию:" << "\n";
        std::cout << "1 - добавить элемент в список." << "\n";
        std::cout << "2 - удалить элемент из списка." << "\n";
        std::cout << "3 - показать все элементы списка." << "\n";
        std::cout << "4 - завершить работу программы." << "\n";
        std::cout << "5 - посчитать количество скрытых системных файлов." << "\n";
        std::cin >> n;
        if (n == 1) {
            temp_file.change_size(123);
            temp_file.change_x(64);
            temp_file.change_hid(false);
            temp_file.change_sys(false);
            temp_file.change_name("file");
            directory.add_file(temp_file);
            std::cout << "Файл добавлен." << "\n";
        }
        else if (n == 2) {
            std::cout << "Введите номер удалемого элемента (нумерация начинаеться с 1): ";
            std::cin >> temp_i;
            directory.del_file(temp_i - 1);
            std::cout << "Файл удалён. " << "\n";
        }
        else if (n == 3) {
            directory.print_all();
        }
        else if (n == 5) {
            std::cout << "Количество скрытых системных файлов: " << directory.count_system() << "\n";
        }
    }
    directory.del_all();
}