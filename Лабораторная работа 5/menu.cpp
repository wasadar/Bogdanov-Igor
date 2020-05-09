#include "menu.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    int n = 0, temp_i;
    dir directory;
    x_version* x32 = new x_version;
    x32->change_ver(32);
    x_version* x64 = new x_version;
    x64->change_ver(64);
    directory.read_from_file("data.txt",x32,x64);
    int s;
    int m;
    while (n != 4) {
        std::cout << "�������� �������� �����:" << "\n";
        std::cout << "1 - �������� ������� � ������." << "\n";
        std::cout << "2 - ������� ������� �� ������." << "\n";
        std::cout << "3 - �������� ��� �������� ������." << "\n";
        std::cout << "4 - ��������� ������ ���������." << "\n";
        std::cout << "5 - ��������� ���������� ������� ��������� ������." << "\n";
        std::cout << "6 - ��������� ������ �� �����. " << "\n";
        std::cout << "7 - �������� ������� ������ ������ � ����. " << "\n";
        std::cout << "8 - ����� ��� ������� � �������� ������� ���� 2 ��� ������ �����. " << "\n";
        std::cout << "9 - ������������� ������. " << "\n";
        std::cin >> n;
        if (n == 1) {
            directory.add_file_by_str("\"File\" 0 123 64 0 0 \0",x32,x64);
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
            directory.read_from_file("data.txt",x32,x64);
        }
        else if (n == 7) {
            directory.print_to_file("data.txt");
        }
        else if (n == 8) {
            directory.print_all_with_2_or_more_words();
        }
        else if (n == 9) {
            std::cout << "�������� ������� ����������. 1 - �� �� �������� � �� �������� � ��������, 2 - ��������. " << "\n";
            std::cin >> m;
            std::cout << "�������� ����� �������� �� �������� ������ ������������� ������: 1 - x, 2 - size, 3 - index, 4 - opt, 5 - name. " << "\n";
            std::cin >> s;
            if ((s == 1) and (m == 1)) {
                directory.sort_files(sort_version);
            }
            else if ((s == 1) and (m == 2)) {
                directory.sort_files(sort_version_2);
            }
            else if ((s == 2) and (m == 1)) {
                directory.sort_files(sort_size);
            }
            else if ((s == 2) and (m == 2)) {
                directory.sort_files(sort_size_2);
            }
            else if ((s == 3) and (m == 1)) {
                directory.sort_files(sort_ind);
            }
            else if ((s == 3) and (m == 2)) {
                directory.sort_files(sort_ind_2);
            }
            else if ((s == 4) and (m == 1)) {
                directory.sort_files(sort_opt);
            }
            else if ((s == 4) and (m == 2)) {
                directory.sort_files(sort_opt_2);
            }
            else if ((s == 5) and (m == 1)) {
                directory.sort_files(sort_name);
            }
            else if ((s == 5) and (m == 2)) {
                directory.sort_files(sort_name_2);
            }
        }
    }
    directory.del_all();
    delete x32;
    delete x64;
}