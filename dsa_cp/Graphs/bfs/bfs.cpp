#include<bits/stdc++.h>

using namespace std;



void bfs(vector<vector<int>> edges, int n, int s) {
	
	vector<int> distance(n, INT_MAX);
	
	distance[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int k = q.front();
		q.pop();
		for(auto v: edges[k]) {
			
			if(distance[v] > distance[k] + 1) {
			
				distance[v] = distance[k]+1;
				q.push(v);
			}
			
		}
	}


}
int main() {


}
