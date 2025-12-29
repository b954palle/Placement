#include<bits/stdc++.h>

using namespace std;


int main() {

	int n, x;
	
	cin >> n >> x;
	
	vector<int> coins(n);
	
	for(int i=0; i<n; i++) cin >> coins[i];
	
	vector<int> dp(x+1, INT_MAX);
	
	dp[0] = 0;
	
	for(int bal = 1; bal <= x; bal++) {
		
		for(int i=0; i<n; i++) {
		
			if(coins[i] > bal || dp[bal - coins[i]] == INT_MAX) continue;
			
			dp[bal] = min(dp[bal], dp[bal-coins[i]]+1); 
		}
	}

	
	cout << (dp[x] != INT_MAX ? dp[x] : -1) << endl;
	
}
