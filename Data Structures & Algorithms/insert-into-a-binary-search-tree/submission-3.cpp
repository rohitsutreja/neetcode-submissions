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
    TreeNode* insertIntoBST(TreeNode* root, int val) { return insertIntoBSTIterative(root, val); }

    TreeNode* insertIntoBSTRecursive(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode{val};
        }

        if (root->val < val) {
            root->right = insertIntoBSTRecursive(root->right, val);
        } else if (root->val > val) {
            root->left = insertIntoBSTRecursive(root->left, val);
        }

        return root;
    }

    TreeNode* insertIntoBSTIterative(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode{val};
        }

        auto* cur = root;

        while (cur) {
            if (cur->val > val) {
                if (!cur->left) {
                    cur->left = new TreeNode{val};
                    break;
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = new TreeNode{val};
                    break;
                }
                cur = cur->right;
            }
        };

        return root;
    }
};