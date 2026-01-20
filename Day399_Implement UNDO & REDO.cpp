// You are given a text document that is initially empty. You need to complete the following functions:

// void append(char x) - Append the character x to the end of the document.
// void undo() - Undo the most recent APPEND operation (remove the last appended character).
// void redo() - Reapply the most recent undone operation (restore the last character removed by UNDO).
// string read() - Return the current content of the document as a string.
// There will be a sequence of q queries arr[] on the document. The queries are represented in numeric form:

// 1 x - Call append(x)
// 2 - Call undo()
// 3 - Call redo()
// 4 - Call read()
// The driver code will process the queries, call the corresponding functions, and finally print the outputs of all READ() operations.
// You only need to implement the above four functions.

// Examples:

// Input: arr[] = [[1 'A'], [1 'B'], [1 'C'], [2], [4], [3], [4]]
// Output: ["AB", "ABC"]
// Explanation: For each query following changes are made into the document.
// 1st query: Append('A'), Document contains "A".
// 2nd query: Append('B'), Document contains "AB".
// 3rd query: Append('C'), Document contains "ABC".
// 4rth query: UNDO(), Last character is removed, Document contains "AB".
// 5th query: READ(), Document content will be printed.
// 6th query: REDO(), Document contains "ABC".
// 7th query: READ(), Document content will be printed.
// Input: arr[] = [[1 'D'], [2], [4]]
// Output: [""]
// Explanation: Queries will be processed as:
// 1st query: Append('D'), Document contains "D".
// 2nd query: UNDO(), Last character is removed, Document becomes empty.
// 3rd query: READ(), Empty Document will be printed.
class Solution
{
public:
    string s;
    stack<char> st1, st2;
    void append(char x)
    {
        st1.push(x);
        s.push_back(x);
    }
    void undo()
    {
        st2.push(st1.top());
        st1.pop();
        s.pop_back();
    }
    void redo()
    {
        s.push_back(st2.top());
        st1.push(st2.top());
        st2.pop();
    }
    string read()
    {
        return s;
    }
};