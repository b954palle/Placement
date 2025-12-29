#include<bits/stdc++.h>

using namespace std;




int main() {
	
	

	int n, x;
	cin >> n >> x;
	int mod = 1e9+7;
	vector<int> coins(n);
	
	for(int i=0; i<n; i++) cin >> coins[i];
	

	vector<long long> dp(x+1);
	dp[0] = 1;
	
	for(int bal = 1; bal <=x; bal++) {
		dp[bal] = 0;
		for(int i=0; i<n; i++) {
			if(coins[i] - bal > 0) continue;
			dp[bal] += dp[bal-coins[i]];
			dp[bal] %= mod;
		}

	}
	
	cout << dp[x] << endl;
	
}
