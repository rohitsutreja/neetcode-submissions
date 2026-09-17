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
    vector<int> iterative(TreeNode* root) {
        vector<int> result{};

        stack<std::pair<TreeNode*, bool>> s{};
        s.push({root, false});

        while (!s.empty()) {
            auto [cur, v] = s.top();

            if (!cur) {
                s.pop();
                continue;
            }

            if (v) {
                s.pop();
                result.push_back(cur->val);
            } else {
                s.top().second = true;
                s.push({cur->right, false});
                s.push({cur->left, false});
            }
        }

        return result;
    }

    vector<int> recursive(TreeNode* root) {
        if (!root) {
            return {};
        }

        auto l = postorderTraversal(root->left);
        auto r = postorderTraversal(root->right);

        l.insert(l.end(), r.begin(), r.end());
        l.push_back(root->val);

        return l;
    }

    vector<int> postorderTraversal(TreeNode* root) { return iterative(root); }
};