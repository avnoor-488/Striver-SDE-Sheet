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
    
    TreeNode * findPred(TreeNode* current) 
    {
        
        TreeNode *pred =current->left ;
        while(pred->right and pred->right!=current)
            pred = pred->right;
        
        return pred;
    }
    

        vector<int> inorderTraversal(TreeNode* root)
    {
            TreeNode *current = root;
            vector<int>output;
            
            while(current!=NULL)
            {
                if(current->left==NULL)
                {
                    output.push_back(current->val);
                    current = current->right;
                }
                
                else 
                {
                    TreeNode *pred = findPred(current);
                    if(pred->right==NULL)
                    {
                        pred->right = current;
                        current = current->left;
                    }
                    
                    else 
                    {
                        pred->right = NULL;
                        output.push_back(current->val);                                           
                        current = current->right;
                    }
                }
            }
            
            return output;
    }
};
