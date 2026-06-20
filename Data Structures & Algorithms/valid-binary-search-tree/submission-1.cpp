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

class triple{
public:
    bool isValid;
    int min=INT_MAX;
    int max=INT_MIN;
};

class Solution {
public:
    triple dfs(TreeNode* root) {
        triple t;
        if(root==NULL){
            t.min=INT_MAX;
            t.max=INT_MIN;
            t.isValid=true;
            return t;
        }

        triple left=dfs(root->left);
        triple right=dfs(root->right);

        t.min=min(root->val,min(left.min,right.min));
        t.max=max(root->val,max(left.max,right.max));
        bool isRootValid=(root->val>left.max)&&(root->val<right.min);
        t.isValid=left.isValid && right.isValid && isRootValid;

        return t;
    }

    bool isValidBST(TreeNode* root){
        return dfs(root).isValid;
    }
};
