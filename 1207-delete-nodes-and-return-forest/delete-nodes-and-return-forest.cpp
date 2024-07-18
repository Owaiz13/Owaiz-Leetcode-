#include <vector>
#include <unordered_set>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        root = helper(root, toDeleteSet, result);
        
        if (root != nullptr) {
            result.push_back(root);
        }
        
        return result;
    }

private:
    TreeNode* helper(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& result) {
        if (node == nullptr) {
            return nullptr;
        }
        
        node->left = helper(node->left, toDeleteSet, result);
        node->right = helper(node->right, toDeleteSet, result);
        
        if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
            if (node->left != nullptr) {
                result.push_back(node->left);
            }
            if (node->right != nullptr) {
                result.push_back(node->right);
            }
            return nullptr;
        }
        
        return node;
    }
};
