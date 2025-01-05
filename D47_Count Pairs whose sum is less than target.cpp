// Given an array arr[] and an integer target.You have to find the number of pairs in the array whose sum is strictly less than the target.

//                          Examples :

//     Input : arr[] = [ 7, 2, 5, 3 ],
//             target = 8 Output : 2 Explanation : There are 2 pairs with sum less than 8 : (2, 5) and (2, 3).Input : arr[] = [ 5, 2, 3, 2, 4, 1 ], target = 5 Output : 4 Explanation : There are 4 pairs whose sum is less than 5 : (2, 2), (2, 1), (3, 1) and (2, 1).Input : arr[] = [ 2, 1, 8, 3, 4, 7, 6, 5 ], target = 7 Output : 6 Explanation : There are 6 pairs whose sum is less than 7 : (2, 1), (2, 3), (2, 4), (1, 3), (1, 4) and (1, 5).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        // Sort the array
        sort(arr.begin(), arr.end());

        int left = 0, right = arr.size() - 1;
        int count = 0;

        // Use two-pointer technique
        while (left < right)
        {
            if (arr[left] + arr[right] < target)
            {
                // If arr[left] + arr[right] is less than target,
                // all pairs from left to right are valid
                count += (right - left);
                left++;
            }
            else
            {
                // Otherwise, move the right pointer to the left
                right--;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {7, 2, 5, 3};
    int target1 = 8;
    cout << "Number of pairs: " << sol.countPairs(arr1, target1) << endl;

    vector<int> arr2 = {5, 2, 3, 2, 4, 1};
    int target2 = 5;
    cout << "Number of pairs: " << sol.countPairs(arr2, target2) << endl;

    vector<int> arr3 = {2, 1, 8, 3, 4, 7, 6, 5};
    int target3 = 7;
    cout << "Number of pairs: " << sol.countPairs(arr3, target3) << endl;

    return 0;
}
