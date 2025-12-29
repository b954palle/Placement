#include<bits/stdc++.h>

using namespace std;


bool dfs(int node, vector<vector<int>> &adj, vector<int> &color) {
	
	for(auto e: adj[node]) {
		if(color[e] == -1) {
			color[e] = 1-color[node];
			if(!dfs(e, adj, color)) return false;
		}
		else if(color[e] == color[node]) return false;
	}
	
	return true;
}

bool bipartite(vector<vector<int>> &adj) {
	
	int n = adj.size();
	vector<int> color(n, -1);
	
	for(int i=0; i<n; i++) {
		if(color[i] == -1) {
			color[i] = 1;
			if(!dfs(i, adj, color)) return false;
		}
	}
	return true;
}
int main() {
	
	
}

