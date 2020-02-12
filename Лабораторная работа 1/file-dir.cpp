#include "file-dir.h"
 
int file::get_x() {
	return x_version;
}
int file::get_size() {
	return size;
}
int file::get_index() {
	return index;
}
void file::change_x(int x) {
	x_version = x;
}
void file::change_size(int sz) {
	size = sz;
}

void file::change_index(int in) {
	index = in;
}

void dir::add_file(file f) {
	if (next_ind == 0) {
		files = (file*)malloc(sizeof(file));
		files[next_ind] = f;
		files[next_ind].change_index(new_ind);
		new_ind++;
		next_ind++;
	}
	else {
		copy = (file*)malloc(sizeof(file) * (next_ind + 1));
		for (int i = 0; i < next_ind; i++) {
			copy[i] = files[i];
		}
		free(files);
		files = (file*)malloc(sizeof(file) * (next_ind + 1));
		for (int i = 0; i < next_ind; i++) {
			files[i] = copy[i];
		}
		free(copy);
		files[next_ind] = f;
		files[next_ind].change_index(new_ind+1);
		next_ind++;
	}
}
void dir::del_file(int index) {
	if (next_ind == 1) {
		free(files);
	}
	else {
		copy = (file*)malloc(sizeof(file) * (next_ind - 1));
		for (int i = 0; i < index; i++) {
			copy[i] = files[i];
		}
		for (int i = index + 1; i < next_ind; i++) {
			copy[i - 1] = files[i];
		}
		free(files);
		files = (file*)malloc(sizeof(file) * (next_ind - 1));
		for (int i = 0; i < next_ind; i++) {
			files[i] = copy[i];
		}
		free(copy);
		next_ind--;
	}
}
void dir::del_all() {
	free(files);
}
void dir::get_file_to_screen(int index) {
	std::cout << files[index].get_index() << " " << files[index].get_size() << " x" << files[index].get_x() << "\n";
}
void dir::print_all() {
	for (int i = 0; i < next_ind; i++) {
		std::cout << i + 1 << " ";
		get_file_to_screen(i);
	}
}