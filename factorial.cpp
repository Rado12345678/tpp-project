#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Using iteration to calculate factorial
long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Using recursion to calculate factorial
long long factorial_recursive(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}

// Timer function
template <typename Func>
double measure_time(Func func, int n) {
    auto start = high_resolution_clock::now();
    func(n);
    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count();
}

int main() {
    int n = 100;

    // Measure and print results for iterative and recursive
    cout << "Factorial (Iterative) of " << n << " is: " << factorial_iterative(n) << endl;
    cout << "Time (Iterative): " << measure_time(factorial_iterative, n) << "s\n";

    cout << "Factorial (Recursive) of " << n << " is: " << factorial_recursive(n) << endl;
    cout << "Time (Recursive): " << measure_time(factorial_recursive, n) << "s\n";

    return 0;
}
