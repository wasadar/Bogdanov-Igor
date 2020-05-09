#pragma once
#include <iostream>

template <typename t> class funcclass {
public:
	t** data;
	int len;
	void print_to_screen();
	int find_ind(t el);
	void sort(int s);
	t find_min();
	t find_max();
};
class drob {
public:
	int chislitel;
	int znaminaytel;
	drob& operator=(const drob& d);
	drob(int f, int s);
	drob();
	virtual char get_char() const;
};
class drob2 : public drob {
public:
	char c;
	drob2& operator=(const drob2& d);
	drob2(int f, int s, char c);
	drob2();
	virtual char get_char() const override;
};
std::ostream& operator<<(std::ostream& os, const drob& d);
std::istream& operator>>(std::istream& is, drob& d);
bool operator==(const drob& d1, const drob& d2);
bool operator!=(const drob& d1, const drob& d2);
bool operator>(const drob& d1, const drob& d2);
bool operator<(const drob& d1, const drob& d2);
std::ostream& operator<<(std::ostream& os, const drob2& d);
std::istream& operator>>(std::istream& is, drob2& d);
bool operator==(const drob2& d1, const drob2& d2);
bool operator!=(const drob2& d1, const drob2& d2);
bool operator>(const drob2& d1, const drob2& d2);
bool operator<(const drob2& d1, const drob2& d2);
void menu();