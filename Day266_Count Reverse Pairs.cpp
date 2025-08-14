// You are given an array arr[] of positive integers, find the count of reverse pairs. A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:

// 0 ≤ i < j < arr.size()
// arr[i] > 2 * arr[j]
// Examples:
// Input: arr[] = [3, 2, 4, 5, 1, 20]
// Output: 3
// Explanation:
// The Reverse pairs are
// (0, 4), arr[0] = 3, arr[4] = 1, 3 > 2*1
// (2, 4), arr[2] = 4, arr[4] = 1, 4 > 2*1
// (3, 4), arr[3] = 5, arr[4] = 1, 5 > 2*1
// Input: arr[] = [5, 4, 3, 2, 2]
// Output: 2
// Explanation:
// The Reverse pairs are
// (0, 3), arr[0] = 5, arr[3] = 2, 5 > 2*2
// (0, 4), arr[0] = 5, arr[4] = 2, 5 > 2*2

class Solution
{
public:
    int cnt = 0;
    void merge(int low, int mid, int high, vector<int> &a)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (a[left] <= a[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else
            {
                temp.push_back(a[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(a[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(a[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            a[i] = temp[i - low];
        }
        return;
    }
    void countpairs(int low, int mid, int high, vector<int> &a)
    {
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && a[i] > 2 * (long long)a[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return;
    }
    void mergeSort(int low, int high, vector<int> &a, int n)
    {
        if (low >= high)
            return;
        int mid = (low + high) >> 1;
        mergeSort(low, mid, a, n);
        mergeSort(mid + 1, high, a, n);
        countpairs(low, mid, high, a);
        merge(low, mid, high, a);
        return;
    }
    int countRevPairs(vector<int> &arr)
    {
        int n = arr.size();
        mergeSort(0, n - 1, arr, n);
        return cnt;
    }
};