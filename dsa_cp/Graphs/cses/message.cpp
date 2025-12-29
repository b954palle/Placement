#include<bits/stdc++.h>

using namespace std;

void bfs(int n, vector<vector<int>> &adj) {
	
	vector<int> parent(n+1, -1);
	
	queue<int> q;
	parent[1] = 1;
	q.push(1);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto u: adj[v]) {
			if(parent[u] == -1) {
				parent[u] = v;
				q.push(u);
			}
		}
	}
	
	if(parent[n] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	int curr = n;
	vector<int> path;
	while(true) {
		
		path.push_back(curr);
		if(curr == parent[curr]) break;
		curr = parent[curr];
	}
	
	reverse(path.begin(), path.end());
	
	cout << path.size() << endl;
	for(auto p: path) cout << p << " ";
	cout << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	
	for(int i=0; i<m; i++) {
		int v,u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	bfs(n, adj);
}
