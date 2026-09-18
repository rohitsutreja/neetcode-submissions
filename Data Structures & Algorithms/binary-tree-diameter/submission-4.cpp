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
    int diameterOfBinaryTree(TreeNode* root) { return dfsIt(root); }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        res = std::max(res, left + right);

        return 1 + std::max(left, right);
    }

    int dfsIt(TreeNode* root) {
        if (!root) {
            return 0;
        }

        stack<std::pair<TreeNode*, bool>> st{};
        st.push({root, false});

        unordered_map<TreeNode*, int> mp{};

        while (!st.empty()) {
            auto [node, v] = st.top();

            if (v) {
                st.pop();
                mp[node] = 1 + max(mp[node->left], mp[node->right]);
                res = max(res, mp[node->left] + mp[node->right]);
            } else {
                st.top().second = true;
                if (node->right) {
                    st.push({node->right, false});
                }

                if (node->left) {
                    st.push({node->left, false});
                }
            }
        }

        return res;
    }

   private:
    int res{};
};
