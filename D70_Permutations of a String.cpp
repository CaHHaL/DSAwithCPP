// Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

// Examples:

// Input: s = "ABC"
// Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
// Explanation: Given string ABC has 6 unique permutations.
// Input: s = "ABSG"
// Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
// Explanation: Given string ABSG has 24 unique permutations.
// Input: s = "AAA"
// Output: ["AAA"]
// Explanation: No other unique permutations can be formed as all the characters are same.

class Solution
{
public:
    vector<string> findPermutation(string &s)
    {
        set<string> ans;
        vector<bool> visit(s.length(), false);
        makePermutation(s, ans, "", visit);
        return vector<string>(ans.begin(), ans.end());
    }

private:
    void makePermutation(const string &s, set<string> &ans, string curr, vector<bool> &visit)
    {
        if (curr.length() == s.length())
        {
            ans.insert(curr);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (!visit[i])
            {
                visit[i] = true;
                makePermutation(s, ans, curr + s[i], visit);
                visit[i] = false;
            }
        }
    }
};