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
    void f(TreeNode* root,string&s){
        if(root==NULL){
            s+="$#";
            return;
        }

        s+="$";
        s+=to_string(root->val);
        f(root->left,s);
        f(root->right,s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string strRoot="";
        f(root,strRoot);
        string strSubroot="";
        f(subRoot,strSubroot);
        if(strRoot.find(strSubroot)!=string::npos){
            return true;
        }
        return false;
    }
};
