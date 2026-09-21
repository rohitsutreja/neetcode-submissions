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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced1(TreeNode* root) {
        if (!root) {
            return true;
        }

        auto diff = height(root->left) - height(root->right);

        if (diff >= -1 && diff <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);
        }

        return false;
    }

    int isBalanced2(TreeNode* root, bool& res) {
        if (!root) {
            return 0;
        }

        auto left = isBalanced2(root->left,res);
        auto right = isBalanced2(root->right,res);

        if (std::abs(left - right) > 1) {
            res = false;
        }

        return 1 + std::max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool res = true;
        isBalanced2(root, res);
        return res;
    }
};
