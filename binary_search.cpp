#include <iostream>
#include <vector>

using namespace std;

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
    for (int i = 0; i < 1000000; ++i) {     // Fill the array with values from 0 to 999_999
        arr[i] = 2*i;
    }
    int target = 23000;        // The value we are looking for
    
    int result = binary_search(arr, target);
    cout << "Index hodnoty " << target << ": " << result << endl;
    
    return 0;
}
