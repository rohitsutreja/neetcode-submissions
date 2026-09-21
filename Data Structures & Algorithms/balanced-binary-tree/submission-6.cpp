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

 #include <expected>

class Solution {
   public:
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalancedBf(TreeNode* root) {
        if (!root) {
            return true;
        }

        auto diff = height(root->left) - height(root->right);

        if (diff >= -1 && diff <= 1) {
            return isBalancedBf(root->left) && isBalancedBf(root->right);
        }

        return false;
    }

    std::expected<int, std::monostate> isBalancedOptimized(TreeNode* root) {
        if (!root) {
            return 0;
        }

        auto left = isBalancedOptimized(root->left);

        if(!left){
            return left;
        }

        auto right = isBalancedOptimized(root->right);

        if(!right){
            return right;
        }

        if (std::abs(*left - *right) > 1) {
            return std::unexpected{std::monostate{}};
        }

        return 1 + std::max(*left, *right);
    }

    bool isBalancedIt(TreeNode* root){
        if(!root){
            return true;
        }
        
        stack<std::pair<TreeNode*, bool>> s{};
        std::unordered_map<TreeNode*, int> h{};

        s.push({root, false});

        while(!s.empty()){
            auto& [cur, v] = s.top();

            if(v){
                h[cur] = 1 + max(h[cur->left], h[cur->right]);
                if(std::abs(h[cur->left] - h[cur->right]) > 1){
                    return false;
                }
                s.pop();
            }
            else{
                v = true;

                if(cur->right){
                    s.push({cur->right, false});
                }

                if(cur->left){
                    s.push({cur->left, false});
                }
            }
        }

        return true;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedIt(root);
    }
};
