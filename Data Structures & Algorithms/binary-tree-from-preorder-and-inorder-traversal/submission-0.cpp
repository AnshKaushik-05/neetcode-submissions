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
    unordered_map<int,int>mp;

    TreeNode* f(vector<int>&preorder,vector<int>&inorder,int i,int l,int r){
        if(l>r)return NULL;

        //recursive-case
        int val=preorder[i];
        TreeNode* root=new TreeNode(val);
        root->left=f(preorder,inorder,i+1,l,mp[val]-1);
        int numOfNodesInLST=mp[val]-l;
        root->right=f(preorder,inorder,i+numOfNodesInLST+1,mp[val]+1,r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            int x=inorder[i];
            mp[x]=i;
        }
        int n=inorder.size();
        return f(preorder,inorder,0,0,n-1);
    }
};
