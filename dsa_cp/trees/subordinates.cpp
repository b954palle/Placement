#include<bits/stdc++.h>

using namespace std;


void dfs(int i, vector<vector<int>> &adj, vector<int> &subordinates) {
	
	for(auto e: adj[i]) {
		dfs(e, adj, subordinates);
		subordinates[i] += subordinates[e];
		subordinates[i] += 1;
	}
	
	
}

int main() {
	
	int n;
	cin >> n;
	vector<vector<int>> adj(n+1);
	
	for(int i=2;i<=n;i++) {
		int t;
		cin >> t;
		adj[t].push_back(i);
	}
	
	vector<int> subordinates(n+1, 0);
	
	dfs(1, adj, subordinates);
	
	for(int i=1; i<=n; i++) {
		cout << subordinates[i] << " ";
	}
	
	cout << endl;
	
}
