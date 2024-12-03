// Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.
// Note: When you return '$' driver code will output -1.

// Examples:

// Input: s = "geeksforgeeks"
// Output: 'f'
// Explanation: In the given string, 'f' is the first character in the string which does not repeat.
// Input: s = "racecar"
// Output: 'e'
// Explanation: In the given string, 'e' is the only character in the string which does not repeat.
// Input: s = "aabbccc"
// Output: -1
// Explanation: All the characters in the given string are repeating



#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> freq_map;
        
        // Step 1: Count the frequency of each character
        for (char c : s) {
            freq_map[c]++;
        }
        
        // Step 2: Find the first character with frequency 1
        for (char c : s) {
            if (freq_map[c] == 1) {
                return c;  // return the first non-repeating character
            }
        }
        
        // Step 3: If no such character exists, return '$'
        return '$';
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;  // Read input string
    
    char result = solution.firstUniqChar(s);
    
    // Output result as per the requirement
    if (result == '$') {
        cout << -1 << endl;  // Output -1 when there is no non-repeating character
    } else {
        cout << result << endl;  // Output the first non-repeating character
    }
    
    return 0;
}
