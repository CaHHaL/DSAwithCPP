// Given an array arr[], where each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police.
// Keep in mind the following conditions :

// Each policeman can catch only one thief.
// A policeman cannot catch a thief who is more than k units away from him.
// Examples:

// Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
// Output: 2
// Explanation: Maximum 2 thieves can be caught. First policeman catches first thief and second police man can catch either second or third thief.
// Input: arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
// Output: 3
// Explanation: Maximum 3 thieves can be caught.
class Solution
{
public:
    int catchThieves(vector<char> &arr, int k)
    {
        vector<int> p, t;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 'P')
                p.push_back(i);
            else
                t.push_back(i);
        }
        int ans = 0;
        int st = 0;
        for (int i = 0; i < t.size(); i++)
        {
            while (st < p.size())
            {
                int low = t[i] - k;
                int high = t[i] + k;
                if (p[st] <= high && p[st] >= low)
                {
                    ans++;
                    st++;
                    break;
                }
                else if (p[st] < low)
                {
                    st++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};