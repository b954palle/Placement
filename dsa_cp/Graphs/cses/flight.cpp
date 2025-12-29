#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> adj(n+1);
	
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	
	vector<long long> dist1(n+1, LONG_MAX);
	vector<long long> dist2(n+1, LONG_MAX);
	
	priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
	
	pq.push({0, 1, 0});
	dist1[1] = 0;
	
	while(!pq.empty()) {
		vector<long long> p = pq.top();
		pq.pop();
		
		if(p[2] == 0 && dist1[p[1]] != p[0]) continue;
		if(p[2] == 1 && dist2[p[1]] != p[0]) continue;
		
		int node = p[1];
		long long currdist = p[0];
		
		for(auto e: adj[node]) {
			
			if(p[2] == 0) {
				if(dist1[e.first] > e.second + currdist) {
					dist1[e.first] = e.second + currdist;
					pq.push({dist1[e.first], e.first, 0});
				}
				
				if(dist2[e.first] > e.second/2 + currdist) {
					dist2[e.first] = currdist + (e.second)/2;
					pq.push({dist2[e.first], e.first, 1});
				}
			} 
			else {
				if(dist2[e.first] > e.second + currdist) {
					dist2[e.first] = currdist + (e.second);
					pq.push({dist2[e.first], e.first, 1});
				}
			}
			
		}
		
	}
	
	cout << dist2[n] << endl;
}
