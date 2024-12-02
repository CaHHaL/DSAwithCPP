// Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

// Note: You can assume both the strings s1 & s2 are non-empty.

// Examples :

// Input: s1 = "geeks", s2 = "kseeg"
// Output: true
// Explanation: Both the string have same characters with same frequency. So, they are anagrams.
// Input: s1 = "allergy", s2 = "allergic"
// Output: false
// Explanation: Characters in both the strings are not same, so they are not anagrams.
// Input: s1 = "g", s2 = "g"
// Output: true
// Explanation: Character in both the strings are same, so they are anagrams.



#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        // Step 1: If lengths are different, they cannot be anagrams
        if (s1.size() != s2.size()) {
            return false;
        }

        // Step 2: Create frequency count arrays for both strings
        vector<int> freq1(26, 0), freq2(26, 0);

        // Step 3: Count the frequency of each character in both strings
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;  // Count frequency of characters in s1
            freq2[s2[i] - 'a']++;  // Count frequency of characters in s2
        }

        // Step 4: Compare the frequency counts
        return freq1 == freq2;
    }
};

// Example usage:
int main() {
    Solution solution;
    
    string s1 = "geeks";
    string s2 = "kseeg";
    
    if (solution.areAnagrams(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
