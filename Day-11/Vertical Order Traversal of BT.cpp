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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode *,pair<int,int>>>q;
        vector<vector<int>>output;
        
        if(root==NULL)
            return output;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty())
        {
            pair<TreeNode* ,pair<int,int>>tempP = q.front();
            q.pop();
            TreeNode *frontNode = tempP.first;
            int dist = tempP.second.first;
            int level = tempP.second.second;
            
            nodes[dist][level].push_back(frontNode->val);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left,make_pair(dist-1,level+1)));
            if(frontNode->right)
                q.push(make_pair(frontNode->right,make_pair(dist+1,level+1)));
        }
        
        for(auto i:nodes)
        {
            vector<int>temp;
            for(auto j:i.second)
            {
                for(auto k:j.second)
                    temp.push_back(k);
                sort(temp.begin(),temp.end());
            }
            
            output.push_back(temp);
        }
        
        return output;
    }
};
