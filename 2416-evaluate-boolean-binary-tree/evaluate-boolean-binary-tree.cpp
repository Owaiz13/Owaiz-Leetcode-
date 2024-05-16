class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // Base case: if it's a leaf node, return its value as a boolean
        if (!root->left && !root->right) {
            return root->val == 1;
        }
        
        // Recursive case: evaluate the left and right subtrees
        bool leftValue = evaluateTree(root->left);
        bool rightValue = evaluateTree(root->right);
        
        // Apply the boolean operation based on the value of the current node
        if (root->val == 2) {
            return leftValue || rightValue;
        } else if (root->val == 3) {
            return leftValue && rightValue;
        }
        
        // If the node value is not 0, 1, 2, or 3, something is wrong (though problem constraints ensure this won't happen)
        return false;
    }
};