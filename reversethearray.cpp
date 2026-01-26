#include <bits/stdc++.h>
void reverseArray(vector<int> &arr, int m)
{
    // Write your code here
    reverse(arr.begin() + m + 1, arr.end());
}

#include <bits/stdc++.h>
void reverseArray(vector<int> &arr, int m)
{
    int s = m + 1;
    int n = arr.size();
    int e = n - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}