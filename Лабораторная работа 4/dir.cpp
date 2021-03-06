#include "dir.h"

void dir::add_file(const file &f) {
	if (next_ind == 0) {
		files = new file[1];
		files[next_ind] = f;
		files[next_ind].change_index(new_ind);
		new_ind++;
		next_ind++;
	}
	else {
		copy = new file[next_ind];
		for (int i = 0; i < next_ind; i++) {
			copy[i] = files[i];
		}
		delete[] files;
		files = new file[next_ind + 1];
		for (int i = 0; i < next_ind; i++) {
			files[i] = copy[i];
		}
		delete[] copy;
		files[next_ind] = f;
		files[next_ind].change_index(new_ind);
		next_ind++;
		new_ind++;
	}
}
void dir::del_file(const int &index) {
	if (next_ind == 1) {
		delete[] files;
		next_ind--;
	}
	else {
		copy = new file[next_ind - 1];
		for (int i = 0; i < index; i++) {
			copy[i] = files[i];
		}
		for (int i = index, j = index + 1; i < (next_ind - 1), j < next_ind; i++, j++) {
			copy[i] = files[j];
		}
		delete[] files;
		files = new file[next_ind - 1];
		for (int i = 0; i < next_ind - 1; i++) {
			files[i] = copy[i];
		}
		delete[] copy;
		next_ind--;
	}
}
void dir::del_all() {
	if (next_ind != 0) {
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
std::string dir::get_file_to_str(const int &index) const {
	std::stringstream s;
	s << "\"" << files[index].get_name() << "\" " << files[index].get_index() << " " << files[index].get_size() << " " << files[index].get_x() << " " << files[index].get_hid() << " " << files[index].get_sys();
	return s.str();
}
void dir::print_all() const {
	for (int i = 0; i < next_ind; i++) {
		std::cout << i + 1 << " ";
		std::string str;
		str = get_file_to_str(i);
		std::cout << str << "\n";
	}
}
int dir::count_system() const {
	int count = 0;
	for (int i = 0; i < next_ind; i++) {
		if (files[i].get_hid() && files[i].get_sys()) {
			count++;
		}
	}
	return count;
}
file dir::get_file_by_index(const int& index) const {
	for (int i = 0; i < next_ind; i++) {
		if (files[i].get_index() == index) {
			return files[i];
		}
	}
}
void dir::add_file_by_str(const std::string& str) {
	if (check_str(str)) {
		std::regex re("\".+\"");
		std::smatch sm;
		std::regex_search(str, sm, re);
		int i = str.find("\"");
		i = str.find("\"", i + 1);
		std::regex re_temp("\"");
		std::string temp = sm[0];
		std::string name = std::regex_replace(temp, re_temp, "");
		int i2 = str.find(" ", i + 2);
		temp = str.substr(i + 1, i2 - i);
		std::stringstream s;
		s << temp;
		int index = 0;
		s >> index;
		int i3 = str.find(" ", i2 + 1);
		s.clear();
		temp = str.substr(i2 + 1, i3 - i2);
		s << temp;
		int size = 0;
		s >> size;
		int i4 = str.find(" ", i3 + 1);
		s.clear();
		temp = str.substr(i3 + 1, i4 - i3);
		s << temp;
		int x = 0;
		s >> x;
		int i5 = str.find(" ", i4 + 1);
		s.clear();
		temp = str.substr(i4 + 1, i5 - i4);
		s << temp;
		bool hid = false;
		s >> hid;
		int i6 = str.find(" ", i5 + 1);
		s.clear();
		temp = str.substr(i5 + 1, i6 - i5);
		s << temp;
		bool sys = false;
		s >> sys;
		file new_file(x, size, index, sys, hid, name);
		add_file(new_file);
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
	std::regex re("[A-Za-z�-��-�0-9\s\!,\?\"\.:;\']*");
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
	std::regex re_5("^\"[A-Z�-�]");
	if (!std::regex_search(str, re_5)) {
		return false;
	}
	return true;
}
void dir::print_all_with_2_or_more_words() const {
	for (int i = 0; i < next_ind; i++) {
		std::string str;
		str = get_file_to_str(i);
		std::regex re("\".+ .+\"");
		if (std::regex_search(str, re)) {
			std::cout << i + 1 << " " << str << "\n";
		}
	}
}