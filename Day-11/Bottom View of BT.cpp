class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>out;
        if(root==NULL)
            return out;
            
        queue<pair<Node*, int>>q;
        map<int,int>mp;
        
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            pair<Node* ,int>pp = q.front();
            q.pop();
            Node *frontNode = pp.first;
            int hd = pp.second;
            
            mp[hd] = frontNode->data;
            
            if(frontNode->left!=NULL)
                q.push(make_pair(frontNode->left,hd-1));
            
            if(frontNode->right!=NULL)
                q.push(make_pair(frontNode->right,hd+1));
        }
        
        for(auto it:mp)
            out.push_back(it.second);
            
        return out;
    }
};
