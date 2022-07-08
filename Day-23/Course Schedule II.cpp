class Solution {
public:
    
//     void solve(int node,unordered_map<int,bool> &visited,vector<vector<int>> adj,stack<int> &st)
//     {
//         visited[node] = true;
        
//         for(auto it:adj[node])
//         {
//             if(!visited[it])
//                 solve(it,visited,adj,st);
//         }
        
//         st.push(node);
//     }
    vector<int> findOrder(int n, vector<vector<int>> &edge) {
        
        unordered_map<int,bool>visited;
        stack<int>st;
        vector<vector<int>>adj(n);
                vector<int>indegree(n);

        for(auto it:edge)
        {
            // for(auto i:it)
//             int u = edge[i][0];
//             int v = edge[i][1];
            
//             adj[u].push_back(v);
//             adj[v].push_back(u);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
//         for(int i =0 ;i<n-1;i++)
//         {
//             if(!visited[i])
//                 solve(i,visited,adj,st);
//         }
        
        // for(auto i:adj)
        //     for(auto j:i.second)
        //         indegree[j]++;
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        
        vector<int>output;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            output.push_back(front);
            
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }                
        }
        if(output.size()==n)
            return output;
        return {};
    }
};
