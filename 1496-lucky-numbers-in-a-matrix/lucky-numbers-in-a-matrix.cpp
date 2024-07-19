#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Find the minimum element in each row
        vector<int> minRow(m);
        for (int i = 0; i < m; ++i) {
            minRow[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }

        // Step 2: Check if the minimum element in each row is the maximum in its column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minRow[i]) {
                    bool isMaxInCol = true;
                    for (int k = 0; k < m; ++k) {
                        if (matrix[k][j] > matrix[i][j]) {
                            isMaxInCol = false;
                            break;
                        }
                    }
                    if (isMaxInCol) {
                        result.push_back(matrix[i][j]);
                    }
                }
            }
        }

        return result;
    }
};
