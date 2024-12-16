// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

// Examples :

// Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
// Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
// Output: 256
// Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        
        // To find the kth element, we'll iterate until we reach the kth element
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                k--;
                if (k == 0) return a[i];
                i++;
            } else {
                k--;
                if (k == 0) return b[j];
                j++;
            }
        }
        
        // If we've exhausted one array, we need to continue with the other array
        while (i < n) {
            k--;
            if (k == 0) return a[i];
            i++;
        }
        
        while (j < m) {
            k--;
            if (k == 0) return b[j];
            j++;
        }
        
        return -1; // In case k is out of bounds (though the problem assumes valid k)
    }
};

int main() {
    Solution solution;
    
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    int result = solution.kthElement(a, b, k);
    cout << "The " << k << "-th element is: " << result << endl; // Output should be 6
    
    return 0;
}
