#include<bits/stdc++.h>

using namespace std;


vector<int> bfsOfGraph(int n, vector<vector<int>> &adj) {
	
	vector<int> visited(n, 0);
	
	
	
	queue<int> q;
	q.push(0);
	
	visited[0] = 1; // it is important to do this, do not forget this. 
	
	vector<int> bfs;
	
	while(!q.empty()) {
		
		int node = q.front();
		q.pop();
		bfs.push_back(node);
		
		for(auto id: adj[node]) {
		
			if(visited[id]) continue;
			
			visited[id] = 1;
			q.push(id);
		}

	}
	
	return bfs;
}

