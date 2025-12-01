// Given an array arr[] and an integer k, we need to count the number of pairs from the given array such that the Bitwise XOR of each pair is less than k.

// Examples:

// Input: arr = [1, 2, 3, 5], k = 5
// Output: 4
// Explanation: Bitwise XOR of all possible pairs that satisfy the given conditions are:
// arr[0] ^ arr[1] = 1 ^ 2 = 3
// arr[0] ^ arr[2] = 1 ^ 3 = 2
// arr[0] ^ arr[3] = 1 ^ 5 = 4
// arr[1] ^ arr[2] = 2 ^ 3 = 1
// Therefore, the required output is 4.
// Input: arr[] = [3, 5, 6, 8], k = 7
// Output: 3
// Explnation: Bitwise XOR of all possible pairs that satisfy the given conditions are:
// arr[0] ^ arr[1] = 6
// arr[0] ^ arr[2] = 5
// arr[1] ^ arr[2] = 3
// Therefore, the required output is 3.
// Constraints:
// 1 ≤ arr.size(), k ≤ 5*104
// 1 ≤ arr[i] ≤ 5*104
class Solution
{
public:
    struct Trie
    {
        Trie *child[2];
        int cnt;
        Trie()
        {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };
    Trie *root = new Trie();
    void insert(int x)
    {
        Trie *node = root;
        for (int i = 15; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (!node->child[bit])
            {
                node->child[bit] = new Trie();
            }
            node = node->child[bit];
            node->cnt++;
        }
    }
    int query(int x, int k)
    {
        Trie *node = root;
        int res = 0;
        for (int i = 15; i >= 0; i--)
        {
            if (!node)
            {
                break;
            }
            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;
            if (kb == 1)
            {
                int want = xb;
                if (node->child[want])
                {
                    res += node->child[want]->cnt;
                }
                node = node->child[xb ^ 1];
            }
            else
            {
                int want = xb;
                node = node->child[want];
            }
        }
        return res;
    }
    int cntPairs(vector<int> &arr, int k)
    {
        int ans = 0;
        for (int x : arr)
        {
            ans += query(x, k);
            insert(x);
        }
        return ans;
    }
};