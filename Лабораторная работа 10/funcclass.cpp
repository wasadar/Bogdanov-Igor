#include "funcclass.h"

template <typename t> void funcclass::print_to_screen(t* data, int l) {
	std::cout << "Вот ваш массив данных: " << "\n";
	for (int i = 0; i < l; i++) {
		std::cout << i + 1 << " " << data[i] << "\n";
	}
}
template <typename t> int funcclass::find_ind(t* data, int l, t el) {
	for (int i = 0; i < l; i++) {
		if (data[i] == el) {
			return i;
		}
	}
}
template <typename t> void funcclass::sort(t* data, int l, int s) {
	bool check = false;
	if (s >= 0) {
		do {
			check = false;
			for (int i = 0; i < l - 1; i++) {
				if (data[i] < data[i + 1]) {
					std::swap(data[i], data[i + 1]);
					check = true;
				}
			}
		} while (check);
	} 
	else {
		do {
			check = false;
			for (int i = 0; i < l - 1; i++) {
				if (data[i] > data[i + 1]) {
					std::swap(data[i], data[i + 1]);
					check = true;
				}
			}
		} while (check);
	}
}
template <typename t> t funcclass::find_min(t* data, int l) {
	t min = data[0];
	for (int i = 0; i < l; i++) {
		if (min > data[i]) {
			min = data[i];
		}
	}
	return min;
}
template <typename t> t funcclass::find_max(t* data, int l) {
	t max = data[0];
	for (int i = 0; i < l; i++) {
		if (max < data[i]) {
			max = data[i];
		}
	}
	return max;
}
std::ostream& operator<<(std::ostream& os, const drob& d) {
	return os << d.chislitel << "/" << d.znaminaytel;
}
std::istream& operator>>(std::istream& is, drob& d) {
	return is >> d.chislitel >> d.znaminaytel;
}
bool operator==(const drob& d1, const drob& d2) {
	float dr1, dr2;
	dr1 = float(d1.chislitel) / float(d1.znaminaytel);
	dr2 = float(d2.chislitel) / float(d2.znaminaytel);
	if (dr1 == dr2) {
		return true;
	}
	else {
		return false;
	}
}
bool operator!=(const drob& d1, const drob& d2) {
	return !(d1 == d2);
}
bool operator>(const drob& d1, const drob& d2) {
	float dr1, dr2;
	dr1 = float(d1.chislitel) / float(d1.znaminaytel);
	dr2 = float(d2.chislitel) / float(d2.znaminaytel);
	if (dr1 > dr2) {
		return true;
	}
	else {
		return false;
	}
}
bool operator<(const drob& d1, const drob& d2) {
	float dr1, dr2;
	dr1 = float(d1.chislitel) / float(d1.znaminaytel);
	dr2 = float(d2.chislitel) / float(d2.znaminaytel);
	if (dr1 < dr2) {
		return true;
	}
	else {
		return false;
	}
}
drob& drob::operator=(const drob& d) {
	chislitel = d.chislitel;
	znaminaytel = d.znaminaytel;
	return *this;
}
drob::drob(int f, int s) {
	chislitel = f;
	znaminaytel = s;
}
drob::drob() {
	chislitel = 1;
	znaminaytel = 2;
}
void menu() {
	std::cout << "Выберите тип данных который будет использованн в массиве: " << "\n";
	std::cout << "1 - int " << "\n";
	std::cout << "2 - float " << "\n";
	std::cout << "3 - дробное число (кастомный тип данных) " << "\n";
	std::cout << "Введите цисло соответствующее нужному типу данных: ";
	int q, n, t;
	std::cin >> q;
	funcclass f;
	if (q == 1) {
		int* data;
		std::cout << "Введите размер массива: ";
		std::cin >> n;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = i + 1;
		}
		f.print_to_screen(data, n);
		while (true){
			std::cout << "Выберите нужное действие: " << "\n";
			std::cout << "1 - отсортировать массив" << "\n";
			std::cout << "2 - найти минимум или максимум" << "\n";
			std::cout << "3 - получить индекс элемента по его значению" << "\n";
			std::cout << "4 - показать массив" << "\n";
			std::cout << "5 - завершить работу программы" << "\n";
			std::cout << "Введите число соответствующее нужной операции: ";
			std::cin >> q;
			if (q == 1) {
				std::cout << "Выберите направление сортировки 1 - по возрастанию, 2 - по убыванию: ";
				std::cin >> t;
				if (t == 1) {
					f.sort(data, n, -1);
				}
				else if (t == 2) {
					f.sort(data, n, 1);
				}
				else {
					std::cout << "Введите правильное значение" << "\n";
				}
			}
			else if (q == 2) {
				std::cout << "Выберите, что будете искать 1 - минимум, 2 - максимум: ";
				std::cin >> t;
				if (t == 1) {
					std::cout << "Ваш минимум: " << f.find_min(data, n) << "\n";
				}
				else if (t == 2) {
					std::cout << "Ваш максимум: " << f.find_max(data, n) << "\n";
				}
				else {
					std::cout << "Введите правильное значение" << "\n";
				}
			}
			else if (q == 3) {
				std::cout << "Введите нужный элемент: ";
				std::cin >> t;
				std::cout << "Индекс вашего элемента: " << f.find_ind(data, n, t) << "\n";
			}
			else if (q == 4) {
				f.print_to_screen(data, n);
			}
			else {
				delete[] data;
				break;
			}
		}
	}
	else if (q == 2) {
		float* data;
		float g;
		std::cout << "Введите размер массива: ";
		std::cin >> n;
		data = new float[n];
		for (int i = 0; i < n; i++) {
			data[i] = i + 1 + ((i + 1) / 10);
		}
		f.print_to_screen(data, n);
		while (true) {
			std::cout << "Выберите нужное действие: " << "\n";
			std::cout << "1 - отсортировать массив" << "\n";
			std::cout << "2 - найти минимум или максимум" << "\n";
			std::cout << "3 - получить индекс элемента по его значению" << "\n";
			std::cout << "4 - показать массив" << "\n";
			std::cout << "5 - завершить работу программы" << "\n";
			std::cout << "Введите число соответствующее нужной операции: ";
			std::cin >> q;
			if (q == 1) {
				std::cout << "Выберите направление сортировки 1 - по возрастанию, 2 - по убыванию: ";
				std::cin >> t;
				if (t == 1) {
					f.sort(data, n, -1);
				}
				else if (t == 2) {
					f.sort(data, n, 1);
				}
				else {
					std::cout << "Введите правильное значение" << "\n";
				}
			}
			else if (q == 2) {
				std::cout << "Выберите, что будете искать 1 - минимум, 2 - максимум: ";
				std::cin >> t;
				if (t == 1) {
					std::cout << "Ваш минимум: " << f.find_min(data, n) << "\n";
				}
				else if (t == 2) {
					std::cout << "Ваш максимум: " << f.find_max(data, n) << "\n";
				}
				else {
					std::cout << "Введите правильное значение" << "\n";
				}
			}
			else if (q == 3) {
				std::cout << "Введите нужный элемент: ";
				std::cin >> g;
				std::cout << "Индекс вашего элемента: " << f.find_ind(data, n, g) << "\n";
			}
			else if (q == 4) {
				f.print_to_screen(data, n);
			}
			else {
				delete[] data;
				break;
			}
		}
	}
	else if (q == 3) {
		drob* data;
		drob m;
		std::cout << "Введите размер массива: ";
		std::cin >> n;
		data = new drob[n];
		for (int i = 0; i < n; i++) {
			data[i] = drob(i + 1, i + 2);
		}
		f.print_to_screen(data, n);
		while (true) {
			std::cout << "Выберите нужное действие: " << "\n";
			std::cout << "1 - отсортировать массив" << "\n";
			std::cout << "2 - найти минимум или максимум" << "\n";
			std::cout << "3 - получить индекс элемента по его значению" << "\n";
			std::cout << "4 - показать массив" << "\n";
			std::cout << "5 - завершить работу программы" << "\n";
			std::cout << "Введите число соответствующее нужной операции: ";
			std::cin >> q;
			if (q == 1) {
				std::cout << "Выберите направление сортировки 1 - по возрастанию, 2 - по убыванию: ";
				std::cin >> t;
				if (t == 1) {
					f.sort(data, n, -1);
				}
				else if (t == 2) {
					f.sort(data, n, 1);
				}
				else {
					std::cout << "Введите правильное значение" << "\n";
				}
			}
			else if (q == 2) {
				std::cout << "Выберите, что будете искать 1 - минимум, 2 - максимум: ";
				std::cin >> t;
				if (t == 1) {
					std::cout << "Ваш минимум: " << f.find_min(data, n) << "\n";
				}
				else if (t == 2) {
					std::cout << "Ваш максимум: " << f.find_max(data, n) << "\n";
				}
				else {
					std::cout << "Введите правильное значение" << "\n";
				}
			}
			else if (q == 3) {
				std::cout << "Введите нужный элемент, сначала введите числитель в виде целого числа, а потом знаминатель в таком же виде: ";
				std::cin >> m;
				std::cout << "Индекс вашего элемента: " << f.find_ind(data, n, m) << "\n";
			}
			else if (q == 4) {
				f.print_to_screen(data, n);
			}
			else {
				delete[] data;
				break;
			}
		}
	}
}