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
    int findMin(TreeNode* root){
        if(root==NULL){
            return INT_MAX;
        }
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }

    int findMax(TreeNode* root){
        if(root==NULL){
            return INT_MIN;
        }
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        bool isLSTvalid=isValidBST(root->left);
        bool isRSTvalid=isValidBST(root->right);
        bool isRootvalid= (root->val>findMax(root->left)) && (root->val<findMin(root->right));
        return isLSTvalid && isRSTvalid && isRootvalid;
    }
};
