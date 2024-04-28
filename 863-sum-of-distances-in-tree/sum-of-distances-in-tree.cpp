class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<int> subtreeSize(n, 1); // Number of nodes in the subtree rooted at each node
        vector<int> ans(n, 0); // Stores the sum of distances for each node
        
        // Helper function for DFS traversal
        function<void(int, int)> dfs = [&](int node, int parent) {
            for (int child : tree[node]) {
                if (child != parent) {
                    dfs(child, node);
                    subtreeSize[node] += subtreeSize[child];
                    ans[node] += ans[child] + subtreeSize[child];
                }
            }
        };
        
        // Perform DFS from node 0
        dfs(0, -1);
        
        // Compute answer array based on the results obtained
        function<void(int, int)> computeAns = [&](int node, int parent) {
            for (int child : tree[node]) {
                if (child != parent) {
                    ans[child] = ans[node] - subtreeSize[child] + (n - subtreeSize[child]);
                    computeAns(child, node);
                }
            }
        };
        
        // Update answer array for all nodes
        computeAns(0, -1);
        
        return ans;
    }
};
