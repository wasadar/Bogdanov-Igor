#include "file.h"
#include "Mypointer.h"
#include <memory>
#define _CRTDBG_MAP_ALLOC 

void func();

int main(){
    setlocale(LC_ALL, "Russian");
    func();
    if (_CrtDumpMemoryLeaks()) {
        std::cout << "Утечка памяти обнаружена." << "\n";
    }
    else {
        std::cout << "Утечка памяти не обнаружена." << "\n";
    }
}

void func() {
    std::vector<file> vect;
    std::auto_ptr<executable_file> aptr(new executable_file);
    std::unique_ptr<file> uptr(new file);
    std::shared_ptr<non_executable_file> sptr(new non_executable_file);
    std::weak_ptr<non_executable_file> wptr = sptr;
    My_ptr<file> myptr(new file);
    vect.push_back(*aptr);
    vect.push_back(*uptr);
    vect.push_back(*sptr);
    vect.push_back(*myptr);
    std::cout << "Данные из умных указателей переписаны в вектор.\n";
    for (auto el : vect) {
        std::cout << el << "\n";
    }
}