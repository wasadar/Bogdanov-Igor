#include "file-dir.h"
 
void menu() {
    int n, temp_i;
    dir directory;
    std::string temp;
    file temp_file;
    while (n != 4) {
        std::cout << "�������� �������� �����:" << "\n";
        std::cout << "1 - �������� ������� � ������." << "\n";
        std::cout << "2 - ������� ������� �� ������." << "\n";
        std::cout << "3 - �������� ��� �������� ������." << "\n";
        std::cout << "4 - ��������� ������ ���������." << "\n";
        std::cin >> n;
        if (n == 1) {
            std::cout << "������� ������ � ����� ��������." << "\n";
            std::cout << "��� �����: ";
            std::cin >> temp;
            temp_file.change_name(temp);
            std::cout << "���������� (��� �����): ";
            std::cin >> temp;
            temp_file.change_extension(temp);
            std::cout << "��� �����: ";
            std::cin >> temp_i;
            temp_file.change_size(temp_i);
            std::cout << "������: ";
            std::cin >> temp_i;
            temp_file.change_index(temp_i);
            directory.add_file(temp_file);
            std::cout << "���� ��������." << "\n";
        }
        else if (n == 2) {
            std::cout << "������� ����� ��������� �������� (��������� ����������� � 0): ";
            std::cin >> temp_i;
            directory.del_file(temp_i);
            std::cout << "���� �����";
        }
        else if (n == 3) {
            directory.print_all();
        }
    }
}