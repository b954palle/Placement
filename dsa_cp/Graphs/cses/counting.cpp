#include<bits/stdc++.h>

using namespace std;


void dfs(int i, int j, int n, int m, vector<vector<char>> &matrix, vector<vector<bool>> &visited) {
	
	if(i>=n || j>=m || i<0 || j<0) return;
	
	if(matrix[i][j] == '#' || visited[i][j]) return;
	
	visited[i][j] = true;
	
	dfs(i+1, j, n, m, matrix, visited);
	dfs(i, j+1, n, m, matrix, visited);
	dfs(i-1, j, n, m, matrix, visited);
	dfs(i, j-1, n, m, matrix, visited);
}

int main() {

	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> matrix(n, vector<char>(m));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char c;
			cin >> c;
			matrix[i][j] = c;
		}
	}
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	int connected = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j] == '.' && !visited[i][j]) {
				connected++;
				dfs(i, j, n, m, matrix, visited);
			}
		}
	}
	cout << connected << endl;
	
	
}
