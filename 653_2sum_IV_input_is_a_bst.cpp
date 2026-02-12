class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode* root, int k, unordered_set<int>& seen) {
        if (root == nullptr) return false;
        int complement = k - root->val;
        if (seen.count(complement)) {
            return true;
        }
        seen.insert(root->val);
        return dfs(root->left, k, seen) || dfs(root->right, k, seen); 
    }
};