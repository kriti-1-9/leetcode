class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;
        TreeNode* parent = nullptr;

        while (curr != nullptr) {
            parent = curr;
            if (val > curr->val) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        if (val < parent->val) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }

        return root;
    }
};