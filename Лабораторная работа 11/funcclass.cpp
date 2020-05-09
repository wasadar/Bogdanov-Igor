#include "funcclass.h"

template <typename t> void funcclass<t>::print_to_screen() {
	std::cout << "��� ��� ������ ������: " << "\n";
	for (int i = 0; i < this->len; i++) {
		std::cout << i + 1 << " " << *(data[i]) << "\n";
	}
}
template <typename t> int funcclass<t>::find_ind(t el) {
	for (int i = 0; i < this->len; i++) {
		if (*(data[i]) == el) {
			return i;
		}
	}
}
template <typename t> void funcclass<t>::sort(int s) {
	bool check = false;
	if (s >= 0) {
		do {
			check = false;
			for (int i = 0; i < this->len - 1; i++) {
				if (*(data[i]) < *(data[i + 1])) {
					std::swap(*(data[i]), *(data[i + 1]));
					check = true;
				}
			}
		} while (check);
	} 
	else {
		do {
			check = false;
			for (int i = 0; i < this->len - 1; i++) {
				if (*(data[i]) > *(data[i + 1])) {
					std::swap(*(data[i]), *(data[i + 1]));
					check = true;
				}
			}
		} while (check);
	}
}
template <typename t> t funcclass<t>::find_min() {
	t min = *(data[0]);
	for (int i = 0; i < this->len; i++) {
		if (min > *(data[i])) {
			min = *(data[i]);
		}
	}
	return min;
}
template <typename t> t funcclass<t>::find_max() {
	t max = *(data[0]);
	for (int i = 0; i < this->len; i++) {
		if (max < *(data[i])) {
			max = *(data[i]);
		}
	}
	return max;
}
std::ostream& operator<<(std::ostream& os, const drob& d) {
	return os << d.chislitel << "/" << d.znaminaytel << " " << d.get_char();
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
drob2& drob2::operator=(const drob2& d) {
	chislitel = d.chislitel;
	znaminaytel = d.znaminaytel;
	c = d.c;
	return *this;
}
drob2::drob2(int f, int s, char c): drob(f,s), c(c) {}
drob2::drob2() : drob(), c('c') {}
std::ostream& operator<<(std::ostream& os, const drob2& d) {
	return os << d.chislitel << "/" << d.znaminaytel << " " << d.get_char();
}
std::istream& operator>>(std::istream& is, drob2& d) {
	return is >> d.chislitel >> d.znaminaytel >> d.c;
}
bool operator==(const drob2& d1, const drob2& d2) {
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
bool operator!=(const drob2& d1, const drob2& d2) {
	return !(d1 == d2);
}
bool operator>(const drob2& d1, const drob2& d2) {
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
bool operator<(const drob2& d1, const drob2& d2) {
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
char drob::get_char() const {
	return 'd';
}
char drob2::get_char() const{
	return this->c;
}
void menu() {
	std::cout << "�������� ��� ������ ������� ����� ������������ � �������: " << "\n";
	std::cout << "1 - int " << "\n";
	std::cout << "2 - ������� ����� (��������� ��� ������) " << "\n";
	std::cout << "������� ����� ��������������� ������� ���� ������: ";
	int q, n, t;
	std::cin >> q;
	if (q == 1) {
		funcclass<int> d;
		std::cout << "������� ������ �������: ";
		std::cin >> n;
		d.data = new int*[n];
		d.len = n;
		for (int i = 0; i < n; i++) {
			d.data[i] = new int(i + 1);
		}
		d.print_to_screen();
		while (true){
			std::cout << "�������� ������ ��������: " << "\n";
			std::cout << "1 - ������������� ������" << "\n";
			std::cout << "2 - ����� ������� ��� ��������" << "\n";
			std::cout << "3 - �������� ������ �������� �� ��� ��������" << "\n";
			std::cout << "4 - �������� ������" << "\n";
			std::cout << "5 - ��������� ������ ���������" << "\n";
			std::cout << "������� ����� ��������������� ������ ��������: ";
			std::cin >> q;
			if (q == 1) {
				std::cout << "�������� ����������� ���������� 1 - �� �����������, 2 - �� ��������: ";
				std::cin >> t;
				if (t == 1) {
					d.sort(-1);
				}
				else if (t == 2) {
					d.sort(1);
				}
				else {
					std::cout << "������� ���������� ��������" << "\n";
				}
			}
			else if (q == 2) {
				std::cout << "��������, ��� ������ ������ 1 - �������, 2 - ��������: ";
				std::cin >> t;
				if (t == 1) {
					std::cout << "��� �������: " << d.find_min() << "\n";
				}
				else if (t == 2) {
					std::cout << "��� ��������: " << d.find_max() << "\n";
				}
				else {
					std::cout << "������� ���������� ��������" << "\n";
				}
			}
			else if (q == 3) {
				std::cout << "������� ������ �������: ";
				std::cin >> t;
				std::cout << "������ ������ ��������: " << d.find_ind(t) << "\n";
			}
			else if (q == 4) {
				d.print_to_screen();
			}
			else {
				for (int i = 0; i < n; i++) {
					delete[] d.data[i];
				}
				delete[] d.data;
				break;
			}
		}
	}
	else if (q == 2) {
		funcclass<drob> d;
		drob m;
		std::cout << "������� ������ �������: ";
		std::cin >> n;
		d.data = new drob*[n];
		d.len = n;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				d.data[i] = new drob(i + 1, i + 2);
			}
			else {
				d.data[i] = new drob2(i + 1, i + 2, 'c');
			}
		}
		d.print_to_screen();
		while (true) {
			std::cout << "�������� ������ ��������: " << "\n";
			std::cout << "1 - ������������� ������" << "\n";
			std::cout << "2 - ����� ������� ��� ��������" << "\n";
			std::cout << "3 - �������� ������ �������� �� ��� ��������" << "\n";
			std::cout << "4 - �������� ������" << "\n";
			std::cout << "5 - ��������� ������ ���������" << "\n";
			std::cout << "������� ����� ��������������� ������ ��������: ";
			std::cin >> q;
			if (q == 1) {
				std::cout << "�������� ����������� ���������� 1 - �� �����������, 2 - �� ��������: ";
				std::cin >> t;
				if (t == 1) {
					d.sort(-1);
				}
				else if (t == 2) {
					d.sort(1);
				}
				else {
					std::cout << "������� ���������� ��������" << "\n";
				}
			}
			else if (q == 2) {
				std::cout << "��������, ��� ������ ������ 1 - �������, 2 - ��������: ";
				std::cin >> t;
				if (t == 1) {
					std::cout << "��� �������: " << d.find_min() << "\n";
				}
				else if (t == 2) {
					std::cout << "��� ��������: " << d.find_max() << "\n";
				}
				else {
					std::cout << "������� ���������� ��������" << "\n";
				}
			}
			else if (q == 3) {
				std::cout << "������� ������ �������, ������� ������� ��������� � ���� ������ �����, � ����� ����������� � ����� �� ����: ";
				std::cin >> m;
				std::cout << "������ ������ ��������: " << d.find_ind(m) << "\n";
			}
			else if (q == 4) {
				d.print_to_screen();
			}
			else {
				for (int i = 0; i < n; i++) {
					delete[] d.data[i];
				}
				delete[] d.data;
				break;
			}
		}
	}
}