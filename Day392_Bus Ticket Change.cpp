// You are given an array arr[] representing passengers in a queue. Each bus ticket costs 5 coins, and arr[i] denotes the note a passenger uses to pay (which can be 5, 10, or 20). You must serve the passengers in the given order and always provide the correct change so that each passenger effectively pays exactly 5 coins. Your task is to determine whether it is possible to serve all passengers in the queue without ever running out of change.

// Examples:

// Input: arr[] = [5, 5, 5, 10, 20]
// Output: true
// Explanation: From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change we return true.
// Input: arr[] = [5, 5, 10, 10, 20]
// Output: false
// Explanation: From the first two customers in order, we collect two $5 bills. For the next two customers in order, we collect a $10 bill and give back a $5 bill. For the last customer, we can not give the change of $15 back because we only have two $10 bills. Since not every customer received the correct change, the answer is false.
class Solution
{
public:
    bool canServe(vector<int> &arr)
    {
        int five = 0, ten = 0;
        for (int bill : arr)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};