#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr(1000000);
    for (int i = 0; i < 1000000; ++i) {  // Fill the array with values from 0 to 1,999,998 (even numbers)
        arr[i] = 2 * i;
    }
    
    int target = 23000;  // The value we are looking for

    auto start = high_resolution_clock::now();
    int result = binary_search(arr, target);
    auto end = high_resolution_clock::now();

    cout << "Index hodnoty " << target << ": " << result << endl;
    cout << "Execution time: " << duration<double>(end - start).count() << "s" << endl;

    return 0;
}
