// Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

// Note: A palindrome string is a sequence of characters that reads the same forward and backward.

// Examples:

// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
// Input: s = "aacecaaaa"
// Output: 2
// Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"





#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minChar(string& s) {
        // Reverse the string to check the matching prefix
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // Concatenate the string with a separator
        string concat = s + "#" + rev_s;

        // Compute the LPS (Longest Prefix Suffix) array
        vector<int> lps(concat.size(), 0);
        int j = 0; // length of the previous longest prefix suffix

        // Fill the LPS array
        for (int i = 1; i < concat.size(); i++) {
            while (j > 0 && concat[i] != concat[j]) {
                j = lps[j - 1];
            }
            if (concat[i] == concat[j]) {
                j++;
            }
            lps[i] = j;
        }

        // The number of characters to add to the front is:
        // length of s - LPS value at the end of the concatenated string
        return s.size() - lps[concat.size() - 1];
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "abc";
    cout << sol.minChar(s1) << endl;  // Output: 2

    // Test case 2
    string s2 = "aacecaaaa";
    cout << sol.minChar(s2) << endl;  // Output: 2

    return 0;
}
