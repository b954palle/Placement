#include<bits/stdc++.h>

using namespace std;




bool check(int i, int j, int n, int m) {
	
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	
	return true;
}


void print(int sourcei, int sourcej, int i, int j, vector<vector<pair<int, int>>> &p) {
	
	int curri = i;
	int currj = j;
	
	string ans = "";
	
	while(curri != sourcei || currj != sourcej) {
		
		int dir = p[curri][currj].second;
		if(dir == 0)  {
			ans += "D";
			curri--;
		}
		else if(dir == 1) {
			ans += "U";
			curri++;
		}
		else if(dir == 2) {
			ans += "R";
			currj--;
		}
		else {
			ans += "L";
			currj++;
			
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans << endl;
}

vector<vector<pair<int, int>>> bfs(queue<pair<int, int>> q, vector<vector<char>> adj) {
	
	
	int n = adj.size();
	int m = adj[0].size();
	
	vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {INT_MAX, -1}));
	
	int dist = 0;
	while(!q.empty()) {
		
		int sz = q.size();
		dist++;
		for(int i=0; i<sz; i++) {
			
			pair<int, int> node = q.front();
			q.pop();
			for(int d=0; d<4; d++) {
				int x1 = node.first + dir[d].first;
				int y1 = node.second + dir[d].second;
				if(!check(x1, y1, n, m)) continue;
				
				if(adj[x1][y1] == '.' && parent[x1][y1].first == INT_MAX) {
					parent[x1][y1] = {dist, d};
					q.push({x1, y1});
				}
				
			}
		}
	}
	
	return parent;
	
	
}
int main() {

	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> adj(n, vector<char>(m));
	
	
	queue<pair<int, int>> source;
	queue<pair<int, int>> monsters;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char c;
			cin >> c;
			adj[i][j] = c;
			if(c == 'A') source.push(make_pair(i, j));
			else if(c == 'M') monsters.push({i, j});
		}
	}
	
	
	int sourcei = source.front().first;
	int sourcej = source.front().second;
	
	if(sourcei == 0 || sourcei == n-1 || sourcej == 0 || sourcej == m-1) {
		
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	vector<vector<pair<int, int>>> p1 = bfs(source, adj);
	vector<vector<pair<int, int>>> p2 = bfs(monsters, adj);
	
	

	
	
	for(int j=0; j<m; j++) {
	
		if(p1[0][j].first < p2[0][j].first) { 
			cout << "YES" << endl;

			cout << p1[0][j].first << endl;
			print(sourcei, sourcej, 0, j, p1);
			return 0;
		}

		
		if(p1[n-1][j].first < p2[n-1][j].first) {
			cout << "YES" << endl;
			cout << p1[n-1][j].first << endl;
			print(sourcei, sourcej, n-1, j, p1);
			return 0;
		}
	}
	
	for(int i=0; i<n; i++) {
		if(p1[i][0].first < p2[i][0].first) { 
			cout << "YES" << endl;
			cout << p1[i][0].first << endl;
			print(sourcei, sourcej, i, 0, p1);
			return 0;
		}

		
		if(p1[i][m-1].first < p2[i][m-1].first) {
			cout << "YES" << endl;
			cout << p1[i][m-1].first << endl;
			print(sourcei, sourcej, i, m-1, p1);
			return 0;
		}
	}
	
	cout << "NO" << endl;
	
	return 0;

}
