#include "func.h"
std::string get_str_from_user() {
	std::string str;
	std::cin >> str;
	return str;
}
int** read_data_from_file(std::string name) {
	std::ifstream in(name);
	if (!(in.is_open())) {
		throw 1;
	}
	else {
		int n;
		int t;
		int r;
		int** res;
		in >> n;
		res = new int* [n + 1];
		res[0] = new int;
		res[0][0] = n;
		for (int i = 1; i <= n; i++) {
			in >> t;
			res[i] = new int[t + 1];
			res[i][0] = t;
			for (int u = 1; u <= t; u++) {
				in >> r;
				res[i][u] = r;
			}
		}
		in.close();
		return res;
	}
}
void print_data_to_file(int** data, std::string name) {
	std::ofstream of(name);
	if (data == nullptr) {
		throw 'c';
	}
	else if (!(of.is_open())) {
		throw 1;
	} 
	else {
		of << data[0][0] << "\n";
		for (int i = 1; i <= data[0][0]; i++) {
			of << data[i][0] << " ";
			for (int u = 1; u <= data[i][0]; u++) {
				of << data[i][u] << " ";
			}
			if (i != data[0][0]) {
				of << "\n";
			}
		}
		of.close();
	}
}
int* find_max(int** data) {
	if (data == nullptr) {
		throw 1;
	} 
	else {
		int* res = new int[data[0][0] + 1];
		res[0] = data[0][0];
		for (int i = 1; i <= data[0][0]; i++) {
			res[i] = get_elem_by_ind(data, i - 1, 0);
			for (int u = 1; u <= data[i][0]; u++) {
				if (res[i] < get_elem_by_ind(data, i - 1, u - 1)) {
					res[i] = get_elem_by_ind(data, i - 1, u - 1);
				}
			}
		}
		return res;
	}
}
int get_elem_by_ind(int** data, int ind1, int ind2) {
	if (data == nullptr) {
		throw 1;
	} 
	else {
		if (ind1 >= data[0][0]) {
			throw std::out_of_range("Out of range");
		}
		else if (ind2 >= data[ind1 + 1][0]) {
			throw std::out_of_range("Out of range");
		}
		else {
			return data[ind1 + 1][ind2 + 1];
		}
	}
}
void get_data_to_screen(int** data) {
	if (data == nullptr) {
		throw 1;
	}
	else {
		for (int i = 1; i <= data[0][0]; i++) {
			for (int u = 1; u <= data[i][0]; u++) {
				std::cout << get_elem_by_ind(data, i - 1, u - 1) << " ";
			}
			std::cout << "\n";
		}
	}
}
void get_data_to_screen(int* data) {
	for (int i = 1; i <= data[0]; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << "\n";
} 
void menu() {
	std::string str;
	std::stringstream temp;
	int n = 0;
	int** data = 0;
	int i;
	int u;
	bool m;
	std::string nmout;
	std::string nmin;
	while (true) {
		std::cout << "Выберите желаемое действие: " << "\n";
		std::cout << "1 - ввести название файла (с расширением) для чтения информации." << "\n";
		std::cout << "2 - ввести название файла (с расширением) для записи информации." << "\n";
		std::cout << "3 - вывести массивы на экран." << "\n";
		std::cout << "4 - считать данные из файла." << "\n";
		std::cout << "5 - записать данные в файл." << "\n";
		std::cout << "6 - создать массив из максимальных элементов всех массивов." << "\n";
		std::cout << "7 - получить элемент по индексам." << "\n";
		std::cout << "Что бы завершить работу программы выберите первый пункт и напишите \"\\exit\"." << "\n";
		std::cout << "Введите цифру, соответствующую нужному действию - ";
		std::cin >> str;
		try
		{
			n = std::stoi(str);
		}
		catch (std::invalid_argument const& e)
		{
			std::cout << "Введите число." << '\n';
		}
		catch (std::out_of_range const& e)
		{
			std::cout << "Введите число." << '\n';
		}
		if (n == 1) {
			std::cout << "Введите название файла: ";
			nmin = get_str_from_user();
			if (nmin == "\\exit") {
				break;
			}
		}
		else if (n == 2) {
			std::cout << "Введите название файла: ";
			nmout = get_str_from_user();
		}
		else if (n == 3) {
			try {
				std::cout << "Вот ваши массивы:" << "\n";
				get_data_to_screen(data);
			}
			catch (std::out_of_range) {
				std::cout << "Ошибка в данных массива по-пробуйте считать его заново." << "\n";
			}
			catch (int) {
				std::cout << "Нет массива, попробуйте считать его с файла." << "\n";
			}
		}
		else if (n == 4) {
			try {
				clean_data(data);
				data = read_data_from_file(nmin);
				std::cout << "Данные считаны из файла." << "\n";
			}
			catch (int) {
				std::cout << "Файла с таким названием нет или вы не ввели его название, попробуйте использовать другой файл." << "\n";
			} 
		}
		else if (n == 5) {
			try {
				print_data_to_file(data, nmout);
				std::cout << "Данные записаны в файл." << "\n";
			}
			catch (int) {
				std::cout << "Файла с таким названием нет или вы не ввели его название, попробуйте использовать другой файл." << "\n";
			}
			catch (char) {
				std::cout << "Нет массива, попробуйте считать его с файла." << "\n";
			}
		}
		else if (n == 6) {
			try {
				int* maxmass;
				maxmass = find_max(data);
				std::cout << "Вот максимальные элементы массивов:" << "\n";
				get_data_to_screen(maxmass);
				delete[] maxmass;
			}
			catch (std::out_of_range) {
				std::cout << "Ошибка в данных массива по-пробуйте считать его заново." << "\n";
			}
			catch (int) {
				std::cout << "Нет массива, попробуйте считать его с файла." << "\n";
			}
		}
		else if (n == 7) {
			try {
				std::cout << "Введите индекс массива и индекс элемента: ";
				std::cin >> i >> u;
				std::cout << "Вот элемент с нужными индексами: " << get_elem_by_ind(data, i, u) << "\n";
			}
			catch (std::out_of_range) {
				std::cout << "Ошибка в индексах попробуйте ввести их снова." << "\n";
			}
			catch (int) {
				std::cout << "Нет массива, попробуйте считать его с файла." << "\n";
			}
		}
	}
	clean_data(data);
}
void clean_data(int** data) {
	if (data != nullptr) {
		for (int i = 1; i <= data[0][0]; i++) {
			delete[] data[i];
		}
		delete[] data[0];
		delete[] data;
	}
}