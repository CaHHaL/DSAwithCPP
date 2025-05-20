// Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
// Note: The tree contains unique values.

// Examples :

// Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2

// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.
// Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

// Output: 5
// Explanation: Initially 10 is set to fire at 0 sec
// At 1 sec: Node 5 catches fire.
// At 2 sec: Node 2 catches fire.
// At 3 sec: Nodes 1 and 4 catches fire.
// At 4 sec: Node 3 and 8 catches fire.
// At 5 sec: Node 7 catches fire.
// It takes 5s to burn the complete tree.

class Solution
{
public:
    int minTime(Node *root, int target)
    {
        queue<Node *> que;
        que.push(root);
        unordered_map<Node *, Node *> parent;
        parent[root] = nullptr;
        Node *tar = nullptr;
        while (!que.empty())
        {
            Node *curr = que.front();
            que.pop();
            if (curr->data == target)
            {
                tar = curr;
            }
            if (curr->left)
            {
                que.push(curr->left);
                parent[curr->left] = curr;
            }

            if (curr->right)
            {
                que.push(curr->right);
                parent[curr->right] = curr;
            }
        }
        unordered_map<Node *, bool> visited;
        int t = -1;
        que.push(tar);

        while (!que.empty())
        {
            int n = que.size();

            while (n--)
            {
                Node *curr = que.front();
                que.pop();
                visited[curr] = true;
                if (curr->left && !visited[curr->left])
                {
                    que.push(curr->left);
                }

                if (curr->right && !visited[curr->right])
                {
                    que.push(curr->right);
                }

                if (parent[curr] && !visited[parent[curr]])
                {
                    que.push(parent[curr]);
                }
            }
            t++;
        }
        return t;
    }
};