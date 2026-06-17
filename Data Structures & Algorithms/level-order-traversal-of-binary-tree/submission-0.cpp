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
    vector<vector<int>> bfs(TreeNode* root){
        vector<vector<int>>output;
        if(root==NULL){
            return output;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){

            vector<int>temp;
            int qSize=q.size();
            while(qSize--){
                TreeNode* cur=q.front();
                q.pop();
                temp.push_back(cur->val);

                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            output.push_back(temp);
        }
        return output;
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};
