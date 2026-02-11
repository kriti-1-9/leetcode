class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root; 
        while (node != nullptr && node->val != val) {
            if (val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node;
    }
};