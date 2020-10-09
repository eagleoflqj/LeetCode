class Codec {
    void to_oss(ostringstream &oss, TreeNode *root) {
        if(!root) {
            oss << '.';
            return;
        }
        oss << root->val << ' ';
        to_oss(oss, root->left);
        oss << ' ';
        to_oss(oss, root->right);
    }
    TreeNode* from_iss(istringstream &iss) {
        string value;
        iss >> value;
        if(value[0] == '.')
            return nullptr;
        TreeNode *root = new TreeNode(stoi(value));
        root->left = from_iss(iss);
        root->right = from_iss(iss);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        to_oss(oss, root);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return from_iss(iss);
    }
};
