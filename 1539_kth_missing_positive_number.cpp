// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int low = 0, high = arr.size() - 1;
        
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             int missing = arr[mid] - (mid + 1);
            
//             if (missing < k) {
//                 low = mid + 1; // Need to look further right for more missing numbers
//             } else {
//                 high = mid - 1; // Too many missing numbers, look left
//             }
//         }
        
//         // The formula for the result is: high + 1 + k
//         // Or more simply: low + k
//         return low + k;
//     }
// };

#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}