#include <vector>
#include <string>

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> pathToStart, pathToDest;
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);
        
        int i = 0;
        // Find the first divergence point
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        string result;
        // Add 'U' for every step we need to move up from the startValue to the common ancestor
        for (int j = i; j < pathToStart.size(); j++) {
            result += 'U';
        }
        // Add the remaining path from the common ancestor to the destValue
        for (int j = i; j < pathToDest.size(); j++) {
            result += pathToDest[j];
        }

        return result;
    }

private:
    // Helper function to find the path from the root to the given value
    bool findPath(TreeNode* root, int value, vector<char>& path) {
        if (!root) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (findPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};
