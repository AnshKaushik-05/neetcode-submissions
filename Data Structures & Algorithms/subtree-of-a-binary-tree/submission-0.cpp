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
    bool flag=false;

    string f(TreeNode* subRoot){
        if(subRoot==NULL){
            return "";
        }

        string left=f(subRoot->left);
        string right=f(subRoot->right);
        string str=to_string(subRoot->val)+"/"+left+"/"+right;
        return str;
    }

    string fun(TreeNode* root,string&substr){
        if(root==NULL){
            return "";
        }

        string left=fun(root->left,substr);
        string right=fun(root->right,substr);
        string str=to_string(root->val)+"/"+left+"/"+right;
        if(str==substr) flag=true;
        return str;
    }

    

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string substr=f(subRoot);
        fun(root,substr);
        return flag;
    }
};
