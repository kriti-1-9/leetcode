struct NodeInfo {
    bool isBST;
    int sum;
    int minVal;
    int maxVal;
};

class Solution {
    int maxTotalSum = 0;

public:
    int maxSumBST(TreeNode* root) {
        maxTotalSum = 0;
        solve(root);
        return maxTotalSum;
    }

    NodeInfo solve(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSum = root->val + left.sum + right.sum;
            maxTotalSum = max(maxTotalSum, currentSum);
            return {true, currentSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }
        return {false, 0, 0, 0};
    }
};