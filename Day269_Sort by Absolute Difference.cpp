// You are given a number x and array arr[]. Your task is to rearrange the elements of the array according to the absolute difference with x, i.e., an element having minimum difference comes first, and so on.
// Note: If two or more elements are at equal distances arrange them in the same sequence as in the given array.

// Examples:

// Input: x = 7, arr[] = [10, 5, 3, 9, 2]
// Output: [5, 9, 10, 3, 2]
// Explanation: Sorting the numbers according to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.
// Input: x = 6, arr[] = [1, 2, 3, 4, 5]
// Output: [5, 4, 3, 2, 1]
// Explanation: Sorting the numbers according to the absolute difference with 6, we have array elements as 5, 4, 3, 2, 1.

class Solution
{
public:
    void rearrange(vector<int> &arr, int x)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < arr.size(); i++)
            temp.push_back({arr[i], i});
        auto comp = [&](auto &v1, auto &v2)
        {
            if (abs(v1.first - x) == abs(v2.first - x))
            {
                return v1.second < v2.second;
            }
            return abs(v1.first - x) < abs(v2.first - x);
        };
        sort(temp.begin(), temp.end(), comp);
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = temp[i].first;
        }
    }
};