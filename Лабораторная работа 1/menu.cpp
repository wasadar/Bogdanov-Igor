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
        std::cout << "�������� �������� �����:" << "\n";
        std::cout << "1 - �������� ������� � ������." << "\n";
        std::cout << "2 - ������� ������� �� ������." << "\n";
        std::cout << "3 - �������� ��� �������� ������." << "\n";
        std::cout << "4 - ��������� ������ ���������." << "\n";
        std::cin >> n;
        if (n == 1) {
            temp_file.change_size(123);
            temp_file.change_x(64);
            directory.add_file(temp_file);
            std::cout << "���� ��������." << "\n";
        }
        else if (n == 2) {
            std::cout << "������� ����� ��������� �������� (��������� ����������� � 1): ";
            std::cin >> temp_i;
            directory.del_file(temp_i - 1);
            std::cout << "���� �����";
        }
        else if (n == 3) {
            directory.print_all();
        }
    }
    directory.del_all();
}