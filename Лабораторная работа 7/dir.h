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
	void add_file_by_str(const std::string& str, x_version*, x_version*);
	void read_from_file(const std::string& name, x_version*, x_version*);
	std::string get_file_to_str(const int& index) const;
	file* get_file_by_index(const int& index) const;
	void print_all() const;
	int count_system() const;
	void print_to_file(const std::string& name) const;
	bool check_str(const std::string& str) const;
	void print_all_with_2_or_more_words() const;
	void sort_files(bool (*f)(file&, file&));
};

bool sort_version(file&, file&);
bool sort_size(file&, file&);
bool sort_ind(file&, file&);
bool sort_opt(file&, file&);
bool sort_name(file&, file&);