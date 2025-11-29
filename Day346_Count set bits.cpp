// You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).

// Examples :

// Input: n = 4
// Output: 5
// Explanation: For numbers from 1 to 4. for 1: 0 0 1 => 1 set bit, for 2: 0 1 0 => 1 set bit, for 3: 0 1 1 => 2 set bits, for 4: 1 0 0 => 1 set bit. Therefore, the total set bits are 5.
// Input: n = 17
// Output: 35
// Explanation: From numbers 1 to 17(both inclusive), the total number of set bits are 35.
// Constraints:
// 1 ≤ n ≤ 108

class Solution
{
public:
    int countSetBits(int n)
    {
        int totaln = n + 1;
        int ones = 1;
        int count = 0;
        while (n != 0)
        {
            int temp = totaln / (ones * 2);
            count += (temp * ones);
            temp = totaln / ones;
            if (temp % 2 == 1)
                count += (totaln % ones);
            n >>= 1;
            ones *= 2;
        }
        return count;
    }
};