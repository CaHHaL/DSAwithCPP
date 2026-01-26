class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> mer;
        int i = 0;
        int j = 0;

        while (i < m && j < n)
        {
            if (nums1[i] >= nums2[j])
            {
                mer.push_back(nums2[j]);
                j++;
            }
            else
            {
                mer.push_back(nums1[i]);
                i++;
            }
        }
        while (i < m)
        {
            mer.push_back(nums1[i++]);
        }
        while (j < n)
        {
            mer.push_back(nums2[j++]);
        }
        for (int j = 0; j < m + n; j++)
        {
            nums1[j] = mer[j];
        }
    }
};