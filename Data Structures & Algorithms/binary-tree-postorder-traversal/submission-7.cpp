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
        if (!root) {
            return {};
        }
        vector<int> result{};

        stack<std::pair<TreeNode*, bool>> s{};
        s.push({root, false});

        while (!s.empty()) {
            auto [cur, v] = s.top();

            if (v) {
                s.pop();
                result.push_back(cur->val);
            } else {
                s.top().second = true;
                if (cur->right) {
                    s.push({cur->right, false});
                }
                if (cur->left) {
                    s.push({cur->left, false});
                }
            }
        }

        return result;
    }

    vector<int> iterative2(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::vector<int> result{};

        stack<TreeNode*> s{};
        TreeNode* last = nullptr;

        auto* cur = root;

        while (cur || !s.empty()) {

            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();

            if(cur->right && last != cur->right){
                cur = cur->right;
            }
            else{
                result.push_back(cur->val);
                last = cur;
                s.pop();
                cur = nullptr;
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

    vector<int> postorderTraversal(TreeNode* root) { return iterative2(root); }
};