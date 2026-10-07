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
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeRecursiveAlt(root, key);
    }        

    TreeNode* deleteNodeRecursive(TreeNode* root, int key) {
        if(!root){
            return root;
        }

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left){
                root = root->right;
                return root;
            }
            else if(!root->right){
                root = root->left;
                return root;
            }
            else{
                auto* cur = root->left;

                while(cur->right){
                    cur = cur->right;
                }

                std::swap(cur->val, root->val);

                root->left = deleteNode(root->left, cur->val);
            }
        }

        return root;
    }        

    TreeNode* deleteNodeRecursiveAlt(TreeNode* root, int key) {
        if(!root){
            return root;
        }

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left){
                root = root->right;
                return root;
            }
            else if(!root->right){
                root = root->left;
                return root;
            }
            else{
                auto* cur = root->left;

                while(cur->right){
                    cur = cur->right;
                }

                cur->right = root->right;
                root = root->left;
                
            }
        }

        return root;
    }        



    TreeNode* deleteNodeIterative(TreeNode* root, int key) {
 
    }        
};