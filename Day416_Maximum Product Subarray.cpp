class Solution
{
public:
    long long maxProduct(vector<int> &arr)
    {
        long long maxProd = arr[0];
        long long minProd = arr[0];
        long long ans = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            // If current element is negative, swap
            if (arr[i] < 0)
            {
                swap(maxProd, minProd);
            }

            maxProd = max((long long)arr[i], maxProd * arr[i]);
            minProd = min((long long)arr[i], minProd * arr[i]);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};