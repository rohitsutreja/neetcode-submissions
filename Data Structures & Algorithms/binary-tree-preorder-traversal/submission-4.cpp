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
 #include <ranges>
class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        if (!root) return {};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        l.insert(l.begin(), root->val);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }

    vector<int> dfsIt(TreeNode* root) {
        if (!root) return {};

        vector<int> result{};
        stack<TreeNode*> s{};

        auto* cur = root;

        while(cur || !s.empty()){
            while(cur){
                result.push_back(cur->val);
                s.push(cur->right);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
        }

        return result;
    }


    vector<int> preorderTraversal(TreeNode* root) {
       return dfsIt(root);
    }
};