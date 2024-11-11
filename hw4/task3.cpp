#include <iostream>

int* remove_dynamic_array_head(int* arr, int &logical_size, int &actual_size) {
    if (logical_size - 1 > actual_size / 3) {
        for (int i = 1; i < logical_size; i++) {
            arr[i - 1] = arr[i];
        }
        logical_size--;
    }
    else {
        int* arr1 = new int(actual_size / 3);
        actual_size /= 3;
        for (int i = 1; i < logical_size; i++) {
            arr1[i - 1] = arr[i];
        }
        logical_size--;
        delete arr;
        return arr1;
    }
    return arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Dynamic array: " << std::endl;
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

    while (1) {
        std::string yN;
        std::cout << "Do you want to remove the first element? (yes/no): ";
        std::cin >> yN;
        if (yN == "yes") {
            if (lSize == 0) {
                std::cout << "Cannot remove the first element, the array is empty. Goodbye!" << std::endl;
                break;
            }
            dinArr = remove_dynamic_array_head(dinArr, lSize, actSize);
            print_dynamic_array(dinArr, lSize, actSize);
        }
        else if (yN == "no") {
            std::cout << "Thank you! Your dynamic array: ";
            print_dynamic_array(dinArr, lSize, actSize);
            break;
        }
        else {
            std::cout << "please enter valid command: yes/no" << std::endl;
        }
    }    
    delete dinArr;

    return 0;
}