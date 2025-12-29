#include<bits/stdc++.h>

using namespace std;

// this works for only undirected. 


bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>>& adj) {
        
        vis[node] = 1;
        for(auto e: adj[node]) {
            if(!vis[e]) {
                if(dfs(e, node, vis, adj)) return true;
            }
            else if(parent != e) return true;
        }
        
        return false;
}

bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        
        return false;

}


int main() {
	
    vector<vector<int>> adj = {{1}, {2}, {0}};
    cout << isCycle(adj) << endl;
	
}
