#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Helper function to perform topological sort
        auto topologicalSort = [&](int k, const vector<vector<int>>& conditions) -> vector<int> {
            vector<int> inDegree(k + 1, 0);
            unordered_map<int, unordered_set<int>> graph;
            for (const auto& condition : conditions) {
                int u = condition[0], v = condition[1];
                if (graph[u].insert(v).second) { // to handle duplicate edges
                    inDegree[v]++;
                }
            }

            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                for (int neighbor : graph[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            return order.size() == k ? order : vector<int>{};
        };

        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            matrix[rowPos[i]][colPos[i]] = i;
        }

        return matrix;
    }
};
