// You are playing a game with n people standing in a circle, numbered from 1 to n. Starting from person 1, every kth person is eliminated in a circular fashion. The process continues until only one person remains.
// Given integers n and k, return the position (1-based index) of the person who will survive.

// Examples :

// Input: n = 5, k = 2
// Output: 3
// Explanation: Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed.
// Finally, the person at position 5 is killed. So the person at position 3 survives.
// Input: n = 7, k = 3
// Output: 4
// Explanation: The elimination order is 3 → 6 → 2 → 7 → 5 → 1, and the person at position 4 survives.
// Constraints:
class Solution
{
public:
    int josephus(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        int size = k, front;
        while (q.size() > 1)
        {
            while (size > 1)
            {
                front = q.front();
                q.pop();
                q.push(front);
                size--;
            }
            size = k;
            q.pop();
        }
        return q.front();
    }
};