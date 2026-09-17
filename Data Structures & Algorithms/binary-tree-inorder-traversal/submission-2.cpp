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

    vector<int> inorderRecursive(TreeNode* root){
        if(!root){
            return {};
        }

        auto leftRes{inorderRecursive(root->left)};
        auto rightRes{inorderRecursive(root->right)};

        leftRes.push_back(root->val);
        leftRes.insert(leftRes.end(), rightRes.begin(), rightRes.end());

        return leftRes;
    }

vector<int> inorderIterative(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<int> result{};
    stack<TreeNode*> s{};
    auto* cur = root;

    while (cur || !s.empty()) {
        while(cur){
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();

        result.push_back(cur->val);

        cur = cur->right;
    }

    return result;
}

    vector<int> inorderTraversal(TreeNode* root) {
        return inorderIterative(root);
    }
};