// Given a string s consisting of lowercase English characters, determine the total number of distinct non-empty substrings present in the string. A substring is defined as a contiguous block of characters within the string.

// Two substrings are considered distinct if their contents differ, even if they originate from different positions in the string.

// Note: The empty substring is not counted.

// Examples :

// Input: s = "ababa"
// Output: 9
// Explanation: All distinct substrings of "ababa" are: "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa".
// Input: s = "aaa"
// Output: 3
// Explanation: The distinct substrings of "aaa" are: "a", "aa", "aaa".
// Constraints:
// 1 ≤ s.size() ≤ 3000
class Node
{
public:
    Node *child[26];
    Node()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class Solution
{
public:
    virtual int countSubs(string &s)
    {
        Node *root = new Node();
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            Node *temp = root;
            for (int j = i; j < n; j++)
            {
                int ind = s[j] - 97;
                if (temp->child[ind] == NULL)
                {
                    temp->child[ind] = new Node();
                    count++;
                }
                temp = temp->child[ind];
            }
        }
        return count;
    }
};