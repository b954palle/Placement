#include<bits/stdc++.h>

using namespace std;



vector<vector<int>> floydwarshall(vector<vector<pair<int, int>>> &adj) {

	int n = adj.size();
	
	vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
	
	for(int i=1; i<n; i++) cost[i][i] = 0;
	
	for(int i=1; i<n; i++) {
		for(auto p: adj[i]) {
			cost[i][p.first] = p.second;
		}
	}
	
	for(int via=1; via < n; via++) {
		
		for(int i=1; i<n; i++) {
			
			for(int j=1; j<n; j++) {
				
				if(cost[i][via] != INT_MAX && cost[via][j] != INT_MAX) {
					
					cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
					
				}
				
			}
		}
	}
	
	return cost;
}

vector<int> dijkstras(int i, vector<vector<pair<int, int>>> &adj)  {
	
	int n = adj.size();
	
	vector<int> cost(n, INT_MAX);
	
	cost[i] = 0;
	
	

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, i});
		
	while(!pq.empty()) {
			
			auto k = pq.top();
			pq.pop();
			
			if(k.first != cost[k.second]) continue;
			
			int v = k.second;
			
			for(auto u: adj[v]){
				
				if(k.first + u.second < cost[u.first]) {
					cost[u.first] = k.first + u.second;
					pq.push({cost[u.first] , u.first});
				}
			}
	}
		
	return cost;
	
}


int main() {
	
	int s;
	cin >> s;
	
	ios_base::sync_with_stdio(false);
    	cin.tie(0);
        cout.tie(0);

	
	while(s--) {
		
		int n;
		cin >> n;
		unordered_map<string, int> cityindices;
		vector<vector<pair<int, int>>> adj(n+1);
		for(int i=1; i<=n; i++) {
			string s;
			cin >> s;
			cityindices[s] = i;
			int m;
			cin >> m;
			for(int j=0; j<m; j++) {
				int v, cost;
				cin >> v >> cost;
				adj[i].push_back({v, cost});	
			}
		}
		
		
		
		int r;
		cin >> r;
		for(int i=0; i<r; i++) {
			string c1, c2;
			cin >> c1 >> c2;
			int i1 = cityindices[c1];
			int i2 = cityindices[c2];
			vector<int> costs = dijkstras(i1, adj);
			cout << costs[i2] << endl;
		}
		
	}
}
