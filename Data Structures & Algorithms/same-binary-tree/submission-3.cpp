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
    bool isSameTree(TreeNode* p, TreeNode* q) { return isSameTreeIterativeBFS(p, q); }

    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if ((!p && q) || (!q && p)) {
            return false;
        }

        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }

    bool isSameTreeIterative(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({p, q});

        while (!s.empty()) {
            auto [l, r] = s.top();
            s.pop();

            if (l->val != r->val) {
                return false;
            }

            if (l->right && r->right) {
                s.push({l->right, r->right});
            } else if (!l->right && !r->right) {
            } else {
                return false;
            }

            if (l->left && r->left) {
                s.push({l->left, r->left});
            } else if (!l->left && !r->left) {
            } else {
                return false;
            }
        }

        return true;
    }

    bool isSameTreeIterativeBFS(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        std::queue<std::pair<TreeNode*, TreeNode*>> qu{};
        qu.push({p, q});

        while (!qu.empty()) {
            auto [l, r]{qu.front()};
            qu.pop();

            if (!l && !r) {
                continue;
            }

            if (!l || !r) {
                return false;
            }

            if (l->val != r->val) {
                return false;
            }

            qu.push({l->left, r->left});
            qu.push({l->right, r->right});
        }

        return true;
    }
};
