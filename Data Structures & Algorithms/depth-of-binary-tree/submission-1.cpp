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
    int dfs(TreeNode* root){
        if(root==NULL) return 0;

        int left=dfs(root->left);
        int right=dfs(root->right);
        return 1+max(left,right);
    }
    int bfs(TreeNode* root){
        queue<TreeNode*>q;
        if(root==NULL) return 0;
        q.push(root);
        int level=0;
        q.push(NULL);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur!=NULL){
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }                
            }else{
                level++;
                if(!q.empty()) q.push(NULL);
            }
        }
        return level;
    }
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};
