#include<bits/stdc++.h>

using namespace std;


void bfs(vector<vector<int>>&adj) {
	
	int n = adj.size();
	vector<int> partition(n, 0);
	
	
	for(int node = 1; node <n; node++){
		
		if(partition[node] != 0) continue;
		queue<int> q;
		q.push(node);
		
		partition[node] = 1;
		int curr = 2;
		while(!q.empty()) {
		
			int sz = q.size();
			
			for(int i=0; i<sz; i++) {
				int v = q.front();
				q.pop();
				
				for(auto u: adj[v]) {
					if(partition[u] == 0) {
						partition[u] = curr;
						q.push(u);
					}
					else if(partition[u] == partition[v]) {
						cout << "IMPOSSIBLE" << endl;
						return;
					}
				}
			}
			
			if(curr == 2) curr = 1;
			else curr = 2;
			
		}
	}
	
	for(int i=1; i<n; i++) cout << partition[i] << " ";
	cout << endl;
	
}


int main() {
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	
	for(int i=0; i<m; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	bfs(adj);
	
}
