class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the first row of dp with the same values as the first row of grid
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Initialize minSum to the maximum integer value
                int minSum = numeric_limits<int>::max();
                for (int k = 0; k < n; ++k) {
                    if (k != j) { // Ensure not in the same column
                        minSum = min(minSum, dp[i - 1][k]);
                    }
                }
                dp[i][j] = minSum + grid[i][j];
            }
        }
        
        // Find the minimum sum in the last row of dp
        int minPathSum = numeric_limits<int>::max();
        for (int j = 0; j < n; ++j) {
            minPathSum = min(minPathSum, dp[n - 1][j]);
        }
        
        return minPathSum;
    }
};