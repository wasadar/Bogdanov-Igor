#include "menu.h"

void old_menu() {
    setlocale(LC_ALL, "Russian"); 
    int n = 0, temp_i;
    dir directory;
    std::ifstream f("data.txt");
    std::ofstream d;
    f >> directory;
    f.close();
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
            directory.add_file_by_str("\"File\" 0 123 64 0 0 \0");
            std::cout << "���� ��������." << "\n";
        }
        else if (n == 2) {
            std::cout << "������� ����� ��������� �������� (��������� ����������� � 1): ";
            std::cin >> temp_i;
            directory.del_file(temp_i - 1);
            std::cout << "���� �����. " << "\n";
        }
        else if (n == 3) {
            std::cout << directory;
        }
        else if (n == 5) {
            std::cout << "���������� ������� ��������� ������: " << directory.count_system() << "\n";
        }
        else if (n == 6) {
            f.open("data.txt");
            f >> directory;
            f.close();
        }
        else if (n == 7) {
            d.open("data.txt");
            d << directory;
            d.close();
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
void menu() {
    setlocale(LC_ALL, "Russian");
    int n, w;
    std::cout << "�������� � ����� ����� ���������� ����� �������� ��������� �� ���� ���: " << "\n";
    std::cout << "1 - vector" << "\n";
    std::cout << "2 - list" << "\n";
    std::cout << "3 - map" << "\n";
    std::cout << "4 - set" << "\n";
    std::cout << "������� ����� ��������������� ������������ ����������: ";
    std::cin >> n;
    if (n == 1) {
        int q = 0;
        std::vector<file> vect;
        executable_file exetemp;
        non_executable_file nontemp;
        std::ifstream f("data.txt");
        while (f >> n) {
            if (n == 1) {
                f >> exetemp;
                vect.push_back(exetemp);
                vect[q].change_index(q);
            }
            else {
                f >> nontemp;
                vect.push_back(nontemp);
                vect[q].change_index(q);
            }
            q++;
        }
        f.close();
        std::cout << "������ ������� �� ����� � ������.\n";
        while (true) {
            std::cout << "�������� ���������� ��������: " << "\n";
            std::cout << "1 - ������� ������ �� �����.\n";
            std::cout << "2 - ������� ������ �� ����� � ������.\n";
            std::cout << "3 - �������� ������� � ������.\n";
            std::cout << "4 - ������� ������� �� ������� �� �������.\n";
            std::cout << "5 - ������� ���� ������� ������� �� �������.\n";
            std::cout << "6 - ��������� ������ ���������.\n";
            std::cout << "������� �����, ��� ������������� ������������ ��������: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "��� ������ �������: \n";
                for (int i = 0; i < q; i++) {
                    std::cout << vect[i] << "\n";
                }
            }
            else if (n == 2) {
                vect.clear();
                f.open("data.txt");
                q = 0;
                while (f >> w) {
                    if (n == 1) {
                        f >> exetemp;
                        vect.push_back(exetemp);
                        vect[q].change_index(q);
                    }
                    else {
                        f >> nontemp;
                        vect.push_back(nontemp);
                        vect[q].change_index(q);
                    }
                    q++;
                }
                f.close();
                std::cout << "������ ������� �� ����� � ������.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                vect.push_back(non);
                vect[q].change_index(q);
                q++;
                std::cout << "������� �������� � ������.\n";
            }
            else if (n == 4) {
                std::cout << "������� ������ ���������� ��������: ";
                std::cin >> w;
                if (w < q) {
                    for (int i = w; i < (q - 1); i++) {
                        vect[i] = vect[i + 1];
                        vect[i].change_index(i);
                    }
                    vect.pop_back();
                    q--;
                    std::cout << "������� � ������ �������� ����� �� �������.\n";
                }
                else {
                    std::cout << "������� ���������� ������.\n";
                }
            }
            else if (n == 5) {
                std::cout << "������� ������ ������� ��������:";
                std::cin >> w;
                if (w < q) {
                    std::cout << "��� ������ � �������� � ������ ��������:\n";
                    std::cout << vect[w] << "\n";
                }
                else {
                    std::cout << "������� ���������� ������.\n";
                }
            }
            else{
                break;
            }
        }
    }
    else if (n == 2) {
        bool check;
        std::string name;
        std::list<file> lst;
        executable_file exetemp;
        non_executable_file nontemp;
        std::ifstream f("data.txt");
        while (f >> n) {
            if (n == 1) {
                f >> exetemp;
                lst.push_back(exetemp);
            }
            else {
                f >> nontemp;
                lst.push_back(nontemp);
            }
        }
        f.close();
        std::cout << "������ ������� �� ����� � ������.\n";
        while (true) {
            std::cout << "�������� ���������� ��������: " << "\n";
            std::cout << "1 - ������� ������ �� �����.\n";
            std::cout << "2 - ������� ������ �� ����� � ������.\n";
            std::cout << "3 - �������� ������� � ������.\n";
            std::cout << "4 - ������� ������� �� ������ �� ��� ��������.\n";
            std::cout << "5 - �������� ������� �� ������ �� ��� ��������.\n";
            std::cout << "6 - ��������� ������ ���������.\n";
            std::cout << "������� �����, ��� ������������� ������������ ��������: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "��� ������ ������: \n";
                std::copy(lst.begin(), lst.end(), std::ostream_iterator<file>(std::cout, " \n"));
            }
            else if (n == 2) {
                lst.clear();
                f.open("data.txt");
                while (f >> n) {
                    if (n == 1) {
                        f >> exetemp;
                        lst.push_back(exetemp);
                    }
                    else {
                        f >> nontemp;
                        lst.push_back(nontemp);
                    }
                }
                f.close();
                std::cout << "������ ������� �� ����� � ������.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                lst.push_back(non);
                std::cout << "������� �������� � ������.\n";
            }
            else if (n == 4) {
                std::cout << "������� �������� ���������� ��������: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                check = false;
                for (auto el : lst) {
                    if (el.get_name() == name) {
                        lst.remove(el);
                        check = true;
                        break;
                    }
                }
                if (check) {
                    std::cout << "������� �����.\n";
                }
                else {
                    std::cout << "������ �������� ���.\n";
                }
            }
            else if (n == 5) {
                std::cout << "������� �������� ������� ��������: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                check = true;
                for (auto el : lst) {
                    if (el.get_name() == name) {
                        std::cout << "��� ������ �������: ";
                        std::cout << el << "\n";
                        check = false;
                        break;
                    }
                }
                if (check) {
                    std::cout << "������ �������� ���.\n";
                }
            }
            else {
                break;
            }
        }
    }
    else if (n == 3) {
        int q = 0;
        bool check;
        std::map<int, file> mp;
        executable_file exetemp;
        non_executable_file nontemp;
        std::ifstream f("data.txt");
        while (f >> n) {
            if (n == 1) {
                f >> exetemp;
                mp.insert(std::pair<int, file>(q++, exetemp));
            }
            else {
                f >> nontemp;
                mp.insert(std::pair<int, file>(q++, nontemp));
            }
        }
        f.close();
        std::cout << "������ ������� �� ����� � ���������.\n";
        while (true) {
            std::cout << "�������� ���������� ��������: " << "\n";
            std::cout << "1 - ������� ���������� ���������� �� �����.\n";
            std::cout << "2 - ������� ������ �� ����� � ���������.\n";
            std::cout << "3 - �������� ������� � ���������.\n";
            std::cout << "4 - ������� ������� �� ���������� �� ��� �����.\n";
            std::cout << "5 - �������� ������� �� ���������� �� ��� �����.\n";
            std::cout << "6 - ��������� ������ ���������.\n";
            std::cout << "������� �����, ��� ������������� ������������ ��������: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "��� ������ ������ ����������: \n";
                for (auto el : mp) {
                    std::cout << el.first << " : " << el.second << "\n";
                }
            }
            else if (n == 2) {
                mp.clear();
                f.open("data.txt");
                while (f >> n) {
                    if (n == 1) {
                        f >> exetemp;
                        mp.insert(std::pair<int, file>(q++, exetemp));
                    }
                    else {
                        f >> nontemp;
                        mp.insert(std::pair<int, file>(q++, nontemp));
                    }
                }
                f.close();
                std::cout << "������ ������� �� ����� � ���������.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                mp.insert(std::pair<int, file>(q++, non));
                std::cout << "������� �������� � ���������.\n";
            }
            else if (n == 4) {
                std::cout << "������� �������� ���� ���������� ��������: ";
                std::cin >> w;
                check = false;
                for (auto el : mp) {
                    if (el.first == w) {
                        mp.erase(w);
                        check = true;
                        break;
                    }
                }
                if (check) {
                    std::cout << "������� ����� �� ����������.\n";
                }
                else {
                    std::cout << "�������� ����.\n";
                }
            }
            else if (n == 5) {
                std::cout << "������� �������� ���� ������� ��������: ";
                std::cin >> w;
                check = true;;
                for (auto el : mp) {
                    if (el.first == w) {
                        std::cout << "��� ������ ������� ��������: " << el.second << "\n";
                        check = false;
                        break;
                    }
                }
                if (check) {
                    std::cout << "�������� ����.\n";
                }
            }
            else {
                break;
            }
        }
    }
    else if (n == 4) {
        bool check;
        std::string name;
        std::set<file> st;
        executable_file exetemp;
        non_executable_file nontemp;
        std::ifstream f("data.txt");
        while (f >> n) {
            if (n == 1) {
                f >> exetemp;
                st.insert(exetemp);
            }
            else {
                f >> nontemp;
                st.insert(nontemp);
            }
        }
        f.close();
        std::cout << "������ ������� �� ����� � ���������.\n";
        while (true) {
            std::cout << "�������� ���������� ��������: " << "\n";
            std::cout << "1 - ������� ���������� ��������� �� �����.\n";
            std::cout << "2 - ������� ������ �� ����� � ���������.\n";
            std::cout << "3 - �������� ������� � ���������.\n";
            std::cout << "4 - ������� ������� �� ��������� �� ��������.\n";
            std::cout << "5 - �������� ������� �� ��������� �� ��������.\n";
            std::cout << "6 - ��������� ������ ���������.\n";
            std::cout << "������� �����, ��� ������������� ������������ ��������: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "��� ������ �� ������ ���������: \n";
                for (auto el : st) {
                    std::cout << el << "\n";
                }
            }
            else if (n == 2) {
                st.clear();
                f.open("data.txt");
                while (f >> n) {
                    if (n == 1) {
                        f >> exetemp;
                        st.insert(exetemp);
                    }
                    else {
                        f >> nontemp;
                        st.insert(nontemp);
                    }
                }
                f.close();
                std::cout << "������ ������� �� ����� � ���������.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                st.insert(non);
                std::cout << "������� �������� � ���������.\n";
            }
            else if (n == 4) {
                std::cout << "������� �������� ���������� ��������: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                check = false;
                for (auto el : st) {
                    if (el.get_name() == name) {
                        st.erase(el);
                        check = true;;
                        break;
                    }
                }
                if (check) {
                    std::cout << "������� ��� ����� �� ���������.\n";
                }
                else {
                    std::cout << "�������� � ����� ��������� � ��������� ���.\n";
                }
            }
            else if (n == 5) {
                std::cout << "������� �������� ������� ��������: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                check = true;
                for (auto el : st) {
                    if (el.get_name() == name) {
                        std::cout << "��� ��� �������: ";
                        std::cout << el << "\n";
                        check = false;
                        break;
                    }
                }
                if (check) {
                    std::cout << "�������� � ����� ��������� � ��������� ���.\n";
                }
            }
            else {
                break;
            }
        }
    }
}