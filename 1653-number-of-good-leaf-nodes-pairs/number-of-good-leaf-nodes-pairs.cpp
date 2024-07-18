#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int &result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1}; // Leaf node

        auto leftDistances = dfs(node->left, distance, result);
        auto rightDistances = dfs(node->right, distance, result);

        // Count pairs
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }

        // Collect distances for the current node
        vector<int> distances;
        for (int d : leftDistances) {
            if (d + 1 <= distance) distances.push_back(d + 1);
        }
        for (int d : rightDistances) {
            if (d + 1 <= distance) distances.push_back(d + 1);
        }

        return distances;
    }
};
