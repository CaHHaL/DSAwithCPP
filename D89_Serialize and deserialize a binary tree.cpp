// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

// Examples :

// Input: root = [1, 2, 3]

// Output: [2, 1, 3]
// Input: root = [10, 20, 30, 40, 60, N, N]

// Output: [40, 20, 60, 10, 30]

class Solution
{
public:
    void serializeHelper(Node *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            arr.push_back(-1);
            return;
        }
        arr.push_back(root->data);
        serializeHelper(root->left, arr);
        serializeHelper(root->right, arr);
    }

    vector<int> serialize(Node *root)
    {
        vector<int> arr;
        serializeHelper(root, arr);
        return arr;
    }
    Node *deSerializeHelper(vector<int> &arr, int &index)
    {
        if (index >= arr.size() || arr[index] == -1)
        {
            index++;
            return NULL;
        }
        Node *node = new Node(arr[index++]);
        node->left = deSerializeHelper(arr, index);
        node->right = deSerializeHelper(arr, index);

        return node;
    }

    Node *deSerialize(vector<int> &arr)
    {
        int index = 0;
        return deSerializeHelper(arr, index);
    }
};