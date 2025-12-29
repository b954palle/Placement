#include<bits/stdc++.h>

using namespace std;


bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        
        vis[node] = 1;
        
        for(auto e: adj[node]) {
            if(!vis[e]) {
                if(dfs(e, adj, vis)) return true;
            }
            else if(vis[e] == 1) return true;
        }
        
        vis[node] = 2;
        
        return false;
}
    
bool isCyclic(vector<vector<int>> adj) {

        int n = adj.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis)) return true;
            }
        }
        
        return false;
}

int main() {
	vector<vector<int>> adj = {{1}, {2}, {}};
	cout << isCyclic(adj) << endl;
}

