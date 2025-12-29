#include<bits/stdc++.h>

using namespace std;




void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
	
	visited[node] = true;
	
	for(auto a: adj[node]) {
		
		if(visited[a]) continue;
		
		dfs(a, adj, visited);
	}
	
	
}

long long bellmanFord(int n, vector<vector<int>> &edges) {
	
	vector<long long> dist(n+1, LONG_MAX);
	dist[1] = 0;
	
	for(int i=0; i<n; i++) {	
		for(auto e: edges) {
			if(dist[e[0]] != LONG_MAX && dist[e[1]] > dist[e[0]] + e[2]) dist[e[1]] = dist[e[0]] + e[2];
		}
	}
	
	vector<bool> cycle(n+1, false);

	for(auto e: edges) {
		if(dist[e[0]] != LONG_MAX && dist[e[1]] > dist[e[0]] + e[2]) {
			dist[e[1]] = dist[e[0]] + e[2];
			cycle[e[1]] = true;
			if(e[1] == n) return -1;
		}
	}
	
	vector<vector<int>> adj(n+1);
	vector<vector<int>> revadj(n+1);
	
	for(auto e: edges) {
		adj[e[0]].push_back(e[1]);
		revadj[e[1]].push_back(e[0]);
	}
	
	vector<bool> visited(n+1, false);
	
	dfs(1, adj, visited);
	
	vector<bool> visited2(n+1, false);
	
	dfs(n, revadj, visited2);
	
	for(int i=1; i<=n; i++) {
		
		if(visited[i] && visited2[i] && cycle[i]) return -1;
	}
	
	
	return -dist[n];
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> edges;
	for(int i=0; i<m; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		edges.push_back({a, b, -x});
	}
	
	cout << bellmanFord(n, edges) << endl;
	
	
}
