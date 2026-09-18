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
    int maxDepth(TreeNode* root) { return maxDepthRecursive(root); }

    int maxDepthBFS(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int level{0};

        std::queue<TreeNode*> q{};
        q.push(root);

        while (!q.empty()) {
            auto numThisLevel = q.size();
            for (int i{}; i < numThisLevel; ++i) {
                auto* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            level++;
        }

        return level;
    }

    int maxDepthRecursive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + std::max(maxDepthRecursive(root->left),maxDepthRecursive(root->right)); 
    }
    
};
