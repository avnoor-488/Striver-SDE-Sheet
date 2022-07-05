/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    
    vector<int>ans;
    void solve(Node *root)
    {
        if(root==NULL)
            return ;
        
        solve(root->left);
        ans.push_back(root->data);
        solve(root->right);        
    }
    
    int kthLargest(Node *root, int k)
    {
        //Your code here
        solve(root);
        return ans[ans.size()  - k];
    }
};
