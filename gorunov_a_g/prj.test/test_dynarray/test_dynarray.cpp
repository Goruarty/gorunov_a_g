#include "dynarray/dynarray.h"
#include <iostream>
#include <exception>

int main(){
    DynArray arr(2);
    std::cout << arr.size() << " " << arr.capacity() << std::endl;
    arr.resize(6);
    std::cout << arr.size() << " " << arr.capacity() << std::endl;
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << arr.size() << " " << arr.capacity() << std::endl;
    /*
    DynArray arr2(5);
    for (int i = 0; i < arr2.size()-1; ++i) {
        arr2[i] = i + 5;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl << arr2.size() << " " << arr2.capacity() << std::endl;
    */
    std::cout << std::endl;
	return 0;
}



