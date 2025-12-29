#include<bits/stdc++.h>

using namespace std;


vector<int> bfs(int n, vector<vector<int>> & adj) {
	
	vector<int> side(n, -1);
	bool bipartite = true;
	for(int i=0; i<n; i++) {
		
		if(side[i] == -1) {
			
			queue<int> q;
			q.push(i);
			
			while(!q.empty()) {
				
				int v = q.front();
				q.pop();
				for(auto u: adj[v]) {
					
					if(side[u] == -1) {	
						side[u] = 1-side[v];
						q.push(u);
					}
					else {
						if(side[u] == side[v]) {
							
							bipartite = false;
							break;
						}
					}
				}
				if(!bipartite) break;
			}
		}
		
		if(!bipartite) break;
	}
	
	cout << (bipartite == true ? "true" : "false") << endl;
	
	return side;
}
int main(){

	vector<vector<int>> adj = {{1, 3}, {2, 0}, {3, 1}, {0, 2}};
	
	bfs(4, adj);
	
	return 0;
}
