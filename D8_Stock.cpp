// Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

// Note: Stock must be bought before being sold.

// Examples:

// Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
// Output: 8
// Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.
// Input: prices[] = [7, 6, 4, 3, 1]
// Output: 0 
// Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.
// Input: prices[] = [1, 3, 6, 9, 11]
// Output: 10 
// Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].







#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX

using namespace std;

int maxProfit(const vector<int>& prices) {
    if (prices.size() < 2) return 0;  // If there are less than 2 prices, no transaction can be made
    
    int minPrice = INT_MAX;  // Set to the largest possible value initially
    int maxProfit = 0;  // No profit at the start

    // Loop through the prices array
    for (int price : prices) {
        // Update minPrice if a new lower price is found
        if (price < minPrice) {
            minPrice = price;
        }
        // Calculate profit by selling at the current price
        int profit = price - minPrice;
        
        // Update maxProfit if the current profit is higher
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;  // Return the maximum profit found
}

int main() {
    // Test cases
    vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {1, 3, 6, 9, 11};

    cout << "Max profit for prices1: " << maxProfit(prices1) << endl;  // Output: 8
    cout << "Max profit for prices2: " << maxProfit(prices2) << endl;  // Output: 0
    cout << "Max profit for prices3: " << maxProfit(prices3) << endl;  // Output: 10

    return 0;
}
