#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Create an adjacency list and in-degree array
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Perform topological sort using Kahn's algorithm (BFS)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<set<int>> ancestors(n);  // Use a set to avoid duplicates and maintain order
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                ancestors[neighbor].insert(node);
                for (int ancestor : ancestors[node]) {
                    ancestors[neighbor].insert(ancestor);
                }

                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Convert sets to sorted vectors for the final output
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};
