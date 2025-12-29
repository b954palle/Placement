#include<bits/stdc++.h>

using namespace std;


int main()  {
	int n, x;
	cin >> n >> x;
	int mod = 1e9 +7;
	vector<int> coins(n);
	for(int i=0; i<n; i++) cin >> coins[i];
	
	vector<int> dp(x+1, 0);
	
	dp[0]= 1;
	for(int i=0; i<n; i++) {
		for(int bal = 1; bal <= x; bal++) {
			if(bal - coins[i] >= 0 ) {
				dp[bal] = (1LL*dp[bal]+dp[bal-coins[i]])%mod;
				
			}
		}
	}
	cout << dp[x] << endl;
}
