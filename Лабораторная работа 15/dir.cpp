#include "dir.h"

void dir::add_file(const executable_file& f) {
	if (next_ind == 0) {
		files = new file * [next_ind + 1];
		file* ptr = new auto(f);
		files[next_ind] = ptr;
		new_ind++;
		next_ind++;
	}
	else {
		copy = new file * [next_ind + 1];
		for (int i = 0; i < next_ind; i++) {
			copy[i] = files[i];
		}
		delete[] files;
		files = new file * [next_ind + 1];
		for (int i = 0; i < next_ind; i++) {
			files[i] = copy[i];
		}
		file* ptr = new auto(f);
		files[next_ind] = ptr;
		delete[] copy;
		next_ind++;
		new_ind++;
	}
}
void dir::add_file(const non_executable_file& f) {
	if (next_ind == 0) {
		files = new file * [next_ind + 1];
		file* ptr = new auto(f);
		files[next_ind] = ptr;
		new_ind++;
		next_ind++;
	}
	else {
		copy = new file * [next_ind + 1];
		for (int i = 0; i < next_ind; i++) {
			copy[i] = files[i];
		}
		delete[] files;
		files = new file * [next_ind + 1];
		for (int i = 0; i < next_ind; i++) {
			files[i] = copy[i];
		}
		file* ptr = new auto(f);
		files[next_ind] = ptr;
		delete[] copy;
		next_ind++;
		new_ind++;
	}
}
void dir::del_file(const int& index) {
	if (next_ind == 1) {
		delete[] files;
		next_ind--;
	}
	else {
		copy = new file * [next_ind];
		for (int i = 0; i < index; i++) {
			copy[i] = files[i];
		}
		for (int i = index; i < next_ind; i++) {
			copy[i] = files[i + 1];
		}
		delete files[index];
		delete[] files;
		files = copy;
		copy = 0;
	}
}
void dir::del_all() {
	if (next_ind != 0) {
		for (int i = 0; i < next_ind; i++) {
			delete files[i];
		}
		delete[] files;
		next_ind = 0;
	}
}
void dir::read_from_file(const std::string& name) {
	del_all();
	std::ifstream f;
	char* temp;
	f.open(name);
	while (!f.eof()) {
		temp = new char[100];
		f.getline(temp, 100);
		add_file_by_str(temp);
		delete[] temp;
	}
	f.close();
}
std::string dir::get_file_to_str(const int& index) const {
	std::stringstream s;
	s << files[index];
	return s.str();
}
void dir::print_all() const {
	for (int i = 0; i < next_ind; i++) {
		std::cout << i + 1 << " " << *(*(files+i)) << "\n";
	}
}
int dir::count_system() const {
	auto count = 0;
	for (int i = 0; i < next_ind; i++) {
		if (files[i]->get_hid() && files[i]->get_sys()) {
			count++;
		}
	}
	return count;
}
file* dir::get_file_by_index(const int& index) const {
	for (int i = 0; i < next_ind; i++) {
		if (files[i]->get_index() == index) {
			return files[i];
		}
	}
}
void dir::add_file_by_str(const std::string& str) {
	if (check_str(str)) {
		std::stringstream s;
		std::regex re("\".+\"");
		std::smatch sm;
		std::string temp;
		std::regex_search(str, sm, re);
		auto i = str.find("\"");
		i = str.find("\"", i + 1);
		std::regex re_temp("\"");
		temp = sm[0];
		std::string name = std::regex_replace(temp, re_temp, "");
		auto i2 = str.find(" ", i + 2);
		temp = str.substr(i + 1, i2 - i);
		s << temp;
		auto index = 0;
		int check = 0;
		s >> check;
		s.clear();
		i = i2;
		i2 = str.find(" ", i + 1);
		temp = str.substr(i + 1, i2 - i);
		s << temp;
		s >> index;
		s.clear();
		int i3 = str.find(" ", i2 + 1);
		s.clear();
		temp = str.substr(i2 + 1, i3 - i2);
		s << temp;
		auto size = 0;
		s >> size;
		auto i4 = str.find(" ", i3 + 1);
		s.clear();
		temp = str.substr(i3 + 1, i4 - i3);
		s << temp;
		auto x = 0;
		s >> x;
		auto i5 = str.find(" ", i4 + 1);
		s.clear();
		temp = str.substr(i4 + 1, i5 - i4);
		s << temp;
		auto hid = false;
		s >> hid;
		auto i6 = str.find(" ", i5 + 1);
		s.clear();
		temp = str.substr(i5 + 1, i6 - i5);
		s << temp;
		auto sys = false;
		s >> sys;
		auto i7 = str.find(" ", i6 + 1);
		temp = str.substr(i6 + 1, i7 - i6);
		s.clear();
		s << temp;
		if (check == 1) {
			size_t_t time;
			s >> time;
			executable_file new_file(x, size, index, sys, hid, name, time);
			add_file(new_file);
		}
		else {
			bool text;
			s >> text;
			non_executable_file nex_file(x, size, index, sys, hid, name, text);
			add_file(nex_file);
		}
	}
}
void dir::print_to_file(const std::string& name) const {
	std::ofstream f;
	f.open(name);
	std::string str;
	for (int i = 0; i < next_ind; i++) {
		str = get_file_to_str(i);
		f << str;
		if (i != next_ind - 1) {
			f << "\n";
		}
	}
	f.close();
}
bool dir::check_str(const std::string& str) const {
	std::regex re("[A-Za-zР-пр-џ0-9\s\!,\?\"\.:;\']*");
	if (!(std::regex_search(str, re))) {
		return false;
	}
	std::regex re_2("\\s{2,}");
	if (std::regex_search(str, re_2)) {
		return false;
	}
	std::regex re_3("[\!\?:\.,\;]{2,}");
	if (std::regex_search(str, re_3)) {
		return false;
	}
	std::regex re_4("[\'\"]{2,}");
	if (std::regex_search(str, re_4)) {
		return false;
	}
	std::regex re_5("^\"[A-ZР-п]");
	if (!std::regex_search(str, re_5)) {
		return false;
	}
	return true;
}
void dir::print_all_with_2_or_more_words() const {
	for (int i = 0; i < next_ind; i++) {
		std::regex re(".+ .+");
		std::string str = files[i]->get_name();
		if (std::regex_search(str, re)) {
			std::cout << i + 1 << " " << *(*(files + i)) << "\n";
		}
	}
}
void dir::sort_files(bool (*f)(file&, file&)) {
	bool check = false;
	file* temp;
	do {
		check = false;
		for (int i = 0; i < next_ind - 1; i++) {
			if (f(*(files[i]), *(files[i + 1]))) {
				temp = files[i];
				files[i] = files[i + 1];
				files[i + 1] = temp;
				check = true;
			}
		}
	} while (check);
}
bool sort_version(file& first, file& second) {
	return (first.get_x() < second.get_x());
}
bool sort_size(file& first, file& second) {
	return (first.get_size() < second.get_size());
}
bool sort_ind(file& first, file& second) {
	return (first.get_index() > second.get_index());
}
bool sort_opt(file& first, file& second) {
	if (((second.get_sys() && second.get_hid()) == true) && ((first.get_sys() && first.get_hid()) != true)) {
		return true;
	}
	else if (((second.get_sys() == false) && (second.get_hid() == true)) && (first.get_hid() != true)) {
		return true;
	}
	else if (((second.get_hid() == false) && (first.get_hid() == false)) && ((second.get_sys() == true) && (first.get_sys() != true))) {
		return true;
	}
	else {
		return false;
	}
}
bool sort_name(file& first, file& second) {
	return (first.get_name() > second.get_name());
} 
std::istream& operator>>(std::istream& is, dir& d) {
	int temp;
	executable_file exetemp;
	non_executable_file nontemp;
	while (is >> temp) {
		if (temp == 1) {
			is >> exetemp;
			if (exetemp.type_of_file != -1) {
				d.add_file(exetemp);
			}
		}
		else {
			is >> nontemp;
			if (nontemp.type_of_file != -1) {
				d.add_file(nontemp);
			}
		}
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, dir& d) {
	for (size_t i = 0; i < d.next_ind; i++) {
		os << *(d[i]) << "\n";
	}
	return os;
}
void count_64::operator()(file f) {
	if (f.get_x() == 64) {
		count++;
	}
}
void count_32::operator()(file f) {
	if (f.get_x() == 32) {
		count++;
	}
}
void count_sys::operator()(file f) {
	if (f.get_sys() == true) {
		count++;
	}
}
void count_hid::operator()(file f) {
	if (f.get_hid() == 64) {
		count++;
	}
}
void print(const file& f) {
	std::cout << f << "\n";
}
void pprint(const std::pair<int, file>& p) {
	std::cout << p.first << " : " << p.second << "\n";
}
void print_64(const file& f) {
	if (f.get_x() == 64) {
		std::cout << f << "\n";
	}
}
void print_32(const file& f) {
	if (f.get_x() == 32) {
		std::cout << f << "\n";
	}
}
void print_sys(const file& f) {
	if (f.get_sys() == true) {
		std::cout << f << "\n";
	}
}
void print_hid(const file& f) {
	if (f.get_hid() == true) {
		std::cout << f << "\n";
	}
}
void pprint_64(const std::pair<int, file>& p) {
	if (p.second.get_x() == 64) {
		std::cout << p.first << " : " << p.second << "\n";
	}
}
void pprint_32(const std::pair<int, file>& p) {
	if (p.second.get_x() == 32) {
		std::cout << p.first << " : " << p.second << "\n";
	}
}
void pprint_sys(const std::pair<int, file>& p) {
	if (p.second.get_sys() == true) {
		std::cout << p.first << " : " << p.second << "\n";
	}
}
void pprint_hid(const std::pair<int, file>& p) {
	if (p.second.get_hid() == true) {
		std::cout << p.first << " : " << p.second << "\n";
	}
}
void ccount_64::operator()(std::pair<int, file> p) {
	if (p.second.get_x() == 64) {
		count++;
	}
}
void ccount_32::operator()(std::pair<int, file> p) {
	if (p.second.get_x() == 32) {
		count++;
	}
}
void ccount_sys::operator()(std::pair<int, file> p) {
	if (p.second.get_sys() == true) {
		count++;
	}
}
void ccount_hid::operator()(std::pair<int, file> p) {
	if (p.second.get_hid() == true) {
		count++;
	}
}
bool sort_by::operator()(file& f1, file& f2) {
	if (type == 1) {
		return f1.get_x() > f2.get_x();
	}
	else if (type == 2) {
		return f1.get_sys() > f2.get_sys();
	}
	else if (type == 3) {
		return f1.get_hid() > f2.get_hid();
	}
	else if (type == 4) {
		return f1.get_index() < f2.get_index();
	}
	else if (type == 5) {
		return f1.get_size() > f2.get_size();
	}
	else if (type == 6) {
		return f1.get_name() < f2.get_name();
	}
	else if (type == 7) {
		return f1.get_x() < f2.get_x();
	}
	else if (type == 8) {
		return f1.get_sys() < f2.get_sys();
	}
	else if (type == 9) {
		return f1.get_hid() < f2.get_hid();
	}
	else if (type == 10) {
		return f1.get_index() > f2.get_index();
	}
	else if (type == 11) {
		return f1.get_size() < f2.get_size();
	}
	else if (type == 12) {
		return f1.get_name() > f2.get_name();
	}
}