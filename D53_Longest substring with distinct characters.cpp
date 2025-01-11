// Given a string s, find the length of the longest substring with all distinct characters.

// Examples:

// Input: s = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest substring with all distinct characters.
// Input: s = "aaa"
// Output: 1
// Explanation: "a" is the longest substring with all distinct characters.
// Input: s = "abcdefabcbb"
// Output: 6
// Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        unordered_map<char, int> char_map; // To store the last index of each character
        int left = 0;                      // Left pointer of the window
        int max_length = 0;                // To track the maximum length of substring with distinct characters

        for (int right = 0; right < s.length(); ++right)
        {
            // If the character is already in the current window, move the left pointer
            if (char_map.find(s[right]) != char_map.end() && char_map[s[right]] >= left)
            {
                left = char_map[s[right]] + 1;
            }

            // Update the last index of the current character
            char_map[s[right]] = right;

            // Calculate the length of the current window and update the max length
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

int main()
{
    Solution solution;
    string s1 = "geeksforgeeks";
    cout << "Longest substring length in '" << s1 << "' is: " << solution.longestUniqueSubstr(s1) << endl;

    string s2 = "aaa";
    cout << "Longest substring length in '" << s2 << "' is: " << solution.longestUniqueSubstr(s2) << endl;

    string s3 = "abcdefabcbb";
    cout << "Longest substring length in '" << s3 << "' is: " << solution.longestUniqueSubstr(s3) << endl;

    return 0;
}
