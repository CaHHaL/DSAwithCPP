// Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
// Return all such non-zero sums (order does not matter).

// Examples:

// Input: s = "abacab"
// Output: [293, 294]
// Explanation: characters 'a' and 'b' appear more than once:
// 'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
// 'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.
// Input: s = "acdac"
// Output: [197, 199]
// Explanation: characters 'a' and 'c' appear more than once:
// 'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
// 'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.

class Solution {
  public:
    vector<int> asciirange(string& s) {
        vector<int>first(26,-1), last(26,-1),ans;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(first[idx]==-1) first[idx]=i;
            last[idx]=i;
        }
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && last[i]!=-1 && first[i]<last[i]){
                int sum=0;
                for(int j=first[i]+1;j<last[i];j++){
                    sum+=s[j];
                }
                if(sum) ans.push_back(sum);
            }
        }
        return ans;
    }
};