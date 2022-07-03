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
    bool solve(TreeNode *first,TreeNode *second)
    {
        if(first==NULL and second==NULL)
            return true;
        else if(!first or !second)
            return false;
        
        if(first->val!=second->val)
            return false;
        
        return solve(first->left,second->right) and solve(first->right,second->left);
            
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return solve(root->left,root->right);
    }
};
