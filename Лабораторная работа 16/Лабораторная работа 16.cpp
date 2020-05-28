#include "file.h"
#define _CRTDBG_MAP_ALLOC 

int main(){
    setlocale(LC_ALL, "Russian");
    file* test_ptr;
    test_ptr = new file;
    delete test_ptr;
    test_ptr = new file[2];
    delete[] test_ptr;
    executable_file* test_ptr2;
    test_ptr2 = new executable_file;
    delete test_ptr2;
    test_ptr2 = new executable_file[2];
    delete[] test_ptr2;
    non_executable_file* test_ptr3;
    test_ptr3 = new non_executable_file;
    delete test_ptr3;
    test_ptr3 = new non_executable_file[2];
    delete[] test_ptr3;
    if (_CrtDumpMemoryLeaks()) {
        std::cout << "Утечка памяти обнаружена." << "\n";
    }
    else {
        std::cout << "Утечка памяти не обнаружена." << "\n";
    }
}