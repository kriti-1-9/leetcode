class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is technically symmetric
        if (!root) return true;
        
        // Start the mirror check on the left and right children
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Case 1: Both nodes are null (reached the end of a branch)
        if (!t1 && !t2) return true;
        
        // Case 2: Only one is null, or values don't match
        if (!t1 || !t2 || t1->val != t2->val) return false;
        
        // Case 3: Recursively check the mirror positions
        // Outer nodes (left of left, right of right) 
        // AND Inner nodes (right of left, left of right)
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};