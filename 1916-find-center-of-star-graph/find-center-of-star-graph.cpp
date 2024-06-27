class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center of the star graph will be one of the nodes in the first edge.
        // We only need to check the second edge to determine the center node.
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};
