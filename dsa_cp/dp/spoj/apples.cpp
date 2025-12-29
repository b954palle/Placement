#include<bits/stdc++.h>

using namespace std;


void solve(int n, int k, vector<int>&prices) {
	
	
	vector<vector<int>> dp(k+1, vector<int>(n+1, INT_MAX));
	
	dp[0][0] = 0;
	
	for(int i=1; i<=k; i++) {
		if(prices[i] == -1) continue;
		
		for(int w = 0; w<=k; w++) {
			for(int p = 0; p<=n; p++) { 
				int curr = 0;
				for(int j=1; j+p<=n; j++) {
					curr += prices[i];
					if(w+i*j > k) break;
					if(dp[w][p] != INT_MAX)dp[w+i*j][j+p] = min(dp[w+i*j][j+p], dp[w][p]+curr);
				}
			}
		}
			
	}
	
	int ans = INT_MAX;
	for(int i=1; i<=n; i++) {
		ans = min(ans, dp[k][i]);
	}
	
	cout << (ans != INT_MAX ? ans : -1) << endl;

}
int main() {
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> prices(k+1, 0);
		for(int i=1; i<=k; i++) cin >> prices[i];
		solve(n, k, prices);
	}
}
