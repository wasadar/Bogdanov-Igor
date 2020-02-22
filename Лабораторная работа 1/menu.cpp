#include "menu.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    int n = 0, temp_i;
    dir directory;
    file temp_file;
    temp_file.change_size(1234);
    temp_file.change_x(32);
    directory.add_file(temp_file);
    temp_file.change_size(521);
    temp_file.change_x(64);
    directory.add_file(temp_file);
    temp_file.change_size(289);
    temp_file.change_x(64);
    directory.add_file(temp_file);
    temp_file.change_size(10000);
    temp_file.change_x(32);
    directory.add_file(temp_file);
    while (n != 4) {
        std::cout << "Выберите желаемую опцию:" << "\n";
        std::cout << "1 - добавить элемент в список." << "\n";
        std::cout << "2 - удалить элемент из списка." << "\n";
        std::cout << "3 - показать все элементы списка." << "\n";
        std::cout << "4 - завершить работу программы." << "\n";
        std::cout << "5 - получить файл по индексу." << "\n";
        std::cin >> n;
        if (n == 1) {
            temp_file.change_size(123);
            temp_file.change_x(64);
            directory.add_file(temp_file);
            std::cout << "Файл добавлен." << "\n";
        }
        else if (n == 2) {
            std::cout << "Введите номер удалемого элемента (нумерация начинаеться с 1): ";
            std::cin >> temp_i;
            directory.del_file(temp_i - 1);
            std::cout << "Файл удалён";
        }
        else if (n == 3) {
            directory.print_all();
        }
        else if (n == 5) {
            std::cout << "Введите индекс нового элемента. ";
            std::cin >> temp_i;
            temp_i;
            directory.get_file_by_index(temp_i);
        }
    }
    directory.del_all();
}