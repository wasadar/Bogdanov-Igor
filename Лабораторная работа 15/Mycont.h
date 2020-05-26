#pragma once
#include "Mypointer.h"
#include <memory>

template <typename t> class My_lst1;
template <typename t> class My_lst1_el;
template <typename t> class My_lst1_iter;
template <typename t> class My_lst2;
template <typename t> class My_lst2_el;
template <typename t> class My_lst2_iter;
template <typename t> class My_lst3;
template <typename t> class My_lst3_el;
template <typename t> class My_lst3_iter;
template <typename t> class My_lst1 {
private:
	std::shared_ptr<My_lst1_el<t>> head;
public:
	My_lst1();
	void add_el(t new_el);
	void del_el(t del_el);
	void clear();
	template <class compare> void sort(compare cmp);
	My_lst1_iter<t> begin();
	My_lst1_iter<t> end();
};
template <typename t> class My_lst1_el {
public:
	std::shared_ptr<My_lst1_el<typename t>> next;
	std::unique_ptr<t> value;
};
template <typename t> class My_lst1_iter {
private:
    std::shared_ptr<My_lst1_el<t>> current_el;
public:
    My_lst1_iter(std::shared_ptr<My_lst1_el<t>> head) : current_el(head) {}
	void operator++();
	t operator *();
    bool operator== (My_lst1_iter<t>& right);
	bool operator!= (My_lst1_iter<t>& right);
};
/**template <typename t> class My_lst2 {
private:
	std::weak_ptr<My_lst2_el<t>> head;
public:
	My_lst2();
	void add_el(t new_el);
	void del_el(t del_el);
	void clear();
	My_lst2_iter<t> begin();
	My_lst2_iter<t> end();
};
template <typename t> class My_lst2_el {
public:
	std::weak_ptr<My_lst2_el<typename t>> next;
	std::auto_ptr<t> value;
};
template <typename t> class My_lst2_iter {
private:
	std::weak_ptr<My_lst2_el<t>> current_el;
public:
	My_lst2_iter(std::weak_ptr<My_lst2_el<t>> head) : current_el(head) {}
	void operator++();
	t operator *();
	bool operator== (My_lst2_iter<typename t>& right);
};
template <typename t> class My_lst3 {
private:
	My_ptr<My_lst3_el<t>> head;
public:
	My_lst3();
	void add_el(t new_el);
	void del_el(t del_el);
	void clear();
	My_lst3_iter<t> begin();
	My_lst3_iter<t> end();
};
template <typename t> class My_lst3_el {
public:
	My_ptr<My_lst3_el<typename t>> next;
	std::auto_ptr<t> value;
};
template <typename t> class My_lst3_iter {
private:
	My_ptr<My_lst3_el<t>> current_el;
public:
	My_lst3_iter(My_ptr<My_lst3_el<t>> head) : current_el(head) {}
	void operator++();
	t operator *();
	bool operator== (My_lst3_iter<typename t>& right);
};*/