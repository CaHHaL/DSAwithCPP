// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

// Examples:

// Input: k = 7

// Output: 3
// Explanation: The following paths sum to k

// Input: k = 3

// Output: 2
// Explanation:
// Path 1 : 1 -> 2 (Sum = 3)
// Path 2 : 3 (Sum = 3)

class Solution
{
public:
    void solve(Node *root, int k, int currSum, int &count, unordered_map<int, int> &mp)
    {
        if (!root)
            return;
        currSum += root->data;
        if (currSum == k)
            count++;
        if (mp.find(currSum - k) != mp.end())
            count += mp[currSum - k];
        mp[currSum]++;
        solve(root->left, k, currSum, count, mp);
        solve(root->right, k, currSum, count, mp);
        mp[currSum]--;
    }
    int sumK(Node *root, int k)
    {
        unordered_map<int, int> mp;
        int count = 0;
        solve(root, k, 0, count, mp);
        return count;
    }
};