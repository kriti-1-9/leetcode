class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursion(root, 0, result);
        return result;
    }

private:
    void recursion(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) return;

        // If this is the first time we've reached this level, add the node
        if (result.size() == level) {
            result.push_back(root->val);
        }

        // IMPORTANT: Go Right first, then Left
        recursion(root->right, level + 1, result);
        recursion(root->left, level + 1, result);
    }
};