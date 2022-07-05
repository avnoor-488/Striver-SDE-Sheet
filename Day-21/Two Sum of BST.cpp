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
    vector<int>ans;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    bool solve(int key)
    {
        int i = 0 , j =ans.size()-1,sum=0;
        
        while(i<j)
        {
            sum = ans[i]+ans[j];
            
            if(sum==key)
                return true;
            else if(sum>key)
                j--;
            else 
                i++;
        }

      return false;       
        
    }
    bool findTarget(TreeNode* root, int key) {
        inorder(root);
        
        return solve(key);
    }
};
