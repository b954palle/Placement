#include<bits/stdc++.h>

using namespace std;


void bellmanford(int n, vector<vector<int>> &edges) {
	
	
	int start=1;
	vector<bool> visited(n+1, false);
	for(; start<=n; start++) {
	
	if(visited[start]) continue;
	vector<long long> dist(n+1, LONG_MAX);
	
	dist[start] = 0;
	
	visited[start] = true;
	
	for(int i=0; i<n; i++) {
		for(auto e: edges) {
			if(visited[e[0]]) {
				dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
				visited[e[1]] = true;
			} 
		}
	}
	
	bool f = true;
	
	vector<int> parent(n+1, -1);
	
	for(int i=0; i<n; i++) {
		for(auto e: edges) {
			if(visited[e[0]] && dist[e[1]] > dist[e[0]] + e[2]) {
				dist[e[1]] = dist[e[0]] + e[2];
				parent[e[1]] = e[0];
				f = false;
			} 
		}
	}
	
	if(!f) {
		
		cout << "YES" << endl;
		for(int i=1; i<=n; i++) {
			if(parent[i] != -1) {
				stack<int> ans;
				unordered_set<int> st;
				int curr = i;
				while(st.find(curr) == st.end()) {
					st.insert(curr);
					ans.push(curr);
					curr = parent[curr];
				}
				
				cout << curr << " ";
				
				while(ans.top() != curr) {
					cout << ans.top() << " ";
					ans.pop();
				}
				cout << curr << endl;
				return;
			}
		}
		

	}
	}
	
	cout << "NO" << endl;
	
	
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> edges;
	
	bool found = false;
	
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
		if(c < 0) found = true;
	}
	
	
	if(!found) {
		cout << "NO" << endl;
		return 0;
	}
	

	

		
	bellmanford(n, edges);
	

}


