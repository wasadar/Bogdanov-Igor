#pragma once 
#include "file2.h"
 
class dir {
private:
	file* files;
	file* copy;
	int next_ind = 0;
	int new_ind = 1;
public:
	void add_file(const file &f);
	void del_file(const int &index);
	void del_all();
	void get_file_to_screen(const int &index) const;
	void print_all() const;
	int count_system() const;
};