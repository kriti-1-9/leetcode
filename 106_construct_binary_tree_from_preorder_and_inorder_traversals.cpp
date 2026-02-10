class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIdx = n - 1;
        unordered_map<int, int> inMap;
        for(int i=0; i<n; i++) {
            inMap[inorder[i]] = i;
        } 
        return solve(inorder, postorder, postIdx, 0, n-1, inMap);
    }
private:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        // Base case: no elements to process
        if (inStart > inEnd) return nullptr;
        
        // Pick the current root from postorder and move pointer backwards
        int curr = postorder[postIdx--];
        TreeNode* root = new TreeNode(curr);
        
        // Find index of this root in inorder traversal
        int mid = inMap[curr];
        
        // IMPORTANT: Build RIGHT subtree first because we are moving backwards in postorder
        root->right = solve(inorder, postorder, postIdx, mid + 1, inEnd, inMap);
        root->left = solve(inorder, postorder, postIdx, inStart, mid - 1, inMap);
        
        return root;
    }
};