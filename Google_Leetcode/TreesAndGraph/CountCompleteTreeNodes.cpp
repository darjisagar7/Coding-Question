/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        if (root->left == nullptr) {
            return 1 + countNodes(root->right);
        } else if (root->right == nullptr) {
            return 1 + countNodes(root->left);
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
