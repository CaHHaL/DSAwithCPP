// Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance, defined as:

// sqrt( (x2 - x1)2 + (y2 - y1)2 )

// Note: You can return the k closest points in any order, driver code will sort them before printing.

// Examples:

// Input: k = 2, points[] = [[1, 3], [-2, 2], [5, 8], [0, 1]]
// Output: [[-2, 2], [0, 1]]
// Explanation: The Euclidean distances from the origin are:
// Point (1, 3) = sqrt(10)
// Point (-2, 2) = sqrt(8)
// Point (5, 8) = sqrt(89)
// Point (0, 1) = sqrt(1)
// The two closest points to the origin are [-2, 2] and [0, 1].
// Input: k = 1, points = [[2, 4], [-1, -1], [0, 0]]
// Output: [[0, 0]]
// Explanation: The Euclidean distances from the origin are:
// Point (2, 4) = sqrt(20)
// Point (-1, -1) = sqrt(2)
// Point (0, 0) = sqrt(0)
// The closest point to origin is (0, 0).

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto compare = [](vector<int> &a, vector<int> &b)
        {
            return distance(a) < distance(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

        for (auto &pt : points)
        {
            pq.push(pt);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

private:
    static int distance(vector<int> &point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
};