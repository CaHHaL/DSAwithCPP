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
        int N = arr.size();
        int police = 0, thief = 0;
        while (police < N && arr[police] != 'P')
            police++;
        while (thief < N && arr[thief] != 'T')
            thief++;
        int count = 0;
        while (police < N && thief < N)
        {
            if (abs(police - thief) <= k)
            {
                count++;
                police++;
                thief++;
            }
            else if (police < N && police < thief)
                police++;
            else if (thief < N && thief < police)
                thief++;
            while (police < N && arr[police] != 'P')
                police++;
            while (thief < N && arr[thief] != 'T')
                thief++;
        }
        return count;
    }
};