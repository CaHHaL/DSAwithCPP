// You are given an array arr[ ], where arr[i] represents the height of the ith person standing in a line.
// A person i can see another person j if:

// height[j] < height[i],
// There is no person k standing between them such that height[k] ≥ height[i].

// Each person can see in both directions (front and back).
// Your task is to find the maximum number of people that any person can see (including themselves).

// Examples:

// Input: arr[] = [6, 2, 5, 4, 5, 1, 6 ]
// Output: 6
// Explanation:
// Person 1 (height = 6) can see five other people at following positions (2, 3, 4, 5. 6) in addition to himself, i.e. total 6.
// Person 2 (height: 2) can see only himself.
// Person 3 (height = 5) is able to see people 2nd, 3rd, and 4th person.
// Person 4 (height = 4) can see himself.
// Person 5 (height = 5) can see people 4th, 5th, and 6th.
// Person 6 (height =1) can only see himself.
// Person 7 (height = 6) can see 2nd, 3rd, 4th, 5th, 6th, and 7th people.
// A maximum of six people can be seen by Person 1, 7th
// Input: arr[] = [1, 3, 6, 4]
// Output: 4
// Explanation:
// Person with height 6 can see persons with heights 1, 3 on the left and 4 on the right, along with himself, giving a total of 4.
// Constraints:
// 1 ≤ arr.size() ≤ 104
// 1 ≤ arr[i] ≤ 105

#
class Solution
{
public:
    int maxPeople(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                int ind = st.top();
                st.pop();
                int l_people = st.empty() ? ind + 1 : ind - st.top();
                int r_people = i - ind - 1;
                ans = max(ans, l_people + r_people);
            }
            st.push(i);
        }
        int last = n;
        while (!st.empty())
        {
            int ind = st.top();
            st.pop();
            int l_people = st.empty() ? ind + 1 : ind - st.top();
            int r_people;
            if (last < n && arr[last] == arr[ind])
            {
                r_people = last - ind - 1;
            }
            else
            {
                r_people = n - ind - 1;
            }
            ans = max(ans, l_people + r_people);
            last = ind;
        }
        return ans;
    }
};