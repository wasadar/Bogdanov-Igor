#pragma once
#include <string>
#include <iostream>

class file {
private:
	std::string name;
	std::string file_extension;
	int size;
	int index;
public:
	std::string get_name() {
		return name;
	}
	std::string get_extension() {
		return file_extension;
	}
	std::string get_full_name() {
		return name + "." + file_extension;
	}
	int get_size() {
		return size;
	}
	int get_index() {
		return index;
	}
	void change_name(std::string str) {
		name = str;
	}
	void change_size(int sz) {
		size = sz;
	}
	void change_extension(std::string ex) {
		file_extension = ex;
	}
	void change_index(int in) {
		index = in;
	}
}; 
 
class dir {
private:
	file* files;
	int last_ind;
public:
	void add_file(file f) {
		if (files == nullptr) {
			files = (file*)malloc(sizeof(file) * 1);
			files[0] = f;
			last_ind = 0;
		}
		else if (files != nullptr) {
			files = (file*)realloc(files, sizeof(files) + sizeof(file));
			last_ind++;
			files[last_ind] = f;
		}
	}
	void del_file(int index) {
		if (last_ind != 0) {
			int ind = index;
			while (ind != last_ind) {
				files[ind] = files[ind + 1];
				ind++;
			}
			files = (file*)realloc(files, sizeof(files) - sizeof(file));
			last_ind--;
		}
		else {
			free(files);
		}
	}
	void get_file_to_screen(int index) {
		std::cout << files[index].get_full_name << " " << files[index].get_size;
	}
	void print_all() {
		for (int i = 0; i <= last_ind; i++) {
			std::cout << i << " ";
			get_file_to_screen(i);
		}
	}
}; 
 
void menu();