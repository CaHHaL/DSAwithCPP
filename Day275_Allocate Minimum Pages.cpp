// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int mid)
    {
        int sum = 0, student = 1;
        for (int x : arr)
        {
            sum += x;
            if (sum > mid)
            {
                student++;
                sum = x;
            }
        }
        return student <= k;
    }
    int findPages(vector<int> &arr, int k)
    {
        if (k > arr.size())
            return -1;
        int sum = 0, mx = INT_MIN;
        for (int x : arr)
        {
            sum += x;
            mx = max(mx, x);
        }
        int low = mx, high = sum, mid, ans = INT_MAX;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isPossible(arr, k, mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};