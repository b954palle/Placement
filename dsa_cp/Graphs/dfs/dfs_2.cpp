#include<bits/stdc++.h>

using namespace std;


void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
	
	visited[node] = 1;
	
	for(auto it: adj[node]) {
		if(!visited[it]) {
			dfs(it, adj, visited);
		}
	}
	
}
