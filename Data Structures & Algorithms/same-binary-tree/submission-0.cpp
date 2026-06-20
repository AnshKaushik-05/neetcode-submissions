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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }else if(p==NULL && q!=NULL){
            return false;
        }else if(p!=NULL && q==NULL){
            return false;
        }

        bool isRootSame=(p->val == q->val);
        if(!isRootSame) return false;
        
        bool isLSTsame=isSameTree(p->left,q->left);
        bool isRSTsame=isSameTree(p->right,q->right);
        return isLSTsame && isRSTsame && isRootSame;
    }
};
