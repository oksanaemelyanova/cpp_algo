#include <iostream>

void bubble(int *arr, int size){
     for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge_sort(int* arr, int size) {
    std::cout<< "======merge sort=======" << std::endl;
    std::cout << "initial array:" << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int* sorted = new int(size);
    //1. preparing two sorted arrays
    int mid = size / 2;

    int left[mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    bubble(left, mid);
       
    int right[size - mid];
    int j = 0;
    for (int i = mid; i < size; i++) {
        right[j] = arr[i];
        j++;
    }
    bubble(right, size - mid);

    //2. merging two sorted arrays
    int a = 0;
    int b = 0;
    int c = 0;
    while (a < mid || b < (size - mid)) {
        if (a == mid) {
            sorted[c] = right[b];
            b++;
        }
        else if (b == (size - mid)) {
            sorted[c] = left[a];
            a++;
        }
        else {
            if (left[a] <= right[b]) {
                sorted[c] = left[a];
                a++;
            }
            else {
                sorted[c] = right[b];
                b++;
            }
        }
        c++;
    }

    std::cout << "sorted array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;

    delete sorted;
}


int main(void) {
    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "size1: " << size1 << ", size 2: " << size2 << std::endl;
    merge_sort(arr1, size1);
    merge_sort(arr2, size2);

    return(0);
}