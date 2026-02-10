class Codec {
public:
    // 1. Serialize: Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // 2. Deserialize: Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "# "; // Use # to represent null, followed by a space delimiter
            return;
        }
        // Root -> Left -> Right
        out << root->val << " ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val; // Read the next "word" from the stream
        
        if (val == "#") {
            return nullptr;
        }

        // Create the node and recursively build subtrees
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);
        
        return root;
    }
};