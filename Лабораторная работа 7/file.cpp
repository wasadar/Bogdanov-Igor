#include "file.h"
 
size_t_t file::get_x() const {
	return x->get_ver();
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
void file::change_x(x_version* new_x) {
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
file::file(x_version* ver, const size_t_t& sz, const size_t_t& ind, const bool& sys, const bool& hid, const std::string& nm) {
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
int x_version::get_ver() const {
	return ver;
}
void x_version::change_ver(const int& x) {
	ver = x;
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
executable_file::executable_file(x_version* x, const size_t_t& sz, const size_t_t& ind, const bool& sys, const bool& hid, const std::string& nm, const size_t_t& time) : file(x, sz, ind, sys, hid, nm), runningtime(time) {
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
non_executable_file::non_executable_file(x_version* x, const size_t_t& sz, const size_t_t& ind, const bool& sys, const bool& hid, const std::string& nm, const bool& text) : file(x, sz, ind, sys, hid, nm), is_text(text) {
	type_of_file = 2;
}
non_executable_file::~non_executable_file() {}
void non_executable_file::change_text(const bool& text) {
	is_text = text;
}
std::string executable_file::get_info() const {
	std::stringstream s;
	s << runningtime;
	return s.str();
}
std::string non_executable_file::get_info() const {
	std::stringstream s;
	s << is_text;
	return s.str();
}