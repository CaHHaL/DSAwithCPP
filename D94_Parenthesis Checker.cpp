// Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
// An input string is valid if:

//          1. Open brackets must be closed by the same type of brackets.
//          2. Open brackets must be closed in the correct order.

// Examples :

// Input: s = "[{()}]"
// Output: true
// Explanation: All the brackets are well-formed.
// Input: s = "[()()]{}"
// Output: true
// Explanation: All the brackets are well-formed.
// Input: s = "([]"
// Output: False
// Explanation: The expression is not balanced as there is a missing ')' at the end.
// Input: s = "([{]})"
// Output: False
// Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.

class Solution
{
public:
    bool isBalanced(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (!st.empty() && ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') ||
                                    (st.top() == '{' && s[i] == '}')))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};