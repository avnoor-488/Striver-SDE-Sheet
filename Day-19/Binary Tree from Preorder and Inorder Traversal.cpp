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
    
    void findPos(vector<int>pre,vector<int>in,int size,unordered_map<int,int> &mp)
    {
            for(int i= 0;i<size;i++)
                mp[in[i]]  = i;
    }
    

    TreeNode *solve(vector<int>& pre, vector<int>& in,int &index,int start,int end,unordered_map<int,int> mp)
    {
        if(start>end)
            return NULL;
        
        int ele = pre[index++];
        TreeNode *root = new TreeNode(ele);
        
        if(start==end)
            return root;
        
        int position = mp[ele];
        
        //recursion calls;
        
        root->left = solve(pre,in,index,start,position-1,mp);
        root->right = solve(pre,in,index,position +1 , end , mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
      //inorder --> LNR
        //preorder -->LNR
        unordered_map<int,int>mp;
        int n = pre.size(),preIndx = 0;
        
        findPos(pre,in,in.size(),mp);
        return solve(pre,in,preIndx,0,n-1,mp);
        
    }
};
