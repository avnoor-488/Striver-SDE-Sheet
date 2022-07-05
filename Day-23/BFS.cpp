  
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        
        unordered_map<int,bool>visited;
        queue<int>q;
        vector<int>ans;
        
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty())
        {
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();
            
            for(auto it:adj[frontNode])
            {
                if(!visited[it])
                {
                    visited[it] =1;
                    q.push(it);
                }
            }
        }
   
        return ans;
    }
