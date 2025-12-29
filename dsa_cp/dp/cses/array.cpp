#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n, m;
	cin >> n >> m;
	
	int mod = 1e9 + 7;
	
	vector<int> arr(n);
	
	for(int i=0; i<n; i++) cin >> arr[i];
	
	vector<vector<int>> dp(n, vector<int>(m+2, 0));
	
	if(arr[0] == 0) {
		for(int i=1; i<=m; i++) {
			dp[0][i] = 1;
		}
	}
	else {
		dp[0][arr[0]] = 1;
	}
	
	for(int i=1; i<n; i++) {
		
		int v = arr[i];
		if(arr[i] == 0) {
			for(int j=1; j<=m; j++) {
				dp[i][j] = ((dp[i-1][j] + dp[i-1][j-1])%mod + dp[i-1][j+1])%mod;
			}
		}
		else {
			dp[i][v] = ((dp[i-1][v-1] + dp[i-1][v])%mod + dp[i-1][v+1])%mod;
		}
	}
	

	int ans = 0;
	for(int j=1; j<=m; j++) (ans += dp[n-1][j])%= mod;
	cout << ans << endl;

}
