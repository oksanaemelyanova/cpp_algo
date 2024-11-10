#include <iostream>
#include <utility>

int pivoting(int *arr, int p, int size) {
    int left = 0;
    int right = size - 1;
    int pivot = arr[p];
    // std::cout << "pivot: " << pivot << std::endl;
    //     std::cout << "begin arr is: " << std::endl;
    //     for (int i = 0; i < size; i++){
    //         std::cout << arr[i] << " ";
    //     }
    //     std::cout << std::endl;
    while (1) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
      //  std::cout << "left is: " << left << ", right is: " << right << std::endl;
        if (left >= right) {
            //std::cout << "returning border: " << right << std::endl;
            return (left);
        }
        std::swap(arr[left], arr[right]);
        // std::cout << "now arr is: " << std::endl;
        // for (int i = 0; i < size; i++){
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
        left++;
        right--;
    }
}

void quick_sort(int* arr, int size) {
    if (size <= 1) {
        return ;
    }

    int p = size / 2;
    int border = pivoting(arr, p, size);
    
    quick_sort(arr, border);
    quick_sort(arr + border, size - border); 
}


int main(void) {
    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "size1: " << size1 << ", size 2: " << size2 << std::endl;
    std::cout << "initial array1:" << std::endl;
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    quick_sort(arr1, size1);
    std::cout << "sorted array1:" << std::endl;
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "initial array2:" << std::endl;
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;    
    quick_sort(arr2, size2);    
    std::cout << "sorted array2:" << std::endl;
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return(0);
}