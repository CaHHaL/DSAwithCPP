// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

// Note: The final output will be in lexicographic order.

// Examples:

// Input: arr[] = ["act", "god", "cat", "dog", "tac"]
// Output: [["act", "cat", "tac"], ["god", "dog"]]
// Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
// Input: arr[] = ["no", "on", "is"]
// Output: [["is"], ["no", "on"]]
// Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
// Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
// Output: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
// Explanation:
// Group 1: "abc", "bac", and "cab" are anagrams.
// Group 2: "listen", "silent", and "enlist" are anagrams.
// Group 3: "rat", "tar", and "art" are anagrams.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        unordered_map<string, vector<string>> mp;
        for (string word : arr)
        {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            mp[sorted_word].push_back(word);
        }
        vector<vector<string>> result;
        for (auto &pair : mp)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        vector<string> arr;
        string input_line;
        getline(cin, input_line);

        stringstream ss(input_line);
        string word;

        while (ss >> word)
        {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);

        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~" << "\n";
    }

    return 0;
}