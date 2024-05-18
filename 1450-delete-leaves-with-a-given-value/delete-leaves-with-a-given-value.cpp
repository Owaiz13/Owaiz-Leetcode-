class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case: if the root is null, just return null.
        if (root == nullptr) return nullptr;
        
        // Recursively remove leaf nodes with the target value in the left subtree.
        root->left = removeLeafNodes(root->left, target);
        // Recursively remove leaf nodes with the target value in the right subtree.
        root->right = removeLeafNodes(root->right, target);
        
        // Check if the current node is a leaf node and if its value is equal to the target.
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr; // Remove the leaf node.
        }
        
        return root; // Return the possibly updated root.
    }
};
