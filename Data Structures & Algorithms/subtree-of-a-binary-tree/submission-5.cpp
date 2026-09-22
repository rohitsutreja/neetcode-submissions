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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { return isSubtreeIt(root, subRoot); }

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

    bool isSubtreeRecursive(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }

        if (!root) {
            return false;
        }

        if (root && !subRoot) {
            return true;
        }

        return isSameTreeRecursive(root, subRoot) || isSubtreeRecursive(root->left, subRoot) ||
               isSubtreeRecursive(root->right, subRoot);
    }

    string preorder(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::string res{};

        stack<TreeNode*> s{};
        auto* cur = root;

        while (cur || !s.empty()) {
            while (cur) {
                res += (std::to_string(cur->val) + "#");
                s.push(cur->right);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();

            if(!cur){
                res += "null#";
            }
        }

        return res;
    }

    bool isSubtreeIt(TreeNode* root, TreeNode* subRoot) {
        auto r = preorder(root);
        return r.find(preorder(subRoot)) != std::string::npos;
    }
};
