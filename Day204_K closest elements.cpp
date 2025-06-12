// You are given a sorted array arr[] of unique integers, an integer k, and a target value x. Return exactly k elements from the array closest to x, excluding x if it exists.

// An element a is closer to x than b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a > b (i.e., prefer the larger element if tied)

// Return the k closest elements in order of closeness.

// Examples:

// Input: arr[] = [1, 3, 4, 10, 12], k = 2, x = 4
// Output: 3 1
// Explanation: 4 is excluded, Closest elements to 4 are: 3 (1), 1 (3). So, the 2 closest elements are: 3 1
// Input: arr[] = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56], k = 4, x = 35
// Output: 39 30 42 45
// Explanation: First closest element to 35 is 39.
// Second closest element to 35 is 30.
// Third closest element to 35 is 42.
// And fourth closest element to 35 is 45.

class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int k, int x)
    {
        auto comp = [x](int a, int b)
        {
            int diffA = abs(a - x);
            int diffB = abs(b - x);
            if (diffA != diffB)
                return diffA < diffB;
            return a > b;
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (int i : arr)
        {
            if (i != x)
            {
                pq.push(i);
            }
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i)
        {
            ans[i] = pq.top();
            pq.pop();
        }

        return ans;
    }
};