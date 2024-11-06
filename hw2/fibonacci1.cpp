#include <iostream>

int fibo(int n) {
    if (n <= 1)
        return n;
    return (fibo(n - 1) + fibo(n - 2));
}

int main(void) {
    int n;
    std::cout << "enter a number" << std::endl;
    std::cin >> n;
    int result = fibo(n);
    std::cout << "the n Fibonacci number is: " << result << std::endl;
}