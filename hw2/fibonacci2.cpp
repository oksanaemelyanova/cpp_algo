#include <iostream>

int fibo(int n) {
    if (n <= 1)
        return (n); // first two elements would be equal n;
    int* fibb = new int[n + 1];
    fibb[0] = 0;
    fibb[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibb[i] = fibb[i - 1] + fibb[i - 2];
    }
    int temp = fibb[n];
    delete fibb;
    return temp;
}

int main(void) {
    int n;
    std::cout << "enter a number" << std::endl;
    std::cin >> n;
    int result = fibo(n);
    std::cout << "the n Fibonacci number is: " << result << std::endl;
}