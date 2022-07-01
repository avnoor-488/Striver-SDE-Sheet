class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>out;
        if(root==NULL)
        return out;
        
        
        queue<pair<Node *,int>>q;
        map<int,int>mp; //hd,tree->data
        
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node *,int>pp = q.front();
            q.pop();
            Node *frontNode = pp.first;
            int hd = pp.second;
             
            //if one val is present for one hd then do nothing;
            
            if(mp.find(hd)==mp.end())
                mp[hd] = frontNode->data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left,hd-1));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right,hd+1));
        }
        
        for(auto it:mp)
            out.push_back(it.second);
            
        return out;
    }

};
