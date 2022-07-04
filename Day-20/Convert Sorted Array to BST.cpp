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
    TreeNode* sortedArrayToBST(vector<int>& vec) {

        if(vec.size()==0)
            return NULL;
        
        if(vec.size()==1)
        {
            TreeNode *root = new TreeNode(vec[0]);
            return root;
        }
        
        int mid = vec.size()/2;
        
        TreeNode  *root = new TreeNode(vec[mid]);
        
        vector<int>leftTree(vec.begin(),vec.begin()+mid);
        vector<int> rightTree(vec.begin() + mid + 1 , vec.end());
        
        root->left = sortedArrayToBST(leftTree);
        root->right = sortedArrayToBST(rightTree);
        
        return root;
    }
};
