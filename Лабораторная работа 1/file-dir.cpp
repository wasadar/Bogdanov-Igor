#include "file-dir.h"
 
void menu() {
    int n, temp_i;
    dir directory;
    std::string temp;
    file temp_file;
    while (n != 4) {
        std::cout << "Выберите желаемую опцию:" << "\n";
        std::cout << "1 - добавить элемент в список." << "\n";
        std::cout << "2 - удалить элемент из списка." << "\n";
        std::cout << "3 - показать все элементы списка." << "\n";
        std::cout << "4 - завершить работу программы." << "\n";
        std::cin >> n;
        if (n == 1) {
            std::cout << "Введите данные о новом элементе." << "\n";
            std::cout << "Имя файла: ";
            std::cin >> temp;
            temp_file.change_name(temp);
            std::cout << "Расширение (без точки): ";
            std::cin >> temp;
            temp_file.change_extension(temp);
            std::cout << "Вес файла: ";
            std::cin >> temp_i;
            temp_file.change_size(temp_i);
            std::cout << "Индекс: ";
            std::cin >> temp_i;
            temp_file.change_index(temp_i);
            directory.add_file(temp_file);
            std::cout << "Файл добавлен." << "\n";
        }
        else if (n == 2) {
            std::cout << "Введите номер удалемого элемента (нумерация начинаеться с 0): ";
            std::cin >> temp_i;
            directory.del_file(temp_i);
            std::cout << "Файл удалён";
        }
        else if (n == 3) {
            directory.print_all();
        }
    }
}