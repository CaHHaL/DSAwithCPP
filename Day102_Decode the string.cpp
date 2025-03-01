// Given an encoded string s, the task is to decode it. The encoding rule is :

// k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets.
// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:

// Input: s = "1[b]"
// Output: "b"
// Explanation: "b" is present only one time.
// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// 1. Inner substring “2[ca]” breakdown into “caca”.
// 2. Now, new string becomes “3[bcaca]”
// 3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.

class Solution
{
public:
    string decodedString(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
                st.push(s[i]);
            else
            {
                string word;
                while (!st.empty() && st.top() != '[')
                {
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(), word.end());
                st.pop();
                string k;
                while (!st.empty() && isdigit(st.top()))
                {
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(), k.end());
                int num = stoi(k);
                string repeated;
                for (int j = 0; j < num; j++)
                {
                    repeated.append(word);
                }
                for (char c : repeated)
                    st.push(c);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};