#include "file-dir.h"
 
void menu() {
    setlocale(LC_ALL, "Russian");
    int n = 0, temp_i;
    dir directory;
    std::string temp;
    file temp_file;
    temp_file.change_name("Test1");
    temp_file.change_extension("txt");
    temp_file.change_size(1234);
    temp_file.change_index(42);
    directory.add_file(temp_file);
    temp_file.change_name("Test2");
    temp_file.change_extension("txt");
    temp_file.change_size(521);
    temp_file.change_index(425);
    directory.add_file(temp_file);
    temp_file.change_name("Test3");
    temp_file.change_extension("txt");
    temp_file.change_size(289);
    temp_file.change_index(4258);
    directory.add_file(temp_file);
    temp_file.change_name("ABC");
    temp_file.change_extension("pdf");
    temp_file.change_size(10000);
    temp_file.change_index(42587);
    directory.add_file(temp_file);
    while (n != 4) {
        std::cout << "Выберите желаемую опцию:" << "\n";
        std::cout << "1 - добавить элемент в список." << "\n";
        std::cout << "2 - удалить элемент из списка." << "\n";
        std::cout << "3 - показать все элементы списка." << "\n";
        std::cout << "4 - завершить работу программы." << "\n";
        std::cin >> n;
        if (n == 1) {
            temp_file.change_name("Test");
            temp_file.change_extension("txt");
            temp_file.change_size(123);
            temp_file.change_index(424);
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