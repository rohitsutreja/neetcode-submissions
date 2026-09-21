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
    string inorder(TreeNode* root) {
        if (!root) {
            return "";
        }

        string result{};

        stack<TreeNode*> s{};
        auto* cur = root;

        while (cur || !s.empty()) {
            while (cur) {
                result += std::to_string(cur->val);
                result += "#";

                s.push(cur->right);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();

            if(!cur){
                result += "null#";
            }
        }

        std::cout << result << '\n';
        return result;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder(root).find(inorder(subRoot)) != std::string::npos;
    }
};
