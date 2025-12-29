#include<bits/stdc++.h>

using namespace std;


// Kruskals algorithm -- O(N^2 + M logM)


void kruskal(int n, vector<vector<int>> &edges) {
	
	sort(edges.begin(), edges.end());
	
	vector<int> tree_id(n);
	
	for(int i=0; i<n; i++) tree_id[i] = i;
	
	
	int cost = 0;
	vector<vector<int>> result;
	
	for(auto &e: edges) {
		
		if(tree_id[e[1]] == tree_id[e[2]]) continue;
		
		cost += e[0];
		
		result.push_back(e);
		
		for(int i=0; i<n; i++) {
			if(tree_id[i] == tree_id[e[2]]) {
				tree_id[i] = tree_id[e[1]];
			}
		}
	}
	
	cout << cost << endl;
	
	for(auto r: result) {
		cout << r[1] << " " << r[2] << " " << r[0] << endl;
	}
}

int main(){

	vector<vector<int>> edges;
	
	int n;
	cin >> n;
	int m;
	cin >> m;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}
	
	kruskal(n, edges);
}
