class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map: [col] -> [row] -> [values]
        map<int, map<int, multiset<int>>> nodes;
        traverse(root, 0, 0, nodes);
        
        vector<vector<int>> result;
        for (auto& colPair : nodes) {
            vector<int> col;
            for (auto& rowPair : colPair.second) {
                // Insert all elements from the sorted multiset into the column vector
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            result.push_back(col);
        }
        return result;
    }

private:
    void traverse(TreeNode* node, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (!node) return;
        
        nodes[x][y].insert(node->val);
        
        traverse(node->left, x - 1, y + 1, nodes);
        traverse(node->right, x + 1, y + 1, nodes);
    }
};