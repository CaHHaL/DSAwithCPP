// Koko is given an array arr[], where each element represents a pile of bananas. She has exactly k hours to eat all the bananas.

// Each hour, Koko can choose one pile and eat up to s bananas from it.

// If the pile has atleast s bananas, she eats exactly s bananas.

// If the pile has fewer than s bananas, she eats the entire pile in that hour.

// Koko can only eat from one pile per hour.

// Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.

// Examples:

// Input: arr[] = [5, 10, 3], k = 4
// Output: 5
// Explanation: Koko eats at least 5 bananas per hour to finish all piles within 4 hours, as she can consume each pile in 1 + 2 + 1 = 4 hours.
// Input: arr[] = [5, 10, 15, 20], k = 7
// Output: 10
// Explanation: At 10 bananas per hour, Koko finishes in 6 hours, just within the limit 7.

class Solution
{
public:
    bool finish(vector<int> &arr, int mid, int k)
    {
        int hours = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            hours += arr[i] / mid;
            if (arr[i] % mid != 0)
            {
                hours++;
            }
        }

        return hours <= k;
    }

    int kokoEat(vector<int> &arr, int k)
    {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int result = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (finish(arr, mid, k))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return result;
    }
};