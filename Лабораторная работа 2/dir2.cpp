#include "dir2.h"

void dir::add_file(const file &f) {
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
		files[next_ind].change_index(new_ind);
		next_ind++;
		new_ind++;
	}
}
void dir::del_file(const int &index) {
	if (next_ind == 1) {
		free(files);
		next_ind--;
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
	next_ind = 0;
}
void dir::get_file_to_screen(const int &index) const {
	std::cout << files[index].get_name() << " " << files[index].get_index() << " " << files[index].get_size() << " x" << files[index].get_x() << " " << files[index].get_hid() << " " << files[index].get_sys() << "\n";
}
void dir::print_all() const {
	for (int i = 0; i < next_ind; i++) {
		std::cout << i + 1 << " ";
		get_file_to_screen(i);
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