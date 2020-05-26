#pragma once 
#include "file.h"

class dir { /** Клас - массив. */
private:
	file** files;
	file** copy;
	int next_ind = 0;
	int new_ind = 1;
public:
	void add_file(const executable_file& f);
	void add_file(const non_executable_file& f);
	void del_file(const int& index);
	void del_all();
	void add_file_by_str(const std::string& str);
	void read_from_file(const std::string& name);
	std::string get_file_to_str(const int& index) const;
	file* get_file_by_index(const int& index) const;
	void print_all() const;
	int count_system() const;
	void print_to_file(const std::string& name) const;
	bool check_str(const std::string& str) const;
	void print_all_with_2_or_more_words() const;
	void sort_files(bool (*f)(file&, file&));
	file* operator[](const int& index) {
		return files[index];
	}
	friend std::ostream& operator<<(std::ostream& on, dir& d);
};
struct count_64 {
	count_64() { count = 0; }
	void operator()(file f);
	int count;
};
struct count_32 {
	count_32() { count = 0; }
	void operator()(file f);
	int count;
};
struct count_sys {
	count_sys() { count = 0; }
	void operator()(file f);
	int count;
};
struct count_hid {
	count_hid() { count = 0; }
	void operator()(file f);
	int count;
};
struct ccount_64 {
	ccount_64() { count = 0; }
	void operator()(std::pair<int, file> p);
	int count;
};
struct ccount_32 {
	ccount_32() { count = 0; }
	void operator()(std::pair<int, file> p);
	int count;
};
struct ccount_sys {
	ccount_sys() { count = 0; }
	void operator()(std::pair<int,file> p);
	int count;
};
struct ccount_hid {
	ccount_hid() { count = 0; }
	void operator()(std::pair<int, file> p);
	int count;
};

bool sort_version(file&, file&);
bool sort_size(file&, file&);
bool sort_ind(file&, file&);
bool sort_opt(file&, file&);
bool sort_name(file&, file&);
std::istream& operator>>(std::istream& is, dir& d);
std::ostream& operator<<(std::ostream& os, dir& d);
void print(const file& f);
void pprint(const std::pair<int, file>& p);
void print_64(const file& f);
void print_32(const file& f);
void print_sys(const file& f);
void print_hid(const file& f);
void pprint_64(const std::pair<int,file>& p);
void pprint_32(const std::pair<int, file>& p);
void pprint_sys(const std::pair<int, file>& p);
void pprint_hid(const std::pair<int, file>& p);
