// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

// However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

// A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

// Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
// Input: words[] = ["caa", "aaa", "aab"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "cab".
// The pair "caa" and "aaa" suggests 'c' appears before 'a'.
// The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary.
// So, 'c' → 'a' → 'b' is a valid ordering.
// Input: words[] = ["ab", "cd", "ef", "ad"]
// Output: ""
// Explanation: No valid ordering of letters is possible.
// The pair "ab" and "ef" suggests "a" appears before "e".
// The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.

class Solution
{
public:
    bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis,
             vector<int> &rec, string &ans)
    {
        vis[u] = rec[u] = 1;

        for (int v = 0; v < 26; v++)
        {
            if (graph[u][v])
            {
                if (!vis[v])
                {
                    if (!dfs(v, graph, vis, rec, ans))
                        return false;
                }
                else if (rec[v])
                {
                    return false;
                }
            }
        }
        ans.push_back(char('a' + u));
        rec[u] = 0;
        return true;
    }
    string findOrder(vector<string> &words)
    {
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> exist(26, 0);
        vector<int> vis(26, 0);
        vector<int> rec(26, 0);
        string ans = "";

        for (string word : words)
        {
            for (char ch : word)
            {
                exist[ch - 'a'] = 1;
            }
        }

        for (int i = 0; i + 1 < words.size(); i++)
        {
            const string &a = words[i], &b = words[i + 1];
            int n = a.size(), m = b.size(), ind = 0;

            while (ind < n && ind < m && a[ind] == b[ind])
                ind++;

            if (ind != n && ind == m)
                return "";

            if (ind < n && ind < m)
                graph[a[ind] - 'a'][b[ind] - 'a'] = 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (exist[i] && !vis[i])
            {
                if (!dfs(i, graph, vis, rec, ans))
                {
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};