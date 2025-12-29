#include<bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cin >> n;

	int mod = 1e9 + 7;

	
	int sum = (n*(n+1))/2;
	if(sum%2 ==1){
		cout << 0 << endl;
		return 0;
	}
	sum /= 2;
	sum -= n;
	vector<int> dp(sum+1, 0);
	dp[0] = 1;
	for(int i=1; i<n; i++) {
		for(int w=sum; w>=(i); w--) {
			(dp[w] += dp[w-i])%=mod;
		}
	}
	cout << dp[sum] << endl;
}
