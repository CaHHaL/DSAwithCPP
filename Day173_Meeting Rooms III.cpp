// You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique.

//     Meeting Allocation Rules:

//     When a meeting starts, assign it to the available room with the smallest number.
//     If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
//     When a room becomes free, assign it to the delayed meeting with the earliest original start time.
//     Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.

//     Examples:

//     Input: n = 2, meetings[][] = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
//     Output: 1
//     Explanation: Time 0: Both rooms available. [0,6] starts in room 0.
//     Time 2: Room 0 busy until 6. Room 1 available. [2,3] starts in room 1.
//     Time 3: Room 1 frees up. [3,7] starts in room 1.
//     Time 4: Both rooms busy. [4,8] is delayed.
//     Time 6: Room 0 frees up. Delayed [4,8] starts in room 0 [6,10).
//     Time 6: [6,8] arrives but both rooms busy. It’s delayed.
//     Time 7: Room 1 frees up. Delayed [6,8] starts in room 1 [7,9).
//     Meeting counts: [2, 3]
//     Input: n = 4, meetings[][] = [[0, 8], [1, 4], [3, 4], [2, 3]
//     Output: 2
//     Explanation: Time 0: All rooms available. [0,8] starts in room 0.
//     Time 1: Room 0 busy until 8. Rooms 1, 2, 3 available. [1,4] starts in room 1.
//     Time 2: Rooms 0 and 1 busy. Rooms 2, 3 available. [2,3] starts in room 2.
//     Time 3: Room 2 frees up. [3,4] starts in room 2.
//     Meeting counts: [1, 1, 2, 0]

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n, 0);
        int maxi = 0, ans = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> initial;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            initial.push({i, i});
        }

        for (auto &i : meetings)
        {
            int s = i[0], e = i[1];
            int empty;

            while (!pq.empty() && pq.top().first <= s)
            {
                empty = pq.top().second;
                pq.pop();
                initial.push({empty, empty});
            }

            if (!initial.empty())
            {
                empty = initial.top().second;
                initial.pop();
                pq.push({e, empty});
                cnt[empty]++;
            }
            else
            {
                pair<int, int> temp = pq.top();
                pq.pop();
                int end_time = temp.first;
                empty = temp.second;
                int new_end = end_time + (e - s);
                pq.push({new_end, empty});
                cnt[empty]++;
            }

            if (cnt[empty] > maxi || (cnt[empty] == maxi && empty < ans))
            {
                maxi = cnt[empty];
                ans = empty;
            }
        }

        return ans;
    }
};