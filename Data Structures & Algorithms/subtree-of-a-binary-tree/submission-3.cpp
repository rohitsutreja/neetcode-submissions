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
    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if ((!p && q) || (!q && p)) {
            return false;
        }

        if (p->val == q->val) {
            return isSameTreeRecursive(p->left, q->left) && isSameTreeRecursive(p->right, q->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }

        if (!root && subRoot) {
            return false;
        }

        if (root && !subRoot) {
            return true;
        }

        return isSameTreeRecursive(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
