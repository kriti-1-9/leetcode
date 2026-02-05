class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        calculateGain(root, globalMax);
        return globalMax;
    }

private:
    int calculateGain(TreeNode* node, int& globalMax) {
        if (!node) return 0;

        // Recursively find the max path sum of left and right subtrees
        // If a subtree returns a negative value, we ignore it (take 0)
        int leftGain = max(calculateGain(node->left, globalMax), 0);
        int rightGain = max(calculateGain(node->right, globalMax), 0);

        // Path sum if the current node is the "highest" point (peak) of the path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum if the current local path is better
        globalMax = max(globalMax, currentPathSum);

        // Return the max gain this node can contribute to its parent
        // (Node value + the best single branch)
        return node->val + max(leftGain, rightGain);
    }
};