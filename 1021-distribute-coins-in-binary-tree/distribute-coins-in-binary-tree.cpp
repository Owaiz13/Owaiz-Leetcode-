class Solution {
public:
    int totalMoves = 0;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftExcess = dfs(node->left);
        int rightExcess = dfs(node->right);
        
        // Current node's total excess is its value minus 1 (the coin it needs for itself)
        // plus the excess from the left and right subtrees.
        int nodeExcess = node->val - 1 + leftExcess + rightExcess;
        
        // The number of moves to balance the coins from/to this node is the absolute value
        // of the excesses from the left and right subtrees.
        totalMoves += abs(leftExcess) + abs(rightExcess);
        
        // Return the current node's total excess to its parent.
        return nodeExcess;
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return totalMoves;
    }
};
