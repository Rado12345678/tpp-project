#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Using recersion
long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Using iteration
long long fibonacci_iterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 40;
    auto start = high_resolution_clock::now();
    cout << "Fibonacci iteratívne: " << fibonacci_iterative(n) << endl;
    auto end = high_resolution_clock::now();
    cout << "Čas iteratívne: " << duration<double>(end - start).count() << "s\n";

    start = high_resolution_clock::now();
    cout << "Fibonacci rekurzívne: " << fibonacci_recursive(n) << endl;
    end = high_resolution_clock::now();
    cout << "Čas rekurzívne: " << duration<double>(end - start).count() << "s\n";

    return 0;
}
