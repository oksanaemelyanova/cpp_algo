#include <iostream>

int calculate(int arr[]) {
    int i = 0;
    while (arr[i]) {
        i++;
    }

    return i;
}

void algo(int arr[], int mark) {
    int size = calculate(arr);
    int left = 0;
    int right = size - 1;
    int middle = 0;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (arr[middle] <= mark)
            left = middle + 1;
        else
            right = middle - 1;
    }
    std::cout << "the array has " << size - left << " elements bigger than " << mark << std::endl;

}

int main(void) {
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};

    algo(arr, 17);
    return 0;
}