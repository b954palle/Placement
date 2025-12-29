#include<bits/stdc++.h>

using namespace std;


int ans = 0;
vector<vector<char>> matrix(8, vector<char>(8));
vector<int> col(8, 0);
vector<int> diag1(15, 0);
vector<int> diag2(15, 0);

void helper(int r) {
	
	if(r == 8) {ans++; return;}
	
	for(int i=0; i<8; i++) {
		if(matrix[r][i] == '.' && col[i]==0 && diag1[i+r] == 0 && diag2[r-i+7] == 0) {
			col[i] = 1; diag1[i+r] = 1; diag2[r-i+7] = 1;
			helper(r+1);
			col[i] = 0; diag1[i+r] = 0; diag2[r-i+7] = 0;
		}
	}	
}

int main() {
	
	
	
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			cin >> matrix[i][j];
		}
	}
	
	helper(0);
	
	cout << ans << endl;

}
