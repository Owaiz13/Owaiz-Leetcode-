#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Choose the minimum value between the current rowSum and colSum
                int val = min(rowSum[i], colSum[j]);
                matrix[i][j] = val;
                // Subtract the chosen value from the current rowSum and colSum
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        
        return matrix;
    }
};
