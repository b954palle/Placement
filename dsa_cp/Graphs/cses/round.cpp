#include<bits/stdc++.h>

using namespace std;



void print(int node, int u, vector<int> &parent) {
	
	vector<int> ans;
	
	int curr = node;
	
	while(curr != u) {
		ans.push_back(curr);
		curr = parent[curr];
	}
	
	cout << ans.size()+2 << endl;
	
	cout << u << " ";
	reverse(ans.begin(), ans.end());
	
	for(auto &a: ans) cout << a << " ";
	
	cout << u << endl;
}

bool dfs(int node, vector<vector<int>>& adj, vector<int> &parent) {
	
	
	for(auto &u: adj[node]) {
		if(parent[u] == -1) {
			parent[u] = node;
			if(dfs(u, adj, parent)) return true;
		}
		else if(parent[node] != u){
			
			
			print(node, u, parent);
			
			return true;
			
		}
	}
	
	return false;
	
	
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n+1);
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> parent(n+1, -1);

	for(int i=1; i<=n; i++) {
		if(parent[i] == -1) {
			parent[i] = i;
			if(dfs(i,adj, parent)) {
				return 0;
			}
		}
	}
	
	cout <<"IMPOSSIBLE" << endl;
	
	
}
