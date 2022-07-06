#include<bits/stdc++.h>

bool solve(unordered_map<int,vector<int>> &adjList,unordered_map<int,bool> &visited, int srcNode )
{
    queue<int>q;
    unordered_map<int,int>parent;
    q.push(srcNode);
    parent[srcNode] = -1;
    visited[srcNode]= true;
    
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        for(auto it:adjList[frontNode])
        {
            if(visited[it]==1 && it != parent[frontNode])
                return true;
            else if(!visited[it]) 
            {
                q.push(it);
                visited[it] = true;
                parent[it] = frontNode;
            }              
        }
    }
    
    return 0;
} 


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,vector<int>>adjList;
    unordered_map<int,bool>visited;
    
    for(int i = 0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    for(int  i = 0;i<n;i++)
    {
        if(!visited[i])
       {     
            bool ans = solve(adjList,visited,i);
            if(ans)
                return "Yes";
        }
    }
    
    return "No";
}
