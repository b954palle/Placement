#include<bits/stdc++.h>

using namespace std;


vector<long long> dijkstras(vector<vector<pair<int, int>>> &adj) {

	int n = adj.size();
	
	vector<long long> dist(n, LONG_MAX);
	
	priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	
	pq.push({0, 1});
	
	dist[1] = 0;
	
	while(!pq.empty()) {
		pair<long long, long long> node = pq.top();
		
		pq.pop();
		
		if(dist[node.second] != node.first) continue;
		
		for(auto &n: adj[node.second]) {
			
			if(dist[n.first] > node.first +  n.second) {

				dist[n.first] = node.first +  n.second;
				pq.push({dist[n.first], n.first});
			}
		}
	}
	
	return dist;
}

int main() {

	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> adj(n+1);
	for(int i=0; i<m; i++) {
		
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		
	}
	
	vector<long long> dist = dijkstras(adj);
	
	for(int i=1; i<=n; i++) cout << dist[i] << " ";
	
	cout << endl;
}
