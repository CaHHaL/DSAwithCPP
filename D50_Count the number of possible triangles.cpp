// Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle.

// A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.

// Examples:

// Input: arr[] = [4, 6, 3, 7]
// Output: 3
// Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.
// Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
// Output: 6
// Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]
// Input: arr[] = [1, 2, 3]
// Output: 0
// Explanation: No triangles are possible.

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;

        // Sort the array to simplify the condition checks
        sort(arr.begin(), arr.end());

        // Iterate over each element arr[i] and check pairs arr[j] and arr[k]
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = i + 2;

            while (k < n)
            {
                if (arr[i] + arr[j] > arr[k])
                {
                    // If arr[i] + arr[j] > arr[k], then all pairs (arr[j], arr[k]), (arr[j+1], arr[k]), ... (arr[n-1], arr[k])
                    // will form valid triangles with arr[i] as the smallest side
                    count += (k - j);
                    k++;
                }
                else
                {
                    // If the sum of arr[i] and arr[j] is not greater than arr[k], we need a larger value for k
                    j++;
                    if (j == k)
                    {
                        k++;
                    }
                }
            }
        }

        return count;
    }
};
