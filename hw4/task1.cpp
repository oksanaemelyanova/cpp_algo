#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "you entered the following array: " << std::endl;
    for (int i = 0; i < logical_size; i++) {
        std::cout << arr[i] << " ";
    }
    if (logical_size < actual_size) {
        for (int i = logical_size; i < actual_size; i++) {
            std::cout << "_" << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int actSize = 0;
    int lSize = 0;
    std::cout << "Enter actual array size" << std::endl;
    std::cin >> actSize;
    int* dinArr = new int(actSize);
    std::cout << "Enter logical array size" << std::endl;
    std::cin >> lSize;
    if (lSize > actSize) {
        std::cout << "Error, logical size can't be greater then the actual one" << std::endl;
        return 1;
    }
    for (int i = 0; i < lSize; i++) {
        std::cout << "please enter the element index " << i << std::endl;
        std::cin >> dinArr[i];
    }
    print_dynamic_array(dinArr, lSize, actSize);
    
    delete dinArr;

    return 0;
}