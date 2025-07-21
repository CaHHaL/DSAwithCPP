// You are given an array arr[] of positive integers. Your task is to count the number of pairs (i, j) such that:

// 0 ≤ i < j ≤ n-1
// gcd(arr[i], arr[j]) = 1
// In other words, count the number of unordered pairs of indices (i, j) where the elements at those positions are co-prime.

// Examples:

// Input: arr[] = [1, 2, 3]
// Output: 3
// Explanation: (0,1), (0,2), (1,2) are the pair of indices where gcd(arr[i], arr[j]) = 1
// Input: arr[] = [4, 8, 3, 9]
// Output: 4
// Explanation: (0,2), (0,3), (1,2), (1,3) are the pair of indices where gcd(arr[i], arr[j]) = 1
class Solution {
  public:
    void computeMobius(int n, vector<int>& mu) {
        vector<int> is_prime(n + 1, 1);
        mu[0] = 0;
        mu[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    is_prime[j] = 0;
                }
                for (int j = i * i; j <= n; j += i * i) {
                    mu[j] = 0;
                }
            }
        }
    }
    void buildFre(vector<int>& arr, vector<int>& freq) {
        for (int x : arr)
            freq[x]++;
    }
    void computeDivCnt(int maxVal, vector<int>& freq, vector<int>& d) {
        for (int k = 1; k <= maxVal; ++k)
            for (int j = k; j <= maxVal; j += k)
                d[k] += freq[j];
    }
    int cntCoprime(vector<int>& arr) {
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal + 1, 0), d(maxVal + 1, 0), mu(maxVal + 1, 1);
        buildFre(arr, freq);
        computeDivCnt(maxVal, freq, d);
        computeMobius(maxVal, mu);
        int result = 0;
        for (int k = 1; k <= maxVal; ++k) {
            if (mu[k] == 0 || d[k] < 2)
                continue;
            int pairs = d[k] * (d[k] - 1) / 2;
            result += mu[k] * pairs;
        }
        return result;
    }
};