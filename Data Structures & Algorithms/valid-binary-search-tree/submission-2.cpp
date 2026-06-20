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
    bool dfs(TreeNode* root,int lb,int ub){
        if(root==NULL){
            return true;
        }

        bool isRootValid=(root->val>lb)&&(root->val<ub);
        if(isRootValid){
            bool isLeftValid=dfs(root->left,lb,root->val);
            bool isRightValid=dfs(root->right,root->val,ub);
            return isLeftValid && isRightValid && isRootValid;
        }else{
            return false;
        }
        
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }
};
