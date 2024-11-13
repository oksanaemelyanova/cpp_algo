#include <iostream>

void print_current_position(int arr[], int current_index) {
    int level = 0;
    int index = current_index;
    while (index > 0) {
        index = (index - 1) / 2;
        level++;
    }
    std::string position;
    int parent_index = (current_index - 1) / 2;
    if (current_index == 0) {
        position = "root";
        std::cout << level << " " << position << " " << arr[current_index] << std::endl;
    } else if (current_index % 2 == 1) {
        position = "left(" + std::to_string(arr[parent_index]) + ")";
        std::cout << level << " " << position << " " << arr[current_index] << std::endl;
    } else {
        position = "right(" + std::to_string(arr[parent_index]) + ")";
        std::cout << level << " " << position << " " << arr[current_index] << std::endl;
    }
}

void navigate_pyramid(int arr[], int n) {
    int current_index = 0;

    std::string command;
    while (true) {
        std::cout << "You are here: ";
        print_current_position(arr, current_index);
        std::cout << "Enter command (up, left, right, exit): ";
        std::cin >> command;

        if (command == "up") {
            if (current_index == 0) {
                std::cout << "Error! No parent exists.\n";
            } else {
                current_index = (current_index - 1) / 2;
                std::cout << "Ok\n";
            }
        } else if (command == "left") {
            int left_child_index = 2 * current_index + 1;
            if (left_child_index >= n) {
                std::cout << "Error! No left child exists.\n";
            } else {
                current_index = left_child_index;
                std::cout << "Ok\n";
            }
        } else if (command == "right") {
            int right_child_index = 2 * current_index + 2;
            if (right_child_index >= n) {
                std::cout << "Error! No right child exists.\n";
            } else {
                current_index = right_child_index;
                std::cout << "Ok\n";
            }
        } else if (command == "exit") {
            std::cout << "Exiting program.\n";
            break;
        } else {
            std::cout << "Error! Unknown command.\n";
        }
    }
}


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

    navigate_pyramid(arr1, size1);

    return 0;
}