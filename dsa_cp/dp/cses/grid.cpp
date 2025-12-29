#include<bits/stdc++.h>

using namespace std;


int mod = 1e9+7;
int main() {
	
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin >> grid[i][j];
	}
	
	if(grid[n-1][n-1] == '*') {cout << 0 << endl; return 0;}
	
	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[n-1][n-1] = 1;
	
	for(int i =n-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
			if(grid[i][j] == '*') continue;
			int ans = 0;
			if(i < n-1 ) {
				ans = (ans + dp[i+1][j])%mod;
			}
			if(j < n-1) {
				ans = (ans + dp[i][j+1])%mod;

			}
			if(ans) dp[i][j] = ans;

		}
	}
	cout << dp[0][0] << endl;
	
}
