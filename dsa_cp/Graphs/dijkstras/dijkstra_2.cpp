#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;


/*

Dijkstra Algorithm 

Single shortest paths problem in directed or undirected weighted graph. 

*/

void dijkstra(int s, vector<vector<pair<int, int>>> &adj) {
	
	int n = adj.size();
	vector<int> d(n, INT_MAX);
	
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	
	while(!pq.empty()) {
		
		int v = pq.top().second;
		int dv = pq.top().first;
		pq.pop();
		if(dv != d[v]) continue;
		
		for(auto edge: adj[v]) {
			
			int u = edge.first;
			int len = edge.second;
			
			if(d[v] + len < d[u]) {
				d[u] = d[v] + len;
				pq.push({d[u], u});
			}
		}
	}
	
	for(int i=0; i<n; i++) cout << d[i] << endl;
}

int main() {
	
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	
	for(int i=0; i<m; i++) {
		
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});

	}
	
	dijkstra(0, adj);

}
