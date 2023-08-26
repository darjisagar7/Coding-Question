/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void dfs(TreeNode* node, ostringstream& ans) {
        if (node == nullptr) {
            ans << "# ";
            return;
        }

        ans << node->val << " ";

        dfs(node->left, ans);
        dfs(node->right, ans);
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ans;
        dfs(root, ans);
        return ans.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
