#include <iostream>

void print_pyramid(int arr[], int n) {
    //1. print array
    std::cout << "Initial array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    

    //2. main part - the pyramid itself
    std::cout << "The pyramid:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int level = 0;
        int index = i;

        while (index > 0) {
            index = (index - 1) / 2;
            level++;
        }

        std::string position;
        int parent_index = (i - 1) / 2;
        if (i == 0) {
            position = "root";
            std::cout << level << " " << position << " " << arr[i] << std::endl;
        } else if (i % 2 == 1) {
            position = "left(" + std::to_string(arr[parent_index]) + ")";
            std::cout << level << " " << position << " " << arr[i] << std::endl;
        } else {
            position = "right(" + std::to_string(arr[parent_index]) + ")";
            std::cout << level << " " << position << " " << arr[i] << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    print_pyramid(arr1, size1);
    print_pyramid(arr2, size2);    

    return 0;
}