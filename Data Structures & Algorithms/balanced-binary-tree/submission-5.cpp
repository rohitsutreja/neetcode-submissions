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

 #include <expected>

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

    std::expected<int, std::monostate> isBalanced2(TreeNode* root) {
        if (!root) {
            return 0;
        }

        auto left = isBalanced2(root->left);

        if(!left){
            return left;
        }

        auto right = isBalanced2(root->right);

        if(!right){
            return right;
        }

        if (std::abs(*left - *right) > 1) {
            return std::unexpected{std::monostate{}};
        }

        return 1 + std::max(*left, *right);
    }

    bool isBalanced(TreeNode* root) {
        return isBalanced2(root).has_value();
    }
};
