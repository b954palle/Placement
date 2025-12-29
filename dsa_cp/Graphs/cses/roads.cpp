#include<bits/stdc++.h>

using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<int> &visited, int conncomponents) {
	
	visited[i] = conncomponents;
	
	for(auto u: adj[i]) {
		if(visited[u] == 0) dfs(u, adj, visited, conncomponents);
	}
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n+1);
	
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> visited(n+1, 0);
	int conncomponents = 0;
	vector<pair<int, int>> buildEdges;
	int prev = -1;
	for(int i=1; i<=n; i++) {
		if(visited[i] == 0) {
			conncomponents++;
			if(prev != -1) {
				buildEdges.push_back({prev, i});
			}
			dfs(i, adj, visited, conncomponents);
			prev = i;
		}
	}
	
	cout << conncomponents-1 << endl;
	
	for(auto p: buildEdges) {
		cout << p.first << " " << p.second << endl;
	}
}
