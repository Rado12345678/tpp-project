#include <iostream>
#include <chrono>
#include <cstdio>
#include <array>

using namespace std;
using namespace std::chrono;

// Funkcia na získanie využitia CPU
double get_cpu_usage() {
    array<char, 128> buffer;
    string result = "";
    FILE* fp = popen("top -bn1 | grep \"Cpu(s)\" | sed \"s/.*, *\\([0-9.]*\\)%* id.*/\\1/\" | awk '{print 100 - $1}'", "r");
    if (fp) {
        while (fgets(buffer.data(), buffer.size(), fp) != nullptr) {
            result += buffer.data();
        }
        fclose(fp);
    }
    return stod(result);
}

// Funkcia na získanie využitia pamäte
double get_memory_usage() {
    array<char, 128> buffer;
    string result = "";
    FILE* fp = popen("free | grep Mem | awk '{print $3/$2 * 100.0}'", "r");
    if (fp) {
        while (fgets(buffer.data(), buffer.size(), fp) != nullptr) {
            result += buffer.data();
        }
        fclose(fp);
    }
    return stod(result);
}

// Použitie rekurzie
long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Použitie iterácie
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
    int n = 50;

    // Iterative Fibonacci
    cout << endl;
    auto start = high_resolution_clock::now();
    cout << "--- ITERATÍVNA VERZIA ---" << endl;
    cout << "Fibonacci result: " << fibonacci_iterative(n) << endl;
    auto end = high_resolution_clock::now();
    cout << "Čas vykonania: " << duration<double>(end - start).count() << " s" << endl;
    cout << "CPU priemerne: " << get_cpu_usage() << "%" << endl;
    cout << "Max RAM počas behu: " << get_memory_usage() << " MB" << endl;

    // # Recursive Fibonacci
    cout << endl;
    start = high_resolution_clock::now();
    cout << "--- REKURZÍVNA VERZIA ---" << endl;
    cout << "Fibonacci result: " << fibonacci_recursive(n) << endl;
    end = high_resolution_clock::now();
    cout << "Čas vykonania: " << duration<double>(end - start).count() << " s" << endl;
    cout << "CPU priemerne: " << get_cpu_usage() << "%" << endl;
    cout << "Max RAM počas behu: " << get_memory_usage() << " MB" << endl;

    return 0;
}
