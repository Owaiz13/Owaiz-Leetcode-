class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        transform(root, sum);
        return root;
    }
    
    void transform(TreeNode* node, int &sum) {
        if (!node) return;
        
        // Traverse the right subtree first (reverse in-order)
        transform(node->right, sum);
        
        // Update the sum and the node's value
        sum += node->val;
        node->val = sum;
        
        // Traverse the left subtree
        transform(node->left, sum);
    }
};
