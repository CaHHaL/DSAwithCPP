// Given an array of strings words[]. Find the longest string in words[] such that every prefix of it is also present in the array words[].

// Note: If multiple strings have the same maximum length, return the lexicographically smallest one.

// Examples:

// Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
// Output: pros
// Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array words[].
// Input: words[] = ["ab", "a", "abc", "abd"]
// Output: abc
// Explanation: Both "abc" and "abd" has all the prefixes in words[]. Since, "abc" is lexicographically smaller than "abd", so the output is "abc".

class Solution
{
public:
    struct TrieNode
    {
        bool isEndOfWord;
        TrieNode *children[26];

        TrieNode()
        {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    TrieNode *root = new TrieNode();
    void insert(string &word)
    {
        TrieNode *crawler = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (crawler->children[index] == nullptr)
            {
                crawler->children[index] = new TrieNode();
            }
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true;
    }
    bool search(string &word)
    {
        TrieNode *crawler = root;

        for (char c : word)
        {
            int index = c - 'a';
            crawler = crawler->children[index];
            if (crawler == nullptr || crawler->isEndOfWord == false)
            {
                return false;
            }
        }
        return true;
    }

    string longestString(vector<string> &arr)
    {
        for (string &word : arr)
        {
            insert(word);
        }

        string result = "";
        for (string &word : arr)
        {
            if (search(word))
            {
                if (word.length() > result.length() ||
                    (word.length() == result.length() && word < result))
                {
                    result = word;
                }
            }
        }
        return result;
    }
};