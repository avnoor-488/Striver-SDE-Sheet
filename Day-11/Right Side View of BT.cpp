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
    void solve(TreeNode *root,vector<int> &out,int lvl)
    {
        if(root==NULL)
            return;
        
        if(lvl==out.size())
            out.push_back(root->val);
        
        solve(root->right,out,lvl+1);
        solve(root->left,out,lvl+1);

        
    }             
  
    vector<int> rightSideView(TreeNode* root) {
        vector<int>output;
        solve(root,output,0);
        
        return output;
    
    }
};
