/*Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Use unsigned long long to handle large numbers
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Initialize the first column to 1
        // This represents the number of ways to form an empty string
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If the current characters match
                if (s[i-1] == t[j-1]) {
                    // We have two choices:
                    // 1. Use the current character: dp[i-1][j-1]
                    // 2. Don't use the current character: dp[i-1][j]
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    // If they don't match, we can only skip the current character in s
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};
