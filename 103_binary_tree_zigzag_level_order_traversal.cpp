class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // Determine the position to insert the node value
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = node->val;

                // Standard BFS child pushing
                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }

            // Flip the direction for the next level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};