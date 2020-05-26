#include "Mycont.h"

template <typename t> void My_lst1_iter<typename t>::operator++() {
    current_el = current_el->next;
}
template <typename t> t My_lst1_iter<typename t>::operator*() {
    return current_el->value;
}
template <typename t> bool My_lst1_iter<t>::operator==(My_lst1_iter<typename t>& right) {
    return current_el == right.current_el;
}
template <typename t> bool My_lst1_iter<t>::operator!=(My_lst1_iter<typename t>& right) {
    return current_el != right.current_el;
}
template <typename t> My_lst1<t>::My_lst1() {
    head = 0;
}
template <typename t> void My_lst1<t>::add_el(t new_el) {
    std::shared_ptr<My_lst1_el<t>> temp = head;
    head = new std::shared_ptr<My_lst1_el<t>>(new_el);
    head->next = temp;
}
template <typename t> void My_lst1<t>::del_el(t del_el) {
    std::shared_ptr<My_lst1_el<t>> temp = head;
    if (*head == del_el) {
        head = head->next;
    }
    else {
        while (temp->next != 0){
            if (temp->next == del_el) {
                temp->next = temp->next->next;
                break;
            }
        }
    }
}
template <typename t> void My_lst1<t>::clear() {
    head = 0;
}
template <typename t> template <class compare> void My_lst1<typename t>::sort(compare cmp) {
    bool check = false;
    do {
        check = false;
        std::shared_ptr<My_lst1_el<t>> temp = head;
        while (temp->next != 0) {
            if (cmp(temp->next,*temp)) {
                check = true;
                std::swap(temp,temp->next);
            }
        }
    } while (check);
}
template <typename t> My_lst1_iter<t> My_lst1<t>::begin() {
    return My_lst1_iter<t>(head);
}
template <typename t> My_lst1_iter<t> My_lst1<t>::end() {
    return My_lst1_iter<t>(0);
}
/**template <typename t> void My_lst2_iter<typename t>::operator++() {
    current_el = current_el->next;
}
template <typename t> t My_lst2_iter<typename t>::operator*() {
    return current_el->value;
}
template <typename t> bool My_lst2_iter<typename t>::operator==(My_lst2_iter<typename t>& right) {
    return current_el == right.current_el;
}
template <typename t> My_lst2<typename t>::My_lst2() {
    head = 0;
}
template <typename t> void My_lst2<typename t>::add_el(t new_el) {
    std::weak_ptr<My_lst2_el<t>> temp = head;
    head = new std::weak_ptr<My_lst2_el<typename t>>(new_el);
    head->next = temp;
}
template <typename t> void My_lst2<typename t>::del_el(t del_el) {
    std::weak_ptr<My_lst2_el<t>> temp = head;
    if (*head == del_el) {
        head = head->next;
    }
    else {
        while (temp->next != 0) {
            if (temp->*next == del_el) {
                temp->next = temp->next->next;
                break;
            }
        }
    }
}
template <typename t> void My_lst2<typename t>::clear() {
    head = 0;
}
template <typename t> My_lst2_iter<typename t> My_lst2<typename t>::begin() {
    return My_lst2_iter<typename t>(head);
}
template <typename t> My_lst2_iter<typename t> My_lst2<typename t>::end() {
    return My_lst2_iter<typename t>(0);
}
template <typename t> void My_lst3_iter<typename t>::operator++() {
    current_el = current_el->next;
}
template <typename t> t My_lst3_iter<typename t>::operator*() {
    return current_el->value;
}
template <typename t> bool My_lst3_iter<typename t>::operator==(My_lst3_iter<typename t>& right) {
    return current_el == right.current_el;
}
template <typename t> My_lst3<typename t>::My_lst3() {
    head = 0;
}
template <typename t> void My_lst3<typename t>::add_el(t new_el) {
    My_ptr<My_lst3_el<typename t>> temp = head;
    head = new My_ptr<My_lst3_el<typename t>>(new_el);
    head->next = temp;
}
template <typename t> void My_lst3<typename t>::del_el(t del_el) {
    My_ptr<My_lst3_el<typename t>> temp = head;
    if (*head == del_el) {
        head = head->next;
    }
    else {
        while (temp->next != 0) {
            if (temp->*next == del_el) {
                temp->next = temp->next->next;
                break;
            }
        }
    }
}
template <typename t> void My_lst3<typename t>::clear() {
    head = 0;
}
template <typename t> My_lst3_iter<typename t> My_lst3<typename t>::begin() {
    return My_lst3_iter<typename t>(head);
}
template <typename t> My_lst3_iter<typename t> My_lst3<typename t>::end() {
    return My_lst3_iter<typename t>(0);
}*/