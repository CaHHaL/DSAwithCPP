// You are given a lowercase string s, determine the total number of distinct strings that can be formed using the following rules:

// Identify all unique vowels (a, e, i, o, u) present in the string.
// For each distinct vowel, choose exactly one of its occurrences from s. If a vowel appears multiple times, each occurrence represents a unique selection choice.
// Generate all possible permutations of the selected vowels. Each unique arrangement counts as a distinct string.
// Return the total number of such distinct strings.

// Examples:

// Input: s = "aeiou"
// Output: 120
// Explanation: Each vowel appears once, so the number of different strings can form is 5! = 120.
// Input: s = "ae"
// Output: 2
// Explanation: Pick a and e, make all orders → "ae", "ea".
// Input: s = "aacidf"
// Output: 4
// Explanation: Vowels in s are 'a' and 'i', Pick each 'a' once with a single 'i', make all orders → "ai", "ia", "ai", "ia".
class Solution
{
public:
    int vowelCount(string &s)
    {
        unordered_map<char, int> freq;
        string vowels = "aeiou";
        for (char ch : s)
        {
            if (vowels.find(ch) != string::npos)
            {
                freq[ch]++;
            }
        }
        int count = 1, uniqueVowelCount = 0;
        for (char v : vowels)
        {
            if (freq.count(v))
            {
                count *= freq[v];
                uniqueVowelCount++;
            }
        }
        if (uniqueVowelCount == 0)
            return 0;
        int fact = 1;
        for (int i = 2; i <= uniqueVowelCount; ++i)
        {
            fact *= i;
        }
        return count * fact;
    }
};