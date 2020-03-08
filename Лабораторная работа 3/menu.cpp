#include "menu.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    int n = 0, temp_i;
    dir directory;
    directory.read_from_file("data.txt");
    while (n != 4) {
        std::cout << "�������� �������� �����:" << "\n";
        std::cout << "1 - �������� ������� � ������." << "\n";
        std::cout << "2 - ������� ������� �� ������." << "\n";
        std::cout << "3 - �������� ��� �������� ������." << "\n";
        std::cout << "4 - ��������� ������ ���������." << "\n";
        std::cout << "5 - ��������� ���������� ������� ��������� ������." << "\n";
        std::cout << "6 - ��������� ������ �� �����. " << "\n";
        std::cout << "7 - �������� ������� ������ ������ � ����. " << "\n";
        std::cin >> n;
        if (n == 1) {
            directory.add_file_by_str("file 0 123 64 0 0 \0");
            std::cout << "���� ��������." << "\n";
        }
        else if (n == 2) {
            std::cout << "������� ����� ��������� �������� (��������� ����������� � 1): ";
            std::cin >> temp_i;
            directory.del_file(temp_i - 1);
            std::cout << "���� �����. " << "\n";
        }
        else if (n == 3) {
            directory.print_all();
        }
        else if (n == 5) {
            std::cout << "���������� ������� ��������� ������: " << directory.count_system() << "\n";
        }
        else if (n == 6) {
            directory.read_from_file("data.txt");
        }
        else if (n == 7) {
            directory.print_to_file("data.txt");
        }
    }
    directory.del_all();
}