// You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

// Note: From dictionary[], any word can be taken any number of times and in any order.

// Examples :

// Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
// Output: true
// Explanation: s can be breakdown as "i like".
// Input: s = "ilikegfg", dictionary[] = ["i", "like", "man", "india", "gfg"]
// Output: true
// Explanation: s can be breakdown as "i like gfg".
// Input: s = "ilikemangoes", dictionary[] = ["i", "like", "man", "india", "gfg"]
// Output: false
// Explanation: s cannot be formed using dictionary[] words.

class Solution
{
public:
    bool solve(string &s, set<string> st, int i, vector<int> &dp)
    {
        if (i == s.size())
            return 1;
        if (dp[i] != -1)
            return dp[i];
        string temp = "";
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if (st.find(temp) != st.end())
            {
                if (solve(s, st, j + 1, dp))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string &s, vector<string> &dictionary)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        set<string> st;
        for (auto it : dictionary)
            st.insert(it);
        return solve(s, st, 0, dp);
    }
};