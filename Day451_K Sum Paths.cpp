/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int solve(Node* root, long long currSum, int k, unordered_map<long long,int>& mp){
        if(root == NULL) return 0;
        
        currSum += root->data;
        
        int count = 0;
        
        if(mp.find(currSum - k) != mp.end()){
            count += mp[currSum - k];
        }
        
        mp[currSum]++;
        
        count += solve(root->left, currSum, k, mp);
        count += solve(root->right, currSum, k, mp);
        
        mp[currSum]--; // backtrack
        
        return count;
    }
  
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        
        return solve(root, 0, k, mp);
    }
};