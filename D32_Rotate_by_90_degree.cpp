// Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

// Examples:

// Input: mat[][] = [[1, 2, 3],
//                 [4, 5, 6]
//                 [7, 8, 9]]
// Output: Rotated Matrix:
// [3, 6, 9]
// [2, 5, 8]
// [1, 4, 7]
// Input: mat[][] = [[1, 2],
//                 [3, 4]]
// Output: Rotated Matrix:
// [2, 4]
// [1, 3] in c++ 


#include <vector>
#include <iostream>
#include <algorithm> // for reverse function
using namespace std;

class Solution {
public:
    // Function to rotate the matrix by 90 degrees in anti-clockwise direction
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();

        // Step 1: Transpose the matrix (swap mat[i][j] with mat[j][i])
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each column of the transposed matrix
        for (int i = 0; i < n; ++i) {
            int start = 0, end = n - 1;
            while (start < end) {
                swap(mat[start][i], mat[end][i]);
                start++;
                end--;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Original Matrix 1:" << endl;
    for (auto& row : mat1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    sol.rotateby90(mat1);
    cout << "\nRotated Matrix 1:" << endl;
    for (auto& row : mat1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Test Case 2
    vector<vector<int>> mat2 = {
        {1, 2},
        {3, 4}
    };
    cout << "\nOriginal Matrix 2:" << endl;
    for (auto& row : mat2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    sol.rotateby90(mat2);
    cout << "\nRotated Matrix 2:" << endl;
    for (auto& row : mat2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
