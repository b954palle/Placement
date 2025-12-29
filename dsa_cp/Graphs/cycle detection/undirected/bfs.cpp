#include<bits/stdc++.h>

using namespace std;


bool bfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
            
	queue<pair<int, int>> q;
	q.push({i, -1});
	vis[i] = 1;
            
	while(!q.empty()) {
        	int curr = q.front().first;
                int prev = q.front().second;
                q.pop();
                for(auto e: adj[curr]) {
                    if(!vis[e]) {
                        q.push({e, curr});
                        vis[e] = 1;
                    }
                    else if(e != prev) return true;
                }
	}
            
	return false;
}
    
bool isCycle(vector<vector<int>>& adj) {
        
	int n = adj.size();
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(bfs(i, adj, vis)) return true;
            }
        }
        
        return false;
        
}


int main() {

	
}
