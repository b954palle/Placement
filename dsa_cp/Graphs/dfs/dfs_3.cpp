#include<bits/stdc++.h>

using namespace std;


class Dfs {
	
	vector<vector<int>> adj;
	vector<int> color;
	vector<int> time_in, time_out;
	int dfs_timer = 0;
	
	DFS(vector<vector<int>> & Adj) {
		adj = Adj;
		int n = adj.size();
		
		color.resize(n, 0);
		time_in.resize(n);
		time_out.resize(n);
		
	}
	
	void dfs(int v) {
		
		time_in[v] = dfs_timer++;
		color[v] = 1;
		for(int u : adj[v]) {
			if(color[u] == 0) dfs(u);	
		}
		color[v] = 2;
		time_out[v] = dfs_timer++;
	}
};

int main() {

}
