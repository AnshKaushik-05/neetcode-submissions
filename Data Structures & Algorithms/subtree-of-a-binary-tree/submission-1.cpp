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
    bool sameTree(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        else if(root1==NULL || root2==NULL){
            return false;
        }

        if(root1->val==root2->val){
            bool isLSTsame=sameTree(root1->left,root2->left);
            bool isRSTsame=sameTree(root1->right,root2->right);
            return isLSTsame && isRSTsame;
        }
        return false;
    }

    void dfs(TreeNode* root,TreeNode* subRoot,bool& flag){
        if(root==NULL) return;
        if(flag) return;

        //recursive case
        if(root->val==subRoot->val && sameTree(root,subRoot)){
            flag=true;
            return; 
        }
        dfs(root->left,subRoot,flag);
        dfs(root->right,subRoot,flag);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag=false;
        dfs(root,subRoot,flag);
        return flag;
    }
};
