/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to perform in-order traversal and collect node values
    void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }

    // Function to construct a balanced BST from sorted array
    TreeNode* sortedArrayToBST(vector<int>& nodes, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = sortedArrayToBST(nodes, left, mid - 1);
        root->right = sortedArrayToBST(nodes, mid + 1, right);
        return root;
    }

    // Main function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorderTraversal(root, nodes); // Collect the nodes in sorted order
        return sortedArrayToBST(nodes, 0, nodes.size() - 1); // Build balanced BST
    }
};
