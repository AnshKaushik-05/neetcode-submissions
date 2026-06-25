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
    string f(TreeNode* root){
        if(root==NULL){
            return "";
        }

        string left=f(root->left);
        string right=f(root->right);
        return "$"+to_string(root->val)+"("+left+")("+right+")";
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string strRoot=f(root);
        string strSubroot=f(subRoot);
        return strRoot.contains(strSubroot);
    }
};
