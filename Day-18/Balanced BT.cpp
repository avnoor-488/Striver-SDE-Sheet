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
        
    pair<bool,int> helper1(TreeNode *root)
    {
         if(root==NULL)
         {
             pair<bool,int>ans = make_pair(true,0);
             return ans;
         }
        
        
        pair<int,int> leftSubTree = helper1(root->left);
        pair<int,int> rightSubTree = helper1(root->right);
        
        
                
        bool leftSub = leftSubTree.first;
        bool rightSub = leftSubTree.first;
        
        
        bool diff = abs(leftSubTree.second - rightSubTree.second) <= 1;
        
        pair<bool,int> finalAns;
        finalAns.second = (leftSubTree.second,rightSubTree.second) +1;

        if(diff and leftSub and rightSub)
        finalAns.first = 1;
        else
        finalAns.first = 0;
        
        
        return finalAns;
    }
    bool isBalanced(TreeNode* root) {
        return helper1(root).first;
    
    }
};
