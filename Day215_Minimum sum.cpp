// Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

// Examples :

// Input: arr[] = [6, 8, 4, 5, 2, 3]
// Output: "604"
// Explanation: The minimum sum is formed by numbers 358 and 246.
// Input: arr[] = [5, 3, 0, 7, 4]
// Output: "82"
// Explanation: The minimum sum is formed by numbers 35 and 047.
// Input: arr[] = [9, 4]
// Output: "13"
// Explanation: The minimum sum is formed by numbers 9 and 4.

class Solution
{
public:
    string addString(string &s1, string &s2)
    {
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int c = 0;
        string result = "";

        while (i >= 0 || j >= 0 || c > 0)
        {
            int sum = c;

            if (i >= 0)
            {
                sum += (s1[i] - '0');
            }
            if (j >= 0)
            {
                sum += (s2[j] - '0');
            }

            result.push_back(sum % 10 + '0');
            c = sum / 10;
            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int> &arr)
    {
        vector<int> count(10, 0);

        for (int num : arr)
        {
            count[num]++;
        }

        string s1 = "";
        string s2 = "";
        bool flag = true;

        for (int digit = 0; digit < 10; digit++)
        {
            while (count[digit]--)
            {
                if (flag)
                {
                    if (!(s1.empty() && digit == 0))
                    {
                        s1.push_back(digit + '0');
                    }
                    flag = false;
                }
                else
                {
                    if (!(s2.empty() && digit == 0))
                    {
                        s2.push_back(digit + '0');
                    }
                    flag = true;
                }
            }
        }

        return addString(s1, s2);
    }
};