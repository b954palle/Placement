#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int i=0; i<n; i++) cin >> coins[i];
	
	
	int currsum = 0;
	for(int i=0; i<n; i++) currsum += coins[i];
	vector<bool> dp(currsum+1, false);
	
	dp[0] = true;
	for(int i=0; i<n; i++) {
		
		int k = coins[i];
		for(int j = currsum-k; j>=0; j--) {
			if(dp[j]) dp[j+k] = true;
		}
	}
	int ans = 0;
	for(int i=1;i<=currsum; i++) {
		if(dp[i]) ans++;
	}
	cout << ans << endl;
	for(int i=1;i<=currsum; i++) {
		if(dp[i]) cout << i << " ";
	}
	cout << endl;
}
