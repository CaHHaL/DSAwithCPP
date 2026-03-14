/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int,int> mp; 
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int hd = temp.second;
    
            if(mp.find(hd) == mp.end()){
                mp[hd] = node->data;
            }
            
            if(node->left){
                q.push({node->left, hd - 1});
            }
            
            if(node->right){
                q.push({node->right, hd + 1});
            }
        }
        
        for(auto x : mp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};