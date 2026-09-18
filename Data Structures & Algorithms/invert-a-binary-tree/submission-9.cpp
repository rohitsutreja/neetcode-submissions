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
    TreeNode* invertTree(TreeNode* root) { return invertTreeIterative2(root); }

    TreeNode* invertTreeRecursive(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        std::swap(root->left, root->right);
        invertTreeRecursive(root->left);
        invertTreeRecursive(root->right);
        return root;
    }

    TreeNode* invertTreeIterative(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        stack<TreeNode*> s{};
        s.push(root);

        while (!s.empty()) {
            auto top = s.top();
            s.pop();

            if (top->left) {
                s.push(top->left);
            }
            if (top->right) {
                s.push(top->right);
            }

            std::swap(top->left, top->right);
        }

        return root;
    }

    TreeNode* invertTreeIterative2(TreeNode* root) { 
        if(!root){
            return nullptr;
        }

        std::queue<TreeNode*> q{};
        q.push(root);

        while(!q.empty()){
            auto* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }

            std::swap(node->left, node->right);
        }

        return root; 
    }
};
