#include "file.h"
 
size_t_t file::get_x() const {
	return x;
}
size_t_t file::get_size() const {
	return size;
}
size_t_t file::get_index() const {
	return index;
}
bool file::get_sys() const {
	return opt.get_sys();
}
bool file::get_hid() const {
	return opt.get_hid();
}
std::string file::get_name() const {
	return name;
}
void file::change_x(const size_t_t& new_x) {
	x = new_x;
}
void file::change_size(const size_t_t& sz) {
	size = sz;
}
void file::change_index(const size_t_t& in) {
	index = in;
}
void file::change_sys(const bool& sys) {
	opt.change_sys(sys);
}
void file::change_hid(const bool& hid) {
	opt.change_hid(hid);
}
void file::change_name(const std::string& nm) {
	name = nm;
}
file::file() {
	x = 0;
	size = 100;
	index = 0;
	opt.change_hid(false);
	opt.change_sys(false);
	name = "File";
	std::cout << "Файл создан при помощи конструктора поумолчанию." << "\n";
}
file::file(const file& f) {
	x = f.x;
	size = f.size;
	index = f.index;
	opt = f.opt;
	name = f.name;
}
file::file(const size_t_t& ver, const size_t_t& sz, const size_t_t& ind, const bool& sys, const bool& hid, const std::string& nm) {
	x = ver;
	size = sz;
	index = ind;
	opt.change_sys(sys);
	opt.change_hid(hid);
	name = nm;
	std::cout << "Файл создан при помощи конструктора с аргументами." << "\n";
}
file::~file() {
	std::cout << "Файл уничтожен при помощи деструктора поумолчанию." << "\n";
}
bool options::get_sys() const {
	return issystem;
}
bool options::get_hid() const {
	return ishidden;
}
void options::change_sys(const bool& sys) {
	issystem = sys;
}
void options::change_hid(const bool& hid) {
	ishidden = hid;
}
size_t_t executable_file::get_time() const {
	return runningtime;
}
executable_file::executable_file() : file(), runningtime(0) {
	type_of_file = 1;
}
executable_file::executable_file(const executable_file& sf) : file(sf), runningtime(sf.runningtime) {
	type_of_file = 1;
}
executable_file::executable_file(const size_t_t& x, const size_t_t& sz, const size_t_t& ind, const bool& sys, const bool& hid, const std::string& nm, const size_t_t& time) : file(x, sz, ind, sys, hid, nm), runningtime(time) {
	type_of_file = 1;
}
executable_file::~executable_file() {}
void executable_file::change_time(const size_t_t& time) {
	runningtime = time;
}
bool non_executable_file::get_text() const {
	return is_text;
}
non_executable_file::non_executable_file() : file(), is_text(true) {
	type_of_file = 2;
}
non_executable_file::non_executable_file(const non_executable_file& nf) : file(nf), is_text(nf.is_text) {
	type_of_file = 2;
}
non_executable_file::non_executable_file(const size_t_t& x, const size_t_t& sz, const size_t_t& ind, const bool& sys, const bool& hid, const std::string& nm, const bool& text) : file(x, sz, ind, sys, hid, nm), is_text(text) {
	type_of_file = 2;
}
non_executable_file::~non_executable_file() {}
void non_executable_file::change_text(const bool& text) {
	is_text = text;
}
std::string executable_file::get_info() const {
	std::stringstream s;
	s << type_of_file << " " << "\"" << name << "\" " << index << " " << size << " " << x << " " << opt.get_hid() << " " << opt.get_sys() << " " << runningtime;
	return s.str();
}
std::string non_executable_file::get_info() const {
	std::stringstream s;
	s << type_of_file << " " << "\"" << name << "\" " << index << " " << size << " " << x << " " << opt.get_hid() << " " << opt.get_sys() << " " << is_text;
	return s.str();
}
bool operator==(const file& f1, const file& f2) {
	if (f1.get_name() != f2.get_name()) {
		return false;
	}
	else if (f1.get_sys() != f2.get_sys()) {
		return false;
	}
	else if (f1.get_size() != f2.get_size()) {
		return false;
	}
	else if (f1.get_hid() != f2.get_hid()) {
		return false;
	}
	else if (f1.get_x() != f2.get_x()) {
		return false;
	}
	else if (f1.get_index() != f2.get_index()) {
		return false;
	}
	else {
		return true;
	}
}
bool operator!=(const file& f1, const file& f2) {
	return !(f1 == f2);
}
bool operator==(const executable_file& f1, const executable_file& f2) {
	if (f1.get_name() != f2.get_name()) {
		return false;
	}
	else if (f1.get_sys() != f2.get_sys()) {
		return false;
	}
	else if (f1.get_size() != f2.get_size()) {
		return false;
	}
	else if (f1.get_hid() != f2.get_hid()) {
		return false;
	}
	else if (f1.get_x() != f2.get_x()) {
		return false;
	}
	else if (f1.get_index() != f2.get_index()) {
		return false;
	}
	else if (f1.get_time() != f2.get_time()) {
		return false;
	}
	else {
		return true;
	}
}
bool operator!=(const executable_file& f1, const executable_file& f2) {
	return !(f1 == f2);
}
bool operator==(const non_executable_file& f1, const non_executable_file& f2) {
	if (f1.get_name() != f2.get_name()) {
		return false;
	}
	else if (f1.get_sys() != f2.get_sys()) {
		return false;
	}
	else if (f1.get_size() != f2.get_size()) {
		return false;
	}
	else if (f1.get_hid() != f2.get_hid()) {
		return false;
	}
	else if (f1.get_x() != f2.get_x()) {
		return false;
	}
	else if (f1.get_index() != f2.get_index()) {
		return false;
	}
	else if (f1.get_text() != f2.get_text()) {
		return false;
	}
	else {
		return true;
	}
}
bool operator!=(const non_executable_file& f1, const non_executable_file& f2) {
	return !(f1 == f2);
}
bool check_str(const std::string& str){
	std::regex re("[A-Za-zА-Яа-я0-9\s\!,\?\"\.:;\']*");
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
	return true;
}
std::ostream& operator<<(std::ostream& os, const file& f) {
	return os << f.get_info();
}
std::ostream& operator<<(std::ostream& os, const executable_file& f) {
	return os << f.get_info();
}
std::ostream& operator<<(std::ostream& os, const non_executable_file& f) {
	return os << f.get_info();
}
std::istream& operator>>(std::istream& is, executable_file& f) {
	std::string name;
	std::string temp;
	std::regex re("\"$");
	std::stringstream temps;
	executable_file tempf;
	bool check = true;
	bool global_check = true;
	do {
		is >> temp;
		if (check_str(temp)) {
			name += temp;
		}
		else {
			global_check = false;
		}
		if (std::regex_search(name, re)) {
			check = false;
		}
		else {
			name += " ";
		}
	} while (check);
	std::regex r("\"");
	name = std::regex_replace(name, r, "");
	tempf.change_name(name);
	int temp_i = 0;
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_index(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_size(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_x(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_hid(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_sys(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_time(temp_i);
	if (global_check == true) {
		f = tempf;
	}
	else {
		f.type_of_file = -1;
	}
	return is;
}
std::istream& operator>>(std::istream& is, non_executable_file& f) {
	std::string name;
	std::string temp;
	std::regex re("\"$");
	std::stringstream temps;
	non_executable_file tempf;
	bool check = true;
	bool global_check = true;
	do {
		is >> temp;
		if (check_str(temp)) {
			name += temp;
		}
		else {
			global_check = false;
		}
		if (std::regex_search(name, re)) {
			check = false;
		}
		else {
			name += " ";
		}
	} while (check);
	std::regex r("\"");
	name = std::regex_replace(name, r, "");
	tempf.change_name(name);
	int temp_i = 0;
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_index(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_size(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_x(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_hid(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_sys(temp_i);
	is >> temp;
	if (!check_str(temp)) {
		global_check = false;
	}
	temps << temp;
	temps >> temp_i;
	temps.clear();
	tempf.change_text(temp_i);
	if (global_check == true) {
		f = tempf;
	}
	else {
		f.type_of_file = -1;
	}
	return is;
}
file& file::operator=(const file& f) {
	x = f.x;
	size = f.size;
	index = f.index;
	name = f.name;
	opt.change_sys(f.get_sys());
	opt.change_hid(f.get_hid());
	return *this;
}
executable_file& executable_file::operator=(const executable_file& f) {
	x = f.x;
	size = f.size;
	index = f.index;
	name = f.name;
	opt.change_sys(f.get_sys());
	opt.change_hid(f.get_hid());
	runningtime = f.runningtime;
	return *this;
}
non_executable_file& non_executable_file::operator=(const non_executable_file& f) {
	x = f.x;
	size = f.size;
	index = f.index;
	name = f.name;
	opt.change_sys(f.get_sys());
	opt.change_hid(f.get_hid());
	is_text = f.is_text;
	return *this;
}
std::string file::get_info() const {
	std::stringstream s;
	s << type_of_file << " " << "\"" << name << "\" " << index << " " << size << " " << x << " " << opt.get_hid() << " " << opt.get_sys();
	return s.str();
}
bool operator>(const file& f1, const file& f2) {
	return f1.get_name() < f2.get_name();
}
bool operator<(const file& f1, const file& f2) {
	return f1.get_name() > f2.get_name();
}
bool operator>(const executable_file& f1, const executable_file& f2) {
	return f1.get_name() < f2.get_name();
}
bool operator<(const executable_file& f1, const executable_file& f2) {
	return f1.get_name() > f2.get_name();
}
bool operator>(const non_executable_file& f1, const non_executable_file& f2) {
	return f1.get_name() < f2.get_name();
}
bool operator<(const non_executable_file& f1, const non_executable_file& f2) {
	return f1.get_name() > f2.get_name();
}