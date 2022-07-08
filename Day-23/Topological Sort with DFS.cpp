// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void solve(int node,vector<int>adj[],unordered_map<int,bool> &visited,stack<int> &st)
	{
	    visited[node] = true;
	    
	    for(auto it:adj[node])
	        if(!visited[it])
	            solve(it,adj,visited,st);
	    st.push(node);
	}
	
	
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    
	    unordered_map<int,bool>visited;
	    stack<int>st;
	    
	    for(int i =0 ;i<n;i++)
	    {
	        if(!visited[i])
	            solve(i,adj,visited,st);
	    }
	    
	    
	    vector<int >output;
	    
	    while(!st.empty())
	    {
	        output.push_back(st.top());
	        st.pop();
	        
	    }
	    
	    return output;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
