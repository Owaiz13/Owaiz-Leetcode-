#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> childNodes;

        // Create all nodes and establish parent-child relationships
        for (const auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2] == 1;

            // Create parent node if it does not exist
            if (nodeMap.find(parent) == nodeMap.end()) {
                nodeMap[parent] = new TreeNode(parent);
            }

            // Create child node if it does not exist
            if (nodeMap.find(child) == nodeMap.end()) {
                nodeMap[child] = new TreeNode(child);
            }

            // Establish the relationship
            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }

            // Record the child node
            childNodes.insert(child);
        }

        // Find the root node
        TreeNode* root = nullptr;
        for (const auto& entry : nodeMap) {
            if (childNodes.find(entry.first) == childNodes.end()) {
                root = entry.second;
                break;
            }
        }

        return root;
    }
};
