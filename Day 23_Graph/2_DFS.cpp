// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfsHelper(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
    {
        dfs.push_back(node);
        vis[node] = 1;
        
        for(int ngbr : adj[node])
        {
            if(!vis[ngbr])
                dfsHelper(ngbr, adj, vis, dfs);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfs;
        vector<int> vis(V, 0);
        
        dfsHelper(0, adj, vis, dfs);
        
        return dfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1