class Solution {
public:
    int findLength(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(findLength(root->left), findLength(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int Lh = findLength(root -> left);
        int Rh = findLength(root -> right);

        if(abs(Rh - Lh) > 1) return false;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        if(!left || !right) return false;

        return true;
    }
};