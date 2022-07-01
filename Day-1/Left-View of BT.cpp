
void solve(Node* root,vector<int> &out,int lvl)
{

    if(root==NULL)
        return;
  
    if(lvl == out.size())
        out.push_back(root->data);
        
    solve(root->left,out,lvl+1);
    solve(root->right,out,lvl+1);
    
    
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
  
   vector<int>out;
   solve(root,out,0);
   return out;
}
