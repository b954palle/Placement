#include<bits/stdc++.h>

using namespace std;


int main() {
	
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
	
	dp[n][m] = 0;
	for(int i=0; i<n; i++) {
		dp[i][m] = n-i; 
	}
	for(int i=0; i<m; i++) {
		dp[n][i] = m-i;	
	}

	for(int i=n-1; i>=0; i--) {
		for(int j=m-1; j>=0; j--) {
			int ans = INT_MAX;
			if(s1[i] == s2[j]) {
				ans = min(ans, dp[i+1][j+1]);
			}
			else {
				ans = min(ans, 1+dp[i+1][j+1]);
			}
			ans = min(ans, 1+dp[i][j+1]);
			ans = min(ans, 1+dp[i+1][j]);	
			dp[i][j] = ans;	
		}
	}
	
	cout << dp[0][0] << endl;
}
