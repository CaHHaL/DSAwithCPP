// Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

// Examples:

// Input: arr[] = [3, 30, 34, 5, 9]
// Output: 9534330
// Explanation: Given numbers are [3, 30, 34, 5, 9], the arrangement [9, 5, 34, 3, 30] gives the largest value.
// Input: arr[] = [54, 546, 548, 60]
// Output: 6054854654
// Explanation: Given numbers are [54, 546, 548, 60], the arrangement [60, 548, 546, 54] gives the largest value.
// Input: arr[] = [3, 4, 6, 5, 9]
// Output: 96543
// Explanation: Given numbers are [3, 4, 6, 5, 9], the arrangement [9, 6, 5, 4, 3] gives the largest value.
class Solution
{
public:
    string findLargest(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int &a, int &b)
             {
            string x = to_string(a); 
            string y = to_string(b); 
            return x + y > y + x; });
        if (!arr.empty() && arr[0] == 0)
            return "0";
        string ans;
        for (auto i : arr)
        {
            ans += to_string(i);
        }
        return ans;
    }
};