    
    void solve(int start,vector<int> &visited,vector<int>adj[],vector<int> &ans)
    {
        if(!visited[start])
        {
            ans.push_back(start);
            visited[start] = 1;
            for(auto it:adj[start])
            {
                solve(it,visited,adj,ans);
            }
        }
    }
                
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>visited(V,0);
        vector<int> ans;
        
        solve(0,visited,adj,ans);
        
        return ans;       
        
    }
};
