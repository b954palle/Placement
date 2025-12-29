#include<bits/stdc++.h>

using namespace std;


void bfs(int starti, int startj, int endi, int endj, vector<vector<char>> &matrix) {

	queue<pair<int, int>> q;
	
	int n = matrix.size();
	int m = matrix[0].size();
	
	vector<vector<char>> parent(n, vector<char>(m, '#'));
	
	
	q.push({starti, startj});
	parent[starti][startj] = '.';
	while(!q.empty()) {
		
		auto p = q.front();
		q.pop();
		int curri = p.first;
		int currj = p.second;

		if(curri + 1 <n ) {
			if(matrix[curri+1][currj] != '#' && parent[curri+1][currj] == '#') {
				parent[curri+1][currj] = 'D';
				if(curri+1 == endi && currj == endj) break;
				q.push({curri+1, currj});
			}
		}
		if(curri - 1 >= 0 ) {
			if(matrix[curri-1][currj] != '#' && parent[curri-1][currj] == '#') {
				parent[curri-1][currj] = 'U';
				if(curri-1 == endi && currj == endj) break;
				q.push({curri-1, currj});
			}
		}
		if(currj + 1 < m) {
			if(matrix[curri][currj+1] != '#' && parent[curri][currj+1] == '#') {
				parent[curri][currj+1] = 'R';
				if(curri == endi && currj+1 == endj) break;
				q.push({curri, currj+1});
			}	
		}
		if(currj - 1 >=0 ) {
			if(matrix[curri][currj-1] != '#' && parent[curri][currj-1] == '#') {
				parent[curri][currj-1] = 'L';
				if(curri == endi && currj-1 == endj) break;
				q.push({curri, currj-1});
			}	
		}
	}
	
	string ans = "";
	if(parent[endi][endj] == '#') {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	int curri = endi;
	int currj = endj;
	while(true) {
		if(curri == starti && currj == startj) break;
		ans += parent[curri][currj];
		if(parent[curri][currj] == 'D') curri--;
		else if(parent[curri][currj] == 'U') curri++;
		else if(parent[curri][currj] == 'L') currj++;
		else currj--;
		
	}
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	cout << ans << endl;
	
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> matrix(n, vector<char>(m));
	
	int starti=-1;
	int startj=-1;
	int endi = -1;
	int endj = -1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char c;
			cin >> c;
			matrix[i][j] = c;
			if(c == 'A') {
				starti = i;
				startj = j;
			}
			else if(c == 'B') {
				endi = i;
				endj = j;
			}
		}
	}
	
	
	bfs(starti, startj, endi, endj, matrix);
	
}
