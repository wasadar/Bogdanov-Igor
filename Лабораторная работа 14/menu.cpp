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
        std::cout << "Выберите желаемую опцию:" << "\n";
        std::cout << "1 - добавить элемент в список." << "\n";
        std::cout << "2 - удалить элемент из списка." << "\n";
        std::cout << "3 - показать все элементы списка." << "\n";
        std::cout << "4 - завершить работу программы." << "\n";
        std::cout << "5 - посчитать количество скрытых системных файлов." << "\n";
        std::cout << "6 - прочитать данные из файла. " << "\n";
        std::cout << "7 - записать текущий список данных в файл. " << "\n";
        std::cout << "8 - найти все элеметы в названии которых есть 2 или больше слова. " << "\n";
        std::cout << "9 - отсортировать массив. " << "\n";
        std::cin >> n;
        if (n == 1) {
            directory.add_file_by_str("\"File\" 0 123 64 0 0 \0");
            std::cout << "Файл добавлен." << "\n";
        }
        else if (n == 2) {
            std::cout << "Введите номер удалемого элемента (нумерация начинаеться с 1): ";
            std::cin >> temp_i;
            directory.del_file(temp_i - 1);
            std::cout << "Файл удалён. " << "\n";
        }
        else if (n == 3) {
            std::cout << directory;
        }
        else if (n == 5) {
            std::cout << "Количество скрытых системных файлов: " << directory.count_system() << "\n";
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
            std::cout << "Ввведите номер признака по которому хотите отсортировать массив: 1 - x, 2 - size, 3 - index, 4 - opt, 5 - name. " << "\n";
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
    std::cout << "Выберите с каким типом контейнера будет работать программа на этот раз: " << "\n";
    std::cout << "1 - vector" << "\n";
    std::cout << "2 - list" << "\n";
    std::cout << "3 - map" << "\n";
    std::cout << "4 - set" << "\n";
    std::cout << "Введите цифру соответствующею необходимому контейнеру: ";
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
        std::cout << "Данные считаны из файла в вектор.\n";
        while (true) {
            std::cout << "Выберите дальнейшие действия: " << "\n";
            std::cout << " 1 - вывести вектор на экран.\n";
            std::cout << " 2 - считать данные из файла в вектор.\n";
            std::cout << " 3 - добавить элемент в вектор.\n";
            std::cout << " 4 - удалить элемент из вектора по индексу.\n";
            std::cout << " 5 - вывести один элемент вектора по индексу.\n";
            std::cout << " 6 - посчитать количество элементов с заданным параметром.\n";
            std::cout << " 7 - вывести все элементы с заданным параметром.\n";
            std::cout << " 8 - сортировка вектора по заданному параметру.\n";
            std::cout << " 9 - считать данные из файла в новый вектор и объединить 2 вектора.\n";
            std::cout << "10 - завершить работу программы.\n";
            std::cout << "Введите число, что соответствует необходимому действию: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Вот данные вектора: \n";
                std::for_each(vect.begin(), vect.end(), print);
            }
            else if (n == 2) {
                vect.clear();
                f.open("data.txt");
                q = 0;
                while (f >> w) {
                    if (w == 1) {
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
                std::cout << "Данные считаны из файла в вектор.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                vect.push_back(non);
                vect[q].change_index(q);
                q++;
                std::cout << "Елемент добавлен в вектор.\n";
            }
            else if (n == 4) {
                std::cout << "Введите индекс удаляемого элемента: ";
                std::cin >> w;
                if (w < q) {
                    for (int i = w; i < (q - 1); i++) {
                        vect[i] = vect[i + 1];
                        vect[i].change_index(i);
                    }
                    vect.pop_back();
                    q--;
                    std::cout << "Элемент с данным индексом удалён из вектора.\n";
                }
                else {
                    std::cout << "Введите правильный индекс.\n";
                }
            }
            else if (n == 5) {
                std::cout << "Введите индекс нужного элемента:";
                std::cin >> w;
                if (w < q) {
                    std::cout << "Вот данные о элементе с данным индексом:\n";
                    std::cout << vect[w] << "\n";
                }
                else {
                    std::cout << "Введите правильный индекс.\n";
                }
            }
            else if (n == 6) {
                std::cout << "Выберите параметр элементы с которым будут посчитаны: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    count_64 c = std::for_each(vect.begin(), vect.end(), count_64());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 2) {
                    count_32 c = std::for_each(vect.begin(), vect.end(), count_32());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 3) {
                    count_sys c = std::for_each(vect.begin(), vect.end(), count_sys());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 4) {
                    count_hid c = std::for_each(vect.begin(), vect.end(), count_hid());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 7) {
                std::cout << "Выберите параметр элементы с которым будут выведены на экран: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(vect.begin(), vect.end(), print_64);
                }
                else if (n == 2) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(vect.begin(), vect.end(), print_32);
                }
                else if (n == 3) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(vect.begin(), vect.end(), print_sys);
                }
                else if (n == 4) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(vect.begin(), vect.end(), print_hid);
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 8) {
                std::cout << "Выберите параметр по которому элементы будут отсортированы: \n";
                std::cout << "1 - битность системы.\n";
                std::cout << "2 - системность файлов.\n";
                std::cout << "3 - являються ли файлы скрытыми.\n";
                std::cout << "4 - индекс файлов.\n";
                std::cout << "5 - размер файлов.\n";
                std::cout << "6 - название файла.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    std::cout << "Выберите какие файлы будут сначала 64-битные (1) или 32-битные (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        std::sort(vect.begin(), vect.end(), sort_by(1));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        std::sort(vect.begin(), vect.end(), sort_by(7));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 2) {
                    std::cout << "Выберите какие файлы будут сначала системные (1) или не системные (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        std::sort(vect.begin(), vect.end(), sort_by(2));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        std::sort(vect.begin(), vect.end(), sort_by(8));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 3) {
                    std::cout << "Выберите какие файлы будут сначала скрытые (1) или не скрытые (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        std::sort(vect.begin(), vect.end(), sort_by(3));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        std::sort(vect.begin(), vect.end(), sort_by(9));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 4) {
                    std::cout << "Выберите как будут отсортированы файлы по возрастанию индекса (1) или по убыванию (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        std::sort(vect.begin(), vect.end(), sort_by(4));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        std::sort(vect.begin(), vect.end(), sort_by(10));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 5) {
                    std::cout << "Выберите как будут отсортированы файлы по убыванию размера (1) или по возрастанию (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        std::sort(vect.begin(), vect.end(), sort_by(5));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        std::sort(vect.begin(), vect.end(), sort_by(11));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 6) {
                    std::cout << "Выберите какие файлы будут сначала алфавитный порядок (1) или обратный алфавитному (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        std::sort(vect.begin(), vect.end(), sort_by(6));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        std::sort(vect.begin(), vect.end(), sort_by(12));
                        std::cout << "Вектор отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else {
                    std::cout << "Такого варианта нет.\n";
                }
            }
            else if (n == 9) {  
                std::vector<file> tempv;
                f.open("data.txt");
                int r = 0;
                while (f >> w) {
                    if (w == 1) {
                        f >> exetemp;
                        tempv.push_back(exetemp);
                        tempv[r].change_index(r);
                    }
                    else {
                        f >> nontemp;
                        tempv.push_back(nontemp);
                        tempv[r].change_index(r);
                    }
                    r++;
                }
                for (int i = r - 1; !(i < 0); i--) {
                    vect.push_back(tempv[i]);
                    vect[q].change_index(q);
                    q++;
                    tempv.pop_back();
                }
                std::cout << "Данные считаны из файла в вектор. И оба вектора объеденены.\n";
            }
            else {
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
        std::cout << "Данные считаны из файла в список.\n";
        while (true) {
            std::cout << "Выберите дальнейшие действия: " << "\n";
            std::cout << "1 - вывести список на экран.\n";
            std::cout << "2 - считать данные из файла в список.\n";
            std::cout << "3 - добавить элемент в список.\n";
            std::cout << "4 - удалить элемент из списка по его названию.\n";
            std::cout << "5 - получить элемент из списка по его названию.\n";
            std::cout << "6 - посчитать количество элементов с заданным параметром.\n";
            std::cout << "7 - вывести все элементы с заданным параметром.\n";
            std::cout << "8 - отсортировать список по заданному параметру.\n";
            std::cout << "9 - завершить работу программы.\n";
            std::cout << "Введите число, что соответствует необходимому действию: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Вот данные списка: \n";
                std::for_each(lst.begin(), lst.end(), print);
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
                std::cout << "Данные считаны из файла в список.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                lst.push_back(non);
                std::cout << "Элемент добавлен в список.\n";
            }
            else if (n == 4) {
                std::cout << "Введите название удаляемого элемента: ";
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
                    std::cout << "Элемент удалён.\n";
                }
                else {
                    std::cout << "Такого элемента нет.\n";
                }
            }
            else if (n == 5) {
                std::cout << "Введите название нужного элемента: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                check = true;
                for (auto el : lst) {
                    if (el.get_name() == name) {
                        std::cout << "Вот нужный элемент: ";
                        std::cout << el << "\n";
                        check = false;
                        break;
                    }
                }
                if (check) {
                    std::cout << "Такого элемента нет.\n";
                }
            }
            else if (n == 6) {
                std::cout << "Выберите параметр элементы с которым будут посчитаны: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    count_64 c = std::for_each(lst.begin(), lst.end(), count_64());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 2) {
                    count_32 c = std::for_each(lst.begin(), lst.end(), count_32());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 3) {
                    count_sys c = std::for_each(lst.begin(), lst.end(), count_sys());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 4) {
                    count_hid c = std::for_each(lst.begin(), lst.end(), count_hid());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 7) {
                std::cout << "Выберите параметр элементы с которым будут выведены на экран: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(lst.begin(), lst.end(), print_64);
                }
                else if (n == 2) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(lst.begin(), lst.end(), print_32);
                }
                else if (n == 3) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(lst.begin(), lst.end(), print_sys);
                }
                else if (n == 4) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(lst.begin(), lst.end(), print_hid);
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 8) {
                std::cout << "Выберите параметр по которому элементы будут отсортированы: \n";
                std::cout << "1 - битность системы.\n";
                std::cout << "2 - системность файлов.\n";
                std::cout << "3 - являються ли файлы скрытыми.\n";
                std::cout << "4 - индекс файлов.\n";
                std::cout << "5 - размер файлов.\n";
                std::cout << "6 - название файла.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    std::cout << "Выберите какие файлы будут сначала 64-битные (1) или 32-битные (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        lst.sort(sort_by(1));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        lst.sort(sort_by(7));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 2) {
                    std::cout << "Выберите какие файлы будут сначала системные (1) или не системные (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        lst.sort(sort_by(2));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        lst.sort(sort_by(8));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 3) {
                    std::cout << "Выберите какие файлы будут сначала скрытые (1) или не скрытые (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        lst.sort(sort_by(3));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        lst.sort(sort_by(9));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 4) {
                    std::cout << "Выберите какие файлы будут сначала больший индекс (1) или меньший индекс (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        lst.sort(sort_by(4));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        lst.sort(sort_by(10));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 5) {
                    std::cout << "Выберите какие файлы будут сначала больший файл (1) или меньший файл (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        lst.sort(sort_by(5));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        lst.sort(sort_by(11));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else if (n == 6) {
                    std::cout << "Выберите какие файлы будут сначала алфавитный порядок (1) или обратный алфавитному (2): ";
                    std::cin >> n;
                    if (n == 1) {
                        lst.sort(sort_by(6));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else if (n == 2) {
                        lst.sort(sort_by(12));
                        std::cout << "Список отсортирован по заданному критерию.\n";
                    }
                    else {
                        std::cout << "Такого варианта нет.\n";
                    }
                }
                else {
                    std::cout << "Такого варианта нет.\n";
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
        std::multimap<int, file> mp;
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
        std::cout << "Данные считаны из файла в контейнер.\n";
        while (true) {
            std::cout << "Выберите дальнейшие действия: " << "\n";
            std::cout << "1 - вывести содержимое контейнера на экран.\n";
            std::cout << "2 - считать данные из файла в контейнер.\n";
            std::cout << "3 - добавить элемент в контейнер.\n";
            std::cout << "4 - удалить элемент из контейнера по его ключу.\n";
            std::cout << "5 - получить элемент из контейнера по его ключу.\n";
            std::cout << "6 - посчитать количество элементов с заданным параметром.\n";
            std::cout << "7 - вывести все элементы с заданным параметром.\n";
            std::cout << "8 - считать данные из файла в новый контейнер и объеденить контейнеры.\n";
            std::cout << "9 - завершить работу программы.\n";
            std::cout << "Введите число, что соответствует необходимому действию: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Вот данные вашего контейнера: \n";
                std::for_each(mp.begin(), mp.end(), pprint);
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
                std::cout << "Данные считаны из файла в контейнер.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                mp.insert(std::pair<int, file>(q++, non));
                std::cout << "Элемент добавлен в контейнер.\n";
            }
            else if (n == 4) {
                std::cout << "Введите числовой ключ удаляемого элемента: ";
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
                    std::cout << "Элемент удалён из контейнера.\n";
                }
                else {
                    std::cout << "Неверный ключ.\n";
                }
            }
            else if (n == 5) {
                std::cout << "Введите числовой ключ нужного элемента: ";
                std::cin >> w;
                check = true;;
                for (auto el : mp) {
                    if (el.first == w) {
                        std::cout << "Вот данные нужного элемента: " << el.second << "\n";
                        check = false;
                        break;
                    }
                }
                if (check) {
                    std::cout << "Неверный ключ.\n";
                }
            }
            else if (n == 6) {
                std::cout << "Выберите параметр элементы с которым будут посчитаны: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    ccount_64 c = std::for_each(mp.begin(), mp.end(), ccount_64());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 2) {
                    ccount_32 c = std::for_each(mp.begin(), mp.end(), ccount_32());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 3) {
                    ccount_sys c = std::for_each(mp.begin(), mp.end(), ccount_sys());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 4) {
                    ccount_hid c = std::for_each(mp.begin(), mp.end(), ccount_hid());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 7) {
                std::cout << "Выберите параметр элементы с которым будут выведены на экран: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(mp.begin(), mp.end(), pprint_64);
                }
                else if (n == 2) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(mp.begin(), mp.end(), pprint_32);
                }
                else if (n == 3) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(mp.begin(), mp.end(), pprint_sys);
                }
                else if (n == 4) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(mp.begin(), mp.end(), pprint_hid);
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 8) {
                std::multimap<int, file> tempm;
                int k = 0;
                f.open("data.txt");
                while (f >> n) {
                    if (n == 1) {
                        f >> exetemp;
                        tempm.insert(std::pair<int, file>(k++, exetemp));
                    }
                    else {
                        f >> nontemp;
                        tempm.insert(std::pair<int, file>(k++, nontemp));
                    }
                }
                f.close();
                for (auto el : tempm) {
                    check = true;
                    for (auto le : mp) {
                        if (el == le) {
                            check = false;
                        }
                    }
                    if (check) {
                        mp.insert(el);
                    }
                }
                std::cout << "Данные считаны из файла в дополнительный контейнер. Затем, основной и дополнительный контейнеры объеденены.\n";
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
        std::cout << "Данные считаны из файла в множество.\n";
        while (true) {
            std::cout << "Выберите дальнейшие действия: " << "\n";
            std::cout << "1 - вывести содержимое множества на экран.\n";
            std::cout << "2 - считать данные из файла в множество.\n";
            std::cout << "3 - добавить элемент в множество.\n";
            std::cout << "4 - удалить элемент из множества по названию.\n";
            std::cout << "5 - получить элемент из множества по названию.\n";
            std::cout << "6 - посчитать количество элементов с заданным параметром.\n";
            std::cout << "7 - вывести все элементы с заданным параметром.\n";
            std::cout << "8 - завершить работу программы.\n";
            std::cout << "Введите число, что соответствует необходимому действию: ";
            std::cin >> n;
            if (n == 1) {
                std::cout << "Вот данные из вашего множества: \n";
                std::for_each(st.begin(), st.end(), print);
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
                std::cout << "Данные считаны из файла в множество.\n";
            }
            else if (n == 3) {
                non_executable_file non(32, 123, 0, false, false, "text", true);
                st.insert(non);
                std::cout << "Элемент добавлен в множество.\n";
            }
            else if (n == 4) {
                std::cout << "Введите название удаляемого элемента: ";
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
                    std::cout << "Элемент был удалён из множества.\n";
                }
                else {
                    std::cout << "Элемента с таким названием в множестве нет.\n";
                }
            }
            else if (n == 5) {
                std::cout << "Введите название нужного элемента: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                check = true;
                for (auto el : st) {
                    if (el.get_name() == name) {
                        std::cout << "Вот ваш элемент: ";
                        std::cout << el << "\n";
                        check = false;
                        break;
                    }
                }
                if (check) {
                    std::cout << "Элемента с таким названием в множестве нет.\n";
                }
            }
            else if (n == 6) {
                std::cout << "Выберите параметр элементы с которым будут посчитаны: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    count_64 c = std::for_each(st.begin(), st.end(), count_64());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 2) {
                    count_32 c = std::for_each(st.begin(), st.end(), count_32());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 3) {
                    count_sys c = std::for_each(st.begin(), st.end(), count_sys());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else if (n == 4) {
                    count_hid c = std::for_each(st.begin(), st.end(), count_hid());
                    std::cout << "Найдено " << c.count << " элементов с заданным параметром.\n";
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else if (n == 7) {
                std::cout << "Выберите параметр элементы с которым будут выведены на экран: \n";
                std::cout << "1 - 64-битные файлы.\n";
                std::cout << "2 - 32-битные файлы.\n";
                std::cout << "3 - системные файлы.\n";
                std::cout << "4 - скрытые файлы.\n";
                std::cout << "Введите значение соответствующее нужному параметру: ";
                std::cin >> n;
                if (n == 1) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(st.begin(), st.end(), print_64);
                }
                else if (n == 2) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(st.begin(), st.end(), print_32);
                }
                else if (n == 3) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(st.begin(), st.end(), print_sys);
                }
                else if (n == 4) {
                    std::cout << "Вот данные о элементах с заданной характеристикой:\n";
                    std::for_each(st.begin(), st.end(), print_hid);
                }
                else {
                    std::cout << "Такого параметра нет.\n";
                }
            }
            else {
                break;
            }
        }
    }
}