#include "menu.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    std::cout << "������ � ������� ������� - 1, � ������� ����������� - 2: ";
    int n = 0, temp_i;
    std::cin >> n;
    x_version* x32 = new x_version;
    x32->change_ver(32);
    x_version* x64 = new x_version;
    x64->change_ver(64);
    if (n == 1) {
        dir directory;
        directory.read_from_file("data.txt", x32, x64);
        int s;
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
                directory.add_file_by_str("\"File\" 0 123 64 0 0 \0", x32, x64);
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
                directory.read_from_file("data.txt", x32, x64);
            }
            else if (n == 7) {
                directory.print_to_file("data.txt");
            }
            else if (n == 8) {
                directory.print_all_with_2_or_more_words();
            }
            else if (n == 9) {
                std::cout << "�������� ����� �������� �� �������� ������ ������������� ������: 1 - x, 2 - size, 3 - index, 4 - opt, 5 - name. " << "\n";
                std::cin >> s;
                if (s == 1) {
                    directory.sort_files(sort_version);
                }
                else if (s == 2) {
                    directory.sort_files(sort_size);
                }
                else if (s == 3) {
                    directory.sort_files(sort_ind);
                }
                else if (s == 4) {
                    s = 0;
                    directory.sort_files(sort_opt);
                }
                else if (s == 5) {
                    directory.sort_files(sort_name);
                }
            }
        }
        directory.del_all();
    }
    if (n == 2) {
        sys_dir directory;
        directory.read_from_file("data2.txt", x32, x64);
        int s;
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
                directory.add_file_by_str("\"File\" 0 123 64 0 0 \0", x32, x64);
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
                directory.read_from_file("data2.txt", x32, x64);
            }
            else if (n == 7) {
                directory.print_to_file("data2.txt");
            }
            else if (n == 8) {
                directory.print_all_with_2_or_more_words();
            }
            else if (n == 9) {
                std::cout << "�������� ����� �������� �� �������� ������ ������������� ������: 1 - x, 2 - size, 3 - index, 4 - opt, 5 - name, 6 - exe. " << "\n";
                std::cin >> s;
                if (s == 1) {
                    directory.sort_files(sort_version);
                }
                else if (s == 2) {
                    directory.sort_files(sort_size);
                }
                else if (s == 3) {
                    directory.sort_files(sort_ind);
                }
                else if (s == 4) {
                    s = 0;
                    directory.sort_files(sort_opt);
                }
                else if (s == 5) {
                    directory.sort_files(sort_name);
                }
                else if (s == 6)
                    directory.sort_files(sort_exe);
            }
        }
        directory.del_all();
    }
    delete x32;
    delete x64;
}