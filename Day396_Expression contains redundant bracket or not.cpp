// Given a string of balanced expression s, check if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

// Examples:

// Input: s = "((a+b))"
// Output: true
// Explanation: ((a+b)) can reduced to (a+b).
// Input: s = "(a+(b)/c)"
// Output: true
// Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.
// Input: s = "(a+b+(c+d))"
// Output: false
// Explanation:(a+b+(c+d)) doesn't have any redundant or multiple brackets.
class Solution
{
public:
    bool checkRedundancy(string &s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c != ')')
                st.push(c);
            else
            {
                int x = 0;
                while (st.top() != '(')
                {
                    st.pop();
                    x++;
                }
                st.pop();
                if (x < 2)
                    return 1;
            }
        }
        return 0;
    }
};